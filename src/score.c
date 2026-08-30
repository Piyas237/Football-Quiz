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

    char name[50];
    char difficulty[20];
    int score;
    fp = fopen("data/highscores.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo high scores found.\n");
        return;
    }

printf("\n=====================================================\n");
printf("                    HIGH SCORES\n");
printf("=====================================================\n\n");

printf("%-15s %-12s %-5s\n", "Player", "Difficulty", "Score");
printf("-----------------------------------------------------\n");

while(fscanf(fp, "%s %s %d", name, difficulty, &score) == 3)
{
    printf("%-15s %-12s %d/10\n", name, difficulty, score);
}

printf("=====================================================\n");

fclose(fp);
}