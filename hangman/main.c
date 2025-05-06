#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_COUNT 200
const char *wordList[WORD_COUNT] = {
    "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
    "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugly", "watermelon",
    "zucchini", "avocado", "blackberry", "blueberry", "cantaloupe", "dragonfruit", "gooseberry", "jackfruit", "kumquat", "lime",
    "melon", "olive", "peach", "pear", "plum", "pomegranate", "prune", "starfruit", "tomato", "xylophone",
    "ant", "bear", "cat", "dog", "elephant", "fox", "giraffe", "hippopotamus", "iguana", "jaguar",
    "kangaroo", "lion", "monkey", "newton", "octopus", "penguin", "quail", "rabbit", "snake", "turtle",
    "urchin", "vulture", "wolf", "kilometer", "pizza", "zebra", "albatross", "buffalo", "chimpanzee", "dolphin",
    "eagle", "flamingo", "gorilla", "hedgehog", "impala", "jellyfish", "koala", "lemur", "anthill", "narwhal",
    "rainforest", "parrot", "cayote", "reindeer", "shark", "toucan", "unicorn", "volleyball", "vampite", "koala",
    "almond", "basil", "cinnamon", "drill", "fennel", "ginger", "hazelnut", "jalapeno", "kelp", "lavender",
    "mint", "nutmeg", "oregano", "pepper", "handbook", "rosemary", "saffron", "rhyme", "vanilla", "wasabi",
    "library", "yarrow", "zest", "acorn", "barley", "cashew", "gluttony", "endive", "flaxseed", "garlic",
    "horseradish", "iceberg", "penguin", "kale", "leek", "mustard", "onion", "pistachio", "radish", "sesame",
    "turnip", "bedsheet", "vinegar", "ocean", "yogurt", "zucchini", "astronaut", "bicycle", "calendar", "diamond",
    "electric", "furnace", "galaxy", "horizon", "internet", "jigsaw", "kitchen", "landscape", "mountain", "notebook",
    "ocean", "puzzle", "quicksand", "rainbow", "sunshine", "telescope", "umbrella", "volcano", "whistle", "xylophone",
    "yacht", "zeppelin", "adventure", "blueprint", "chocolate", "daydream", "exquisite", "friendship", "grandmother", "happiness", "illusion",
    "jubilant", "knowledge", "lighthouse", "moonlight", "nostalgia", "orchestra", "philosophy", "quietude", "resonance", "silhouette",
    "tranquility", "universe", "vibrancy", "wanderlust", "xenophobia", "yearning", "zenith", "butterfly", "champion", "delicate"
};

struct LBInput
{
    char name[100];
    int score;
};

struct LBInput LB[5];

void ascii()
{
    srand(time(NULL)); //Makes Random work
    printf("\nRandom Word: %s\n",wordList[rand() % WORD_COUNT]); // Get random word
    printf("\033[22;34m _    _ \033[0m                                        \n");
    printf("\033[22;34m| |  | |\033[0m                                        \n");
    printf("\033[22;34m| |__| |\033[0m __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("\033[22;34m|  __  |\033[0m/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("\033[22;34m| |  | |\033[0m (_| | | | | (_| | | | | | | (_| | | | |\ \n");
    printf("\033[22;34m|_|  |_|\033[0m\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("\033[22;34m        \033[0m             __/ |                      \n");
    printf("\033[22;34m        \033[0m            |___/                       \n");
}

void header()
{
    ascii();
    printf("\x1b[31m------------------------------------------------\x1b[0m\n");
    printf("1 - Play\n");
    printf("2 - Leaderboard\n");
    printf("3 - History\n");
    printf("4 - addScore test\n");
    printf("0 - Exit\n");
    printf("\x1b[31m------------------------------------------------\x1b[0m\n");
}



void play() {
   char a;
   printf("Not implemented please press enter");
   getchar();
   scanf("%c", &a );
}


void history() {

char a;
   printf("Not implemented please press enter");
   getchar();
   scanf("%c", &a );
}


void leaderboard()
{
    system("cls");
    readLB();
    orderLB();
    writeLB();
    printf("====================\n");
    printf("    Leaderboard\n");
    printf("====================\n");
    FILE *ab;
    ab = fopen("leaderboard.txt","r");
    if(ab)
    {
        fclose(ab);
    }
    else{
        ab = fopen("leaderboard.txt","w");
        fclose(ab);
    }
    FILE *lbb;
    lbb = fopen("leaderboard.txt","r");
    FILE *lb;
    lb = fopen("leaderboard.txt","r");
    char line[100];
    int i = 1;
    fgets(line,100,lb);
    fgets(line,100,lb);
    if(feof(lb))
    {
        FILE *lbw = fopen("leaderboard.txt","w");
        fprintf(lbw,"\nPlayer 1 - 0\nPlayer 2 - 0\nPlayer 3 - 0\nPlayer 4 - 0\nPlayer 5 - 0\n");
        fclose(lbw);
    }
    fclose(lb);
    fgets(line,100,lbb);
    while(fgets(line,100,lbb) &&  i <= 5)
    {
        printf("%d",i);
        printf(". ");
        printf("%s",line);
        i++;
    }
    printf("====================\n");
    printf("Input anything to go back.");
    fclose(lbb);
    char a;
   getchar();
   scanf("%c", &a );
}

void addScore(){
    system("cls");

    FILE *w;
    w = fopen("leaderboard.txt", "a");

    char name[50];
    printf("Input name: "); //Get NAME
    scanf("%s", name);

    int n;
    printf("Input score: "); //Get Score
    scanf("%d", &n);

    fprintf(w, "%s",name);
    fprintf(w," %d\n", n);

    fclose(w);
    char a;
    getchar();
    scanf("%c", &a );
}
void orderLB()
{
    readLB();
    int ok = 1;
    struct LBInput aux;
    while(ok == 1)
    {
        ok = 0;
        for(int j = 0; j < 5; j++)
        {
            if(LB[j].score < LB[j+1].score)
            {
                strcpy(aux.name, LB[j].name);
                aux.score = LB[j].score;
                strcpy(LB[j].name, LB[j+1].name);
                LB[j].score = LB[j+1].score;
                strcpy(LB[j+1].name, aux.name);
                LB[j+1].score = aux.score;
                ok = 1;
            }
        }
    }
}

void readLB()
{
    FILE *r;
    r = fopen("leaderboard.txt", "r");
    char line[100];
    int i;
    int nr;
    fgets(line,55,r);
    for(i = 0 ; i <= 5; i++)
    {
        fgets(line,100,r);
        char *token = strtok(line, " ");
        strcpy(LB[i].name, token);
        token = strtok(NULL, " ");
        nr = atoi(token);
        LB[i].score = nr;
    }
    fclose(r);
}
void writeLB()
{
    FILE *w;
    w = fopen("leaderboard.txt", "w");
    fprintf(w,"\n");
    for(int i = 0; i < 5; i++)
    {
        fprintf(w,"%s %d\n",LB[i].name,LB[i].score);
    }
    fclose(w);
}

void menu(int op)
{
    switch(op)
    {
    case 1:
        play();
        break;
    case 2:
        leaderboard();
        break;
    case 3:
        history();
        break;
    case 4:
        addScore();
        break;
    default:
        printf("EXIT!\n");
    }
}


int main()
{
    int option;

    do{
        system("cls");
        header();
        printf("Enter option: ");
        scanf("%d", &option);
        menu(option);
    } while(option > 0 && option <= 4);

    return 0;
}
