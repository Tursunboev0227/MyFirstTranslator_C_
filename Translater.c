#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct word{
    char eng[30];
    char uzb[30];

}WORD;

void displey(){
    printf("    ENGLISH>>>UZBEK>>>DICTIONARY\n");   
    printf("\t1.|  Add new word     |\n");
    printf("\t2.|  Show all words   |\n");
    printf("\t3.|  Search word      |\n");
    printf("\t4.|  Correct word     |\n");
    printf("\t5.|  Exit             |\n");
    printf("\t------------------------\n");
    printf(">>>> ");

}

void addNewWord(){
    system("cls");
    WORD word;
    char text[120];
    int count=0;

    FILE *fr= fopen("Translater.txt", "r");

    if(fr == NULL){
        printf("Error");
        exit(1);
    }
    printf("Engish: "); scanf(" %[^\n]s", word.eng);
    printf("Uzbek: "); scanf(" %[^\n]s", word.uzb);
   
    while( fscanf(fr,"%s", text) != EOF){
        if(!strcmp(text,word.eng)  ){
            printf("\nAlready exist !!! Please enter another word \n");
             count++;
            break;
        } 
    }              
    fclose(fr);

    FILE *fw = fopen("Translater.txt", "a");

         if(count == 0){
            fprintf(fw,"%s %s\n ", word.eng,word.uzb);
         } count = 0;
        
    fclose(fw);

}

void ShowAllWords(){
    system("cls");
    WORD word;
    FILE *fr =fopen("Translater.txt", "r");

    if(fr == NULL){
        printf("Error");
        exit(1);
    }
    printf("+------------+------------+\n");
    printf("|   ENGLISH  |    UZBEK   |\n");
    printf("+------------+------------+\n");
    while(fscanf(fr,"%s", word.eng) != EOF){
        fscanf(fr,"%s", word.uzb);
        printf("|%10s  | %10s |\n", word.eng, word.uzb);
    } 
    printf("+------------+------------+\n");

    fclose(fr);
}

void SearchWord(){
    system("cls");
    char w[10];

    printf("Enter word ");  scanf("%s", w);

    WORD word;

    FILE *fread =fopen("Translater.txt", "r");

    if(fread == NULL){
        printf("Error");
    }

    while(fscanf(fread,"%s", word.eng) != EOF){
            fscanf(fread,"%s", word.uzb);
        if(!strcmp(word.eng, w)){
            printf("\n%s  %s\n", word.eng, word.uzb);
             break;
        }
        // else{
        // }
        //     printf("Not found \n");
        //     printf("Try again\n");
    } 

    fclose(fread);
}


void CorrectWord(){
    system("cls");

    char wrd[10];

    printf("Enter word for correct: "); scanf("%s", wrd);

    WORD word;
    FILE *read =fopen("Translater.txt", "r+");

        if(read == NULL){
            printf("Error");
            exit(1);
        }

        while(fscanf(read,"%s", word.eng) != EOF){
            char w[10];
            int f=0;

            if(!strcmp(word.eng,wrd)){
            printf("Correct form "); scanf("%s", w);
            f=(strlen(word.eng) - strlen(w));
            
               fseek(read,-strlen(word.eng),1);

               fprintf(read,"%s", w);
               for (int i = 0; i < f; i++)
               {
                 fprintf(read, " ");
               }
               
               break;
            }

        }
    fclose(read);

}



int main(){
    int choise=0;

    while( choise !=5){
    displey();

    scanf("%d", &choise);
        switch(choise){
            case 1:
                addNewWord();
                break;
            case 2:
                ShowAllWords();
                break;
            case 3:
                SearchWord();
                break;
            case 4:
                CorrectWord();
                break;
            case 5:
                break;
            default:{
                printf("Not found\n");
                printf("Please choose a number in display\n");
                break;
            }
        }
    }

    return 0;
}