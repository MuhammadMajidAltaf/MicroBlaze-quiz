#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "questions.h"

void help(void);

char *inputString(FILE* fp, size_t size);

int main()
{
    char choice, playername[20], adminpassword[] = "show";

    bool admin_questions_set = false;

    int i, j, answer, current, count;

    goto mainhome;

    mainhome:
        system("CLS");
        printf("\n\n\t\t\t\tQUIZ GAME");
        printf("\n\t\t----------------------------------------");
        printf("\n\t\t\t > press A for ADMIN");
        printf("\n\n\t\t\t > press H for HELP");
        printf("\n\n\t\t\t > press S to START THE GAME");
        printf("\n\n\t\t\t > press Q to QUIT");
        printf("\n\t\t----------------------------------------\n\n");

        choice = toupper(getch());

        if (choice == 'H')
            {
                help();
                getch();
                goto mainhome;
            }

        else if (choice == 'Q') exit(1);

        else if (choice == 'A')
            {
                goto adminlogin;
                adminlogin:
                    system("CLS");
                    printf("ENTER ADMIN PASSWORD: "); gets(adminpassword);
                    if (strcmp(adminpassword,"show") == 0) goto admininterface;
                    else goto adminlogin;

                    admininterface:
                        system("CLS");
                        printf("ADMIN INTERFACE");
                        printf("\n\t\t\t > press 1 to add questions");
                        printf("\n\n\t\t\t > press 2 to see current QUALIFICATION ROUND questions");
                        printf("\n\n\t\t\t > press 3 to logout and return to MAIN SCREEN\n");

                        choice = getch();

                        if (choice == '1')
                            {
                                system("CLS");

                                for(i = 0; i < NUMBER_OF_ADMIN_QUESTIONS; i++)
                                    {
                                        printf("\nENTER QUESTION [%d]:\t", i+1); qq[i].question = inputString(stdin, 1);
                                        for (j = 0; j < 4; j++)
                                            {
                                                 printf("\n\tENTER POSSIBLE ANSWER [%d] TO QUESTION [%d]:\t", j+1, i+1); qq[i].answers[j] = inputString(stdin, 1);

                                            }
                                    }
                                printf("\n");
                                for(i = 0; i < NUMBER_OF_ADMIN_QUESTIONS; i++)
                                    {
                                        do
                                            {
                                                printf("\nENTER ORDINAL NUMBER (1 - 4) OF CORRECT ANSWER TO QUESTION [%d]:\t", i+1);
                                                scanf ("%d", &qq[i].correctAnswer);
                                            }
                                        while (qq[i].correctAnswer < 1 || qq[i].correctAnswer > 4);
                                        qq[i].correctAnswerIndex = qq[i].correctAnswer - 1;
                                    }

                                admin_questions_set = true;
                                getch();
                                goto admininterface;
                            }

                        else if (choice == '2')
                            {
                                if (admin_questions_set == false)
                                    {
                                        system("CLS");
                                        printf("QUALIFICATION ROUND questions are not set. \nPress any key to return to ADMIN INTERFACE. ");
                                        getch();
                                        goto admininterface;
                                    }

                                else if (admin_questions_set == true)
                                    {
                                        system("CLS");
                                        for(i = 0; i < NUMBER_OF_ADMIN_QUESTIONS; i++)
                                            {
                                                printf("\nQUESTION [%d]:\t%s", i+1, qq[i].question);
                                                for (j = 0; j < 4; j++)
                                                    {
                                                        printf("\n\tPOSSIBLE ANSWER [%d] TO QUESTION [%d]:\t%s", j+1, i+1, qq[i].answers[j]);
                                                    }
                                                printf("\n\tORDINAL NUMBER (1 - 4) OF CORRECT ANSWER TO QUESTION [%d]:\t%d", i+1, qq[i].correctAnswer);
                                            }
                                        getch();
                                        goto admininterface;
                                    }
                            }

                        else if (choice == '3') goto mainhome;
                        else if (choice != '1' && choice != '2' && choice != '3') goto admininterface;
            }

        else if (choice == 'S')
            {
                if (admin_questions_set == false)
                    {
                        system("CLS");
                        printf("QUALIFICATION ROUND questions are not set. \nPress any key to return to MAIN SCREEN. ");
                        getch();
                        goto mainhome;
                    }

                else if (admin_questions_set == true)
                    {
                        system("CLS");
                        printf("WELCOME TO QUALIFICATION ROUND. \nPress any key to begin. ");
                        getch();
                        goto qualificationround;

                        qualificationround:
                            system("CLS");
                            for(i = 0; i < NUMBER_OF_ADMIN_QUESTIONS; i++)
                                {
                                    printf("\nQUESTION [%d]:\t%s", i+1, qq[i].question);
                                    printf("\n");
                                    for (j = 0; j < 4; j++)
                                        {
                                            printf("\n\t[%d]\t%s", j+1, qq[i].answers[j]);
                                        }
                                    printf("\n");
                                    scanf("\t%d", &answer);

                                    if (answer == qq[i].correctAnswer)
                                        {
                                            printf("\tCorrect!\n");
                                            getch();
                                        }
                                    else
                                        {
                                            printf("\nWrong! The correct answer is %s\n", qq[i].answers[qq[i].correctAnswerIndex]);
                                            printf("Press any key to return to MAIN SCREEN. ");
                                            getch();
                                            goto mainhome;

                                        }

                                }
                            printf("\nCongratulations! You passed the QUALIFICATION ROUND. \nPress any key to continue to MONEY ROUND. ");
                            getch();
                            goto moneyround;
                            moneyround:
                                system("CLS");
                                srand((unsigned)time(NULL));
                                count = 0;
                                for (i = 0; i < NUMBER_OF_DEFINED_QUESTIONS; i++)
                                    {
                                        mq[i].correctAnswerIndex = mq[i].correctAnswer - 1;
                                        mq[i].used = false;
                                    }

                                for (i = 0; i < NUMBER_OF_MONEY_ROUND_QUESTIONS; i++)
                                    {
                                        // Loop over questions until you get a new one

                                        current = rand() % NUMBER_OF_DEFINED_QUESTIONS;
                                        while (mq[current].used == true)
                                            {
                                                current = rand() % NUMBER_OF_DEFINED_QUESTIONS;
                                            }
                                        mq[current].used = true;

                                        printf ("\nQUESTION [%d]: %s\n", i+1, mq[current].question);
                                        for (j = 0; j < 4; j++)
                                            {
                                                printf("\n\t[%d]\t%s", j+1, mq[current].answers[j]);
                                            }
                                        printf("\n");
                                        scanf ("%d", &answer);

                                        if (answer == mq[current].correctAnswer)
                                            {
                                                printf("\nCorrect!\n");
                                                count++;
                                                getch();
                                            }
                                        else
                                            {
                                                printf("\nWrong! The correct answer is %s.\n", mq[current].answers[mq[current].correctAnswerIndex]);
                                                getch();
                                            }
                                    }
                                printf("\nYou answered %d/%d questions correctly and earned $%d.", count, NUMBER_OF_MONEY_ROUND_QUESTIONS, count * QUESTION_MONEY);
                                printf("\nCongratulations!\nPress any key to return to MAIN SCREEN. ");
                                getch();
                                goto mainhome;
                    }
            }
        else if (choice != 'A' && choice != 'H' && choice != 'S' && choice != 'Q') goto mainhome;
 }

void help(void)
{
    system("CLS");
    printf("\n\n\t\t\t\t\t\tHELP");
    printf("\n\t-------------------------------------------------------------------------------------");
    printf("\n\n\t >> There are two rounds in the game, QUALIFICATION ROUND and MONEY ROUND.");
    printf("\n\n\t >> In QUALIFICATION ROUND there are %d questions added by ADMIN.", NUMBER_OF_ADMIN_QUESTIONS);
    printf("\n\t    ADMIN has to add these questions on every start of the program.");
    printf("\n\t    If not, it will not be possible to START THE GAME.");
    printf("\n\t    Player has to answer correctly to all 3 questions in QUALIFICATION ROUND");
    printf("\n\t    to access MONEY ROUND and to get a chance to win money.");
    printf("\n\n\t >> In MONEY ROUND there are %d questions and each question is worth $%d.", NUMBER_OF_MONEY_ROUND_QUESTIONS, QUESTION_MONEY);
    printf("\n\n\t >> Player is given 4 possible answers for every question, but only one is correct.");
    printf("\n\n\t >> Game is over if player answers a question wrong.");
    printf("\n\n\t >> There are no negative markings for wrong answers.");
	printf("\n\n\t**********************************BEST OF LUCK**********************************\n");
}

char *inputString(FILE* fp, size_t size)
{
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
