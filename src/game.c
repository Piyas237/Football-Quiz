#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

#include "game.h"
#include "questions.h"
#include "score.h"
#include "color.h"

void startQuiz(char file[], char difficulty[], int timeLimit)
{
    Question q[20];

    int n = loadQuestions(file, q);

    printf(CYAN "\n====================================\n");
    printf("         QUIZ SETTINGS\n");
    printf("====================================\n\n" RESET);

    printf("Difficulty        : %s\n", difficulty);
    printf("Questions         : 10\n");
    printf("Time per Question : %d seconds\n", timeLimit);

    printf("\nPress Enter to Start...");
    getchar();
    getchar();

    int used[20] = {0};
    int cnt = 0;
    int score = 0;
    char name[50];

    printf("Enter your name: ");
    scanf("%49s", name);

    Beep(900,100);
    Beep(1100,100);

    printf(GREEN "\nWelcome, %s!\n\n" RESET, name);

    while(cnt < 10 && cnt < n)
    {
        int r = rand() % n;

        if(used[r])
            continue;

        used[r] = 1;

        printf(CYAN "\n====================================\n");
        printf("Question %d\n", cnt + 1);
        printf("====================================\n" RESET);

        printf(BOLD "%s\n\n" RESET, q[r].question);

        printf(CYAN "A. " RESET "%s\n", q[r].optionA);
        printf(CYAN "B. " RESET "%s\n", q[r].optionB);
        printf(CYAN "C. " RESET "%s\n", q[r].optionC);
        printf(CYAN "D. " RESET "%s\n", q[r].optionD);

        char ans = 'X';

        printf("\nPress A/B/C/D before time runs out!\n");

        for(int t = timeLimit; t >= 1; t--)
        {
            printf(YELLOW "\rTime Left: %2d " RESET, t);

            if(t == 5)
                Beep(700,80);
            else if(t == 4)
                Beep(800,80);
            else if(t == 3)
                Beep(900,80);
            else if(t == 2)
                Beep(1000,80);
            else if(t == 1)
                Beep(1200,100);

            fflush(stdout);

            for(int i = 0; i < 10; i++)
            {
                Sleep(100);

                if(kbhit())
                {
                    ans = toupper(getch());

                    if(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D')
                    {
                        printf("\r                     \r");
                        printf("You answered: %c\n", ans);
                        goto done;
                    }
                }
            }
        }

done:

        printf("\r                     \r");

        if(ans == 'X')
        {
            Beep(600,300);

            printf(YELLOW "\nTime's Up!\n" RESET);
            printf(YELLOW "Correct Answer : %c\n" RESET, q[r].answer);
        }
        else if(ans == q[r].answer)
        {
            Beep(1000,150);

            printf(GREEN "\nCorrect!\n" RESET);
            score++;
        }
        else
        {
            Beep(400,300);

            printf(RED "\nWrong!\n" RESET);
            printf(YELLOW "Correct Answer : %c\n" RESET, q[r].answer);
        }

        cnt++;
    }

    int cor = score;
    int wr = 10 - score;
    double acc = score * 100.0 / 10;

    Beep(800,120);
    Beep(600,120);

    printf(CYAN "\n====================================\n");
    printf("           QUIZ OVER\n");
    printf("====================================\n\n" RESET);

    printf(BOLD "Player          : %s\n" RESET, name);
    printf(BOLD "Difficulty      : %s\n" RESET, difficulty);
    printf(BOLD "Time            : %d Seconds\n\n" RESET, timeLimit);

    printf(BOLD "Correct Answers : %d\n" RESET, cor);
    printf(BOLD "Wrong Answers   : %d\n" RESET, wr);
    printf(BOLD "Accuracy        : %.0f%%\n" RESET, acc);

    printf(GREEN "\nFinal Score     : %d / 10\n" RESET, score);

    printf("\n");

    if(score == 10)
    {
        Beep(700,150);
        Beep(900,150);
        Beep(1100,200);
        Beep(1400,400);

        printf(MAGENTA BOLD "*** PERFECT SCORE ***\n" RESET);
        printf(GREEN "You are a Football Genius!\n" RESET);
    }
    else if(score >= 8)
    {
        printf(GREEN "[EXCELLENT] Great Job!\n" RESET);
    }
    else if(score >= 6)
    {
        printf(CYAN "[GOOD] Nice Work!\n" RESET);
    }
    else if(score >= 4)
    {
        printf(YELLOW "[KEEP GOING] Keep Practicing!\n" RESET);
    }
    else
    {
        printf(RED "[TRY AGAIN] Better Luck Next Time!\n" RESET);
    }

    saveScore(name, difficulty, score);

    printf("\nPress Enter to return to the main menu...");
    getchar();
    getchar();
}