#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "color.h"
#include "ui.h"

void clearScreen()
{
    system("cls");
}

void drawLine()
{
    printf(CYAN "+======================================+\n" RESET);
}

void drawTitle(char title[])
{
    int len = strlen(title);
    int pad = (38 - len) / 2;
    int i;

    drawLine();

    printf(CYAN "|");

    for(i = 0; i < pad; i++)
        printf(" ");

    printf("%s", title);

    for(i = 0; i < 38 - pad - len; i++)
        printf(" ");

    printf("|\n" RESET);

    drawLine();
}
void pauseScreen()
{
    printf("\nPress Enter to continue...");

    getchar();
    getchar();
}

void loadingScreen(char msg[])
{
    clearScreen();

    printf(CYAN "\n%s" RESET, msg);

    fflush(stdout);

    for(int i = 0; i < 3; i++)
    {
        Sleep(300);

        printf(".");

        fflush(stdout);
    }

    Sleep(300);
}