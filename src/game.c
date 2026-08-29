#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "questions.h"

void startQuiz(char file[])
{
    Question q[20];

    int n;

    n = loadQuestions(file, q);

    printf("\nStarting 10-question quiz...\n\n");

    int used[20] = {0};

    int cnt = 0;

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

        printf("\nEnter your answer (A/B/C/D): ");
        scanf(" %c", &ans);
        if(ans == q[r].answer)
{
    printf("\nCorrect!\n");
}
else
{
    printf("\nWrong!\n");
    printf("Correct Answer : %c\n", q[r].answer);
}
        cnt++;
    }
}