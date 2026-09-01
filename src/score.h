#ifndef SCORE_H
#define SCORE_H

typedef struct
{
    char name[50];
    char difficulty[20];
    int score;

} Score;

void saveScore(char name[], char difficulty[], int score);

void showScores();

#endif