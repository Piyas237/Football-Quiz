#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "color.h"
#include "game.h"
#include "score.h"
#include "ui.h"
#include "sound.h"

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

    startMusic();

    showMenu();

    stopMusic();

    return 0;
}

void showMenu()
{
    int ch;

    while (1)
    {
        clearScreen();
        drawTitle("FOOTBALL QUIZ");
        printf("\n");
        printf("\n");

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
                PlaySound("sounds\\click.wav",
                        NULL,
                        SND_FILENAME | SND_ASYNC);

                chooseDifficulty();
                break;

                        case 2:
                PlaySound("sounds\\click.wav",
                        NULL,
                        SND_FILENAME | SND_ASYNC);

                showScores();
                pauseScreen();
                break;

                                case 3:
            PlaySound("sounds\\click.wav",
                    NULL,
                    SND_FILENAME | SND_ASYNC);


            printf(CYAN "\nThanks for playing!\n" RESET);
            return;
        }
    }
}

void chooseDifficulty()
{
    int ch;

    while (1)
    {
       printf(CYAN BOLD);
printf("+======================================+\n");
printf("|        SELECT DIFFICULTY             |\n");
printf("+======================================+\n\n");
printf(RESET);
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
    PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);

    int t = chooseTime();

                if (t == 0)
                    break;

                printf(GREEN "\nStarting Easy Quiz...\n" RESET);
                        PlaySound("sounds\\click.wav",
                NULL,
                SND_FILENAME | SND_ASYNC);
                startQuiz("data/easy.txt", "Easy", t);
                return;
            }

            case 2:
{
    PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);

    int t = chooseTime();

                if (t == 0)
                    break;

                printf(GREEN "\nStarting Medium Quiz...\n" RESET);
                          PlaySound("sounds\\click.wav",
                NULL,
                SND_FILENAME | SND_ASYNC);
                startQuiz("data/medium.txt", "Medium", t);
                return;
            }

           case 3:
{
    PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);

    int t = chooseTime();

                if (t == 0)
                    break;

                printf(GREEN "\nStarting Hard Quiz...\n" RESET);
                          PlaySound("sounds\\click.wav",
                NULL,
                SND_FILENAME | SND_ASYNC);
                startQuiz("data/hard.txt", "Hard", t);
                return;
            }

            case 4:
                      PlaySound("sounds\\click.wav",
                NULL,
                SND_FILENAME | SND_ASYNC);
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
        clearScreen();
        printf(CYAN BOLD);
        printf("+======================================+\n");
        printf("|           SELECT TIME                |\n");
        printf("+======================================+\n\n");
        printf(RESET);
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
            PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);
                return 15;

            case 2:
            PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);
                return 30;

            case 3:
            PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);
                return 45;

            case 4:
            PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);
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
                                    PlaySound("sounds\\click.wav",
                        NULL,
                        SND_FILENAME | SND_ASYNC);

                        return t;
                    }

                    printf(YELLOW "\nPlease enter a value between 5 and 120.\n" RESET);
                }

            case 6:
            PlaySound("sounds\\click.wav",
              NULL,
              SND_FILENAME | SND_ASYNC);
                return 0;

            default:
                printf(RED "\nInvalid Choice!\n" RESET);
        }
    }
}