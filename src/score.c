#include <stdio.h>

#include "score.h"

void saveScore(char name[], char difficulty[], int score)
{
    FILE *fp;

    fp = fopen("data/highscores.txt", "a");

    if(fp == NULL)
    {
        printf("Unable to save score.\n");
        return;
    }

    fprintf(fp, "%s %s %d\n", name, difficulty, score);

    fclose(fp);
}

void showScores()
{
    FILE *fp;

    Score s[100];
    int n = 0;
    fp = fopen("data/highscores.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo high scores found.\n");
        return;
    }
    while(fscanf(fp, "%s %s %d",
             s[n].name,
             s[n].difficulty,
             &s[n].score) == 3)
{
    n++;
}
for(int i = 0; i < n - 1; i++)
{
    for(int j = 0; j < n - i - 1; j++)
    {
        if(s[j].score < s[j + 1].score)
        {
            Score temp = s[j];
            s[j] = s[j + 1];
            s[j + 1] = temp;
        }
    }
}
printf("\n=========================================================\n");
printf("                  TOP 5 HIGH SCORES\n");
printf("=========================================================\n\n");

printf("%-5s %-15s %-12s %-8s\n",
       "Rank",
       "Player",
       "Difficulty",
       "Score");

printf("---------------------------------------------------------\n");

int lim = n;

if(lim > 5)
{
    lim = 5;
}

for(int i = 0; i < lim; i++)
{
    printf("#%-4d %-15s %-12s %d/10\n",
           i + 1,
           s[i].name,
           s[i].difficulty,
           s[i].score);
}

printf("=========================================================\n");

fclose(fp);
}