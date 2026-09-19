#include <stdio.h>
#include <string.h>
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

    Score e[100], m[100], h[100];
    Score t;

    int ne = 0;
    int nm = 0;
    int nh = 0;

    fp = fopen("data/highscores.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo high scores found.\n");
        return;
    }

    while(fscanf(fp, "%s %s %d",
                 t.name,
                 t.difficulty,
                 &t.score) == 3)
    {
        if(strcmp(t.difficulty, "Easy") == 0)
            e[ne++] = t;

        else if(strcmp(t.difficulty, "Medium") == 0)
            m[nm++] = t;

        else if(strcmp(t.difficulty, "Hard") == 0)
            h[nh++] = t;
    }

    fclose(fp);

    // Sort Easy
    for(int i = 0; i < ne - 1; i++)
    {
        for(int j = 0; j < ne - i - 1; j++)
        {
            if(e[j].score < e[j + 1].score)
            {
                Score temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    // Sort Medium
    for(int i = 0; i < nm - 1; i++)
    {
        for(int j = 0; j < nm - i - 1; j++)
        {
            if(m[j].score < m[j + 1].score)
            {
                Score temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }

    // Sort Hard
    for(int i = 0; i < nh - 1; i++)
    {
        for(int j = 0; j < nh - i - 1; j++)
        {
            if(h[j].score < h[j + 1].score)
            {
                Score temp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = temp;
            }
        }
    }

    printf("\n=========================================================\n");
    printf("                 FOOTBALL QUIZ LEADERBOARD\n");
    printf("=========================================================\n");

    // Easy
            printf("\n==============================\n");
        printf("            EASY\n");
        printf("==============================\n");
        printf("%-5s %-15s %-8s\n", "Rank", "Player", "Score");
        printf("------------------------------\n");

    int lim = ne;
    if(lim > 5) lim = 5;

    for(int i = 0; i < lim; i++)
    {
        printf("#%-4d %-15s %d/10\n",
               i + 1,
               e[i].name,
               e[i].score);
    }

    // Medium
    
            printf("\n==============================\n");
        printf("           MEDIUM\n");
        printf("==============================\n");
        printf("%-5s %-15s %-8s\n", "Rank", "Player", "Score");
        printf("------------------------------\n");
    lim = nm;
    if(lim > 5) lim = 5;

    for(int i = 0; i < lim; i++)
    {
        printf("#%-4d %-15s %d/10\n",
               i + 1,
               m[i].name,
               m[i].score);
    }

    // Hard
            printf("\n==============================\n");
        printf("            HARD\n");
        printf("==============================\n");
        printf("%-5s %-15s %-8s\n", "Rank", "Player", "Score");
        printf("------------------------------\n");

    lim = nh;
    if(lim > 5) lim = 5;

    for(int i = 0; i < lim; i++)
    {
        printf("#%-4d %-15s %d/10\n",
               i + 1,
               h[i].name,
               h[i].score);
    }

    printf("\n=========================================================\n");
}