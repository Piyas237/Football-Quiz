#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "game.h"
#include "questions.h"
#include "score.h"
#include "color.h"
#include "ui.h"
#include "sound.h"

void swapStr(char a[], char b[])
{
    char t[100];

    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
void shuffleOptions(Question *q)
{
    char op[4][100];
    char pos[4];
    char tmp[100];
    char ch;

    int i, j;

    strcpy(op[0], q->optionA);
    strcpy(op[1], q->optionB);
    strcpy(op[2], q->optionC);
    strcpy(op[3], q->optionD);

    pos[0] = 'A';
    pos[1] = 'B';
    pos[2] = 'C';
    pos[3] = 'D';

    for(i = 3; i > 0; i--)
    {
        j = rand() % (i + 1);

        strcpy(tmp, op[i]);
        strcpy(op[i], op[j]);
        strcpy(op[j], tmp);

        ch = pos[i];
        pos[i] = pos[j];
        pos[j] = ch;
    }

    strcpy(q->optionA, op[0]);
    strcpy(q->optionB, op[1]);
    strcpy(q->optionC, op[2]);
    strcpy(q->optionD, op[3]);

    for(i = 0; i < 4; i++)
    {
        if(pos[i] == q->answer)
        {
            q->answer = 'A' + i;
            break;
        }
    }
}
void showQuestion(Question q[], int r, int no)
{
    char t[30];

    clearScreen();

    sprintf(t, "QUESTION %d", no);

    drawTitle(t);

    printf("\n");

    printf(BOLD "%s\n\n" RESET, q[r].question);

    printf(CYAN "A. " RESET "%s\n", q[r].optionA);
    printf(CYAN "B. " RESET "%s\n", q[r].optionB);
    printf(CYAN "C. " RESET "%s\n", q[r].optionC);
    printf(CYAN "D. " RESET "%s\n", q[r].optionD);

    printf("\nPress A/B/C/D to answer\n");
    printf("Press Space to Pause\n\n");
}
void showCorrectAnswer(Question *q)
{
    switch(q->answer)
    {
        case 'A':
            printf(YELLOW "Correct Answer : A. %s\n" RESET, q->optionA);
            break;

        case 'B':
            printf(YELLOW "Correct Answer : B. %s\n" RESET, q->optionB);
            break;

        case 'C':
            printf(YELLOW "Correct Answer : C. %s\n" RESET, q->optionC);
            break;

        case 'D':
            printf(YELLOW "Correct Answer : D. %s\n" RESET, q->optionD);
            break;
    }
}
void playAnswerSound(char ans, char correct)
{
    if(ans == 'X')
    {
        playTimeout();
    }
    else if(ans == correct)
    {
        playCorrect();
    }
    else
    {
        playWrong();
    }
}
void showResult(Question *q, char ans, int *score)
{
    playAnswerSound(ans, q->answer);

    if(ans == 'X')
    {
        printf(YELLOW "\nTime's Up!\n" RESET);
        showCorrectAnswer(q);
    }
    else if(ans == q->answer)
    {
        printf(GREEN "\nCorrect!\n" RESET);
        (*score)++;
    }
    else
    {
        printf(RED "\nWrong!\n" RESET);
        showCorrectAnswer(q);
    }
}
void startQuiz(char file[], char difficulty[], int timeLimit)
{
    Question q[50];

    int n = loadQuestions(file, q);

   drawTitle("QUIZ SETTINGS");
   printf("\n");

    printf("Difficulty        : %s\n", difficulty);
    printf("Questions         : 10\n");
    printf("Time per Question : %d seconds\n", timeLimit);

    printf("\nPress Enter to Start...");
    getchar();
    getchar();
    PlaySound("sounds\\click.wav",
          NULL,
          SND_FILENAME | SND_ASYNC);

    int used[50] = {0};
    int cnt = 0;
    int score = 0;
    char name[50];

            printf("Enter your name: ");

        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0';

    printf(GREEN "\nWelcome, %s!\n\n" RESET, name);

    while(cnt < 10 && cnt < n)
    {
        int r = rand() % n;

        if(used[r])
            continue;

        used[r] = 1;
        shuffleOptions(&q[r]);

        showQuestion(q, r, cnt + 1);
        char ans = 'X';

for(int t = timeLimit; t >= 1; t--)
{
    printf(YELLOW "\rTime Left: %2d " RESET, t);
    fflush(stdout);

    for(int i = 0; i < 10; i++)
    {
        Sleep(100);

        if(kbhit())
        {
            ans = getch();

            if(ans == ' ')
            {
                PlaySound("sounds\\pause-resume.wav",
                          NULL,
                          SND_FILENAME | SND_ASYNC);

                clearScreen();

                drawTitle("PAUSED");

                printf("\n");
                printf("Difficulty : %s\n", difficulty);
                printf("Question   : %d / 10\n", cnt + 1);
                printf("Time Left  : %d Seconds\n", t);

                printf("\nPress Space to Resume...");

                while(1)
                {
                    if(kbhit())
                    {
                        if(getch() == ' ')
                        {
                            PlaySound("sounds\\pause-resume.wav",
                                      NULL,
                                      SND_FILENAME | SND_ASYNC);
                            break;
                        }
                    }

                    Sleep(100);
                }

                showQuestion(q, r, cnt + 1);

                printf(YELLOW "\rTime Left: %2d " RESET, t);
                fflush(stdout);

                continue;
            }

            ans = toupper(ans);

            if(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D')
            {
                printf("\r                     \r");
                printf("You answered: %c\n", ans);
                goto done;
            }
        }
    }
}

ans = 'X';

done:
        printf("\r                     \r");

        showResult(&q[r], ans, &score);

cnt++;

if(cnt < 10 && cnt < n)
{
    printf(CYAN "\nPress Enter for the next question..." RESET);
getchar();
        PlaySound("sounds\\click.wav",
                NULL,
                SND_FILENAME | SND_ASYNC);
}
    }
    clearScreen();
    int cor = score;
    int wr = 10 - score;
    double acc = score * 100.0 / 10;

    drawTitle("QUIZ OVER");
    printf("\n");

    printf(BOLD "Player          : %s\n" RESET, name);
    printf(BOLD "Difficulty      : %s\n" RESET, difficulty);
    printf(BOLD "Time            : %d Seconds\n\n" RESET, timeLimit);

    printf(BOLD "Correct Answers : %d\n" RESET, cor);
    printf(BOLD "Wrong Answers   : %d\n" RESET, wr);
    printf(BOLD "Accuracy        : %.0f%%\n" RESET, acc);

        printf(GREEN "\nFinal Score     : %d / 10\n" RESET, score);

        printf("\n");

        stopMusic();
                if(score == 10)
        {
            playFanfare();
            playCheering();

            printf(CYAN);
            printf("\n");
            printf("****************************************\n");
            printf("* * * * * * * * * * * * * * * * * * * *\n");
            printf("*                                      *\n");
            printf("*         CONGRATULATIONS!             *\n");
            printf("*                                      *\n");
            printf("* * * * * * * * * * * * * * * * * * * *\n");
            printf("****************************************\n");
            printf(RESET);

            printf(MAGENTA BOLD "\n*** PERFECT SCORE ***\n" RESET);
            printf(GREEN "You are a Football Genius!\n" RESET);
        }
                else if(score >= 8)
            {
            playCelebration();
            playApplause();

                printf(GREEN "[EXCELLENT] Great Job!\n" RESET);
            }
                else if(score >= 6)
            {
                playShortFanfare();
                playShortApplause();

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

            startMusic();      // Restart background music


}

    