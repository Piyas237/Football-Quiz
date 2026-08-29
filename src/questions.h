#ifndef QUESTIONS_H
#define QUESTIONS_H

typedef struct
{
    char question[200];

    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];

    char answer;

} Question;

int loadQuestions(char filename[], Question q[]);

#endif