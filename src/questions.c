#include <stdio.h>
#include <string.h>

#include "questions.h"

int loadQuestions(char filename[], Question q[])
{
    FILE *fp;

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return 0;
    }

    int i = 0;

    while(i < 50 &&
      fscanf(fp,
"%199[^|]|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%c\n",
      q[i].question,
      q[i].optionA,
      q[i].optionB,
      q[i].optionC,
      q[i].optionD,
      &q[i].answer) == 6)
{
    i++;
}

    fclose(fp);

    return i;
}