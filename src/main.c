#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "color.h"
#include "game.h"
#include "score.h"

void showMenu();
void chooseDifficulty();
int chooseTime();


void enableANSI()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode;

    GetConsoleMode(h, &mode);

    mode |= 0x0004;

    SetConsoleMode(h, mode);
}
int main()
{
    enableANSI();

    srand(time(NULL));

    showMenu();

    return 0;
}

void showMenu()
{
    int ch;

    while (1)
    {
        printf(CYAN BOLD "\n====================================\n");
        printf("         FOOTBALL QUIZ\n");
        printf("====================================\n" RESET);

        printf(GREEN "1." RESET " Start Quiz\n");
        printf(GREEN "2." RESET " High Scores\n");
        printf(GREEN "3." RESET " Exit\n");

        printf(BOLD "\nEnter your choice: " RESET);

        if (scanf("%d", &ch) != 1)
        {
            printf(RED "\nInvalid input! Please enter a number.\n" RESET);

            while (getchar() != '\n');

            continue;
        }

        switch (ch)
        {
            case 1:
                chooseDifficulty();
                break;

            case 2:
                showScores();

                printf("\nPress Enter to return...");
                getchar();
                getchar();

                break;

            case 3:
                printf(CYAN "\nThanks for playing!\n" RESET);
                return;

            default:
                printf(RED "\nInvalid Choice!\n" RESET);
        }
    }
}

void chooseDifficulty()
{
    int ch;

    while (1)
    {
        printf(CYAN BOLD "\n====================================\n");
        printf("      SELECT DIFFICULTY\n");
        printf("====================================\n" RESET);

        printf(GREEN "1." RESET " Easy\n");
        printf(GREEN "2." RESET " Medium\n");
        printf(GREEN "3." RESET " Hard\n");
        printf(GREEN "4." RESET " Back\n");

        printf(BOLD "\nEnter your choice: " RESET);

        if (scanf("%d", &ch) != 1)
        {
            printf(RED "\nInvalid input! Please enter a number.\n" RESET);

            while (getchar() != '\n');

            continue;
        }

        switch (ch)
        {
            case 1:
            {
                int t = chooseTime();

                if (t == 0)
                    break;

                printf(GREEN "\nStarting Easy Quiz...\n" RESET);
                startQuiz("data/easy.txt", "Easy", t);
                return;
            }

            case 2:
            {
                int t = chooseTime();

                if (t == 0)
                    break;

                printf(GREEN "\nStarting Medium Quiz...\n" RESET);
                startQuiz("data/medium.txt", "Medium", t);
                return;
            }

            case 3:
            {
                int t = chooseTime();

                if (t == 0)
                    break;

                printf(GREEN "\nStarting Hard Quiz...\n" RESET);
                startQuiz("data/hard.txt", "Hard", t);
                return;
            }

            case 4:
                return;

            default:
                printf(RED "\nInvalid Choice!\n" RESET);
        }
    }
}

int chooseTime()
{
    int ch, t;

    while (1)
    {
        printf(CYAN BOLD "\n====================================\n");
        printf("         SELECT TIME\n");
        printf("====================================\n" RESET);

        printf(GREEN "1." RESET " 15 Seconds\n");
        printf(GREEN "2." RESET " 30 Seconds\n");
        printf(GREEN "3." RESET " 45 Seconds\n");
        printf(GREEN "4." RESET " 60 Seconds\n");
        printf(GREEN "5." RESET " Custom\n");
        printf(GREEN "6." RESET " Back\n");

        printf(BOLD "\nEnter your choice: " RESET);

        if (scanf("%d", &ch) != 1)
        {
            printf(RED "\nInvalid input! Please enter a number.\n" RESET);

            while (getchar() != '\n');

            continue;
        }

        switch (ch)
        {
            case 1:
                return 15;

            case 2:
                return 30;

            case 3:
                return 45;

            case 4:
                return 60;

            case 5:

                while (1)
                {
                    printf(BOLD "\nEnter time in seconds (5 - 120): " RESET);

                    if (scanf("%d", &t) != 1)
                    {
                        printf(RED "\nInvalid input!\n" RESET);

                        while (getchar() != '\n');

                        continue;
                    }

                    if (t >= 5 && t <= 120)
                    {
                        return t;
                    }

                    printf(YELLOW "\nPlease enter a value between 5 and 120.\n" RESET);
                }

            case 6:
                return 0;

            default:
                printf(RED "\nInvalid Choice!\n" RESET);
        }
    }
}