#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "score.h"
#include "game.h"
#include "questions.h"

void startQuiz(char file[], char difficulty[])
{
    Question q[20];

    int n;

    n = loadQuestions(file, q);

    printf("\nStarting 10-question quiz...\n\n");

    int used[20] = {0};

    int cnt = 0;
    int score = 0;
    char name[50];

        printf("Enter your name: ");
        scanf("%49s", name);

        printf("\nWelcome, %s!\n", name);

    while (cnt < 10 && cnt < n)
    {
        int r = rand() % n;

        if (used[r] == 1)
        {
            continue;
        }

        used[r] = 1;

        printf("\n====================================\n");
        printf("Question %d\n", cnt + 1);
        printf("====================================\n");

        printf("%s\n\n", q[r].question);

        printf("A. %s\n", q[r].optionA);
        printf("B. %s\n", q[r].optionB);
        printf("C. %s\n", q[r].optionC);
        printf("D. %s\n", q[r].optionD);

        char ans;

        while (1)
        {
            printf("\nEnter your answer (A/B/C/D): ");
            scanf(" %c", &ans);

            ans = toupper(ans);

            if (ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D')
            {
                break;
            }

            printf("\nInvalid option! Please enter A, B, C or D.\n");
        }
        if(ans == q[r].answer)
        {
            printf("\nCorrect!\n");
            score++;
        }
        else
        {
            printf("\nWrong!\n");
            printf("Correct Answer : %c\n", q[r].answer);
        }
        cnt++;
        }
         printf("\n====================================\n");
            printf("          QUIZ OVER\n");
            printf("====================================\n");

            printf("\nFinal Score : %d / 10\n", score);
            saveScore(name, difficulty, score);
            printf("\nPress Enter to return to the main menu...");
            getchar();
            getchar();
    }