#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "game.h"

void showMenu();
void chooseDifficulty();

int main()
{
    srand(time(NULL));

    showMenu();

    return 0;
}

void showMenu()
{
    int ch;

    while (1)
    {
        printf("\n====================================\n");
        printf("         FOOTBALL QUIZ\n");
        printf("====================================\n");
        printf("1. Start Quiz\n");
        printf("2. High Scores\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (ch)
        {
            case 1:
                chooseDifficulty();
                break;
            case 2:
                printf("\nHigh Scores Coming Soon...\n");
                break;

            case 3:
                printf("\nThanks for playing!\n");
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

void chooseDifficulty()
{
    int ch;

    while (1)
    {
        printf("\n====================================\n");
        printf("      SELECT DIFFICULTY\n");
        printf("====================================\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("4. Back\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &ch) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");

            while (getchar() != '\n');

            continue;
        }
        switch (ch)
        {
            case 1:
                printf("\nStarting Easy Quiz...\n");
                startQuiz("data/easy.txt");
                return;

           case 2:
                printf("\nStarting Medium Quiz...\n");
                startQuiz("data/medium.txt");
                return;

            case 3:
                printf("\nStarting Hard Quiz...\n");
                startQuiz("data/hard.txt");
                return;
            case 4:
                return;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}