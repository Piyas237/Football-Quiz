#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>

#include "sound.h"

static int song = 0;
void startMusic()
{
    FILE *fp;

    mciSendString("stop bgm", NULL, 0, NULL);
    mciSendString("close bgm", NULL, 0, NULL);

    fp = fopen("data/music.dat", "r");

    if(fp == NULL)
    {
        song = 0;
    }
    else
    {
        if(fscanf(fp, "%d", &song) != 1)
            song = 0;

        fclose(fp);
    }

    if(song == 0)
    {
        mciSendString(
            "open \"sounds\\HeroesTonight.wav\" alias bgm",
            NULL,
            0,
            NULL);

        song = 1;
    }
    else
    {
        mciSendString(
            "open \"sounds\\OnOn.wav\" alias bgm",
            NULL,
            0,
            NULL);

        song = 0;
    }

    mciSendString(
        "play bgm",
        NULL,
        0,
        NULL);

    fp = fopen("data/music.dat", "w");

    if(fp != NULL)
    {
        fprintf(fp, "%d", song);
        fclose(fp);
    }
    
}
void stopMusic()
{
    mciSendString(
        "stop bgm",
        NULL,
        0,
        NULL);

    mciSendString(
        "close bgm",
        NULL,
        0,
        NULL);
}

void playCorrect()
{
    PlaySound(
        "sounds\\correct.wav",
        NULL,
        SND_FILENAME | SND_ASYNC);
}

void playWrong()
{
    PlaySound(
        "sounds\\wrong.wav",
        NULL,
        SND_FILENAME | SND_ASYNC);
}

void playTimeout()
{
    PlaySound(
        "sounds\\timeout.wav",
        NULL,
        SND_FILENAME | SND_ASYNC);
}

void playFanfare()
{
    PlaySound(
        "sounds\\fanfare.wav",
        NULL,
        SND_FILENAME | SND_SYNC);
}

void playCelebration()
{
    PlaySound(
        "sounds\\celebration.wav",
        NULL,
        SND_FILENAME | SND_SYNC);
}

void playApplause()
{
    PlaySound(
        "sounds\\applause.wav",
        NULL,
        SND_FILENAME | SND_SYNC);
}

void playCheering()
{
    PlaySound(
        "sounds\\cheering.wav",
        NULL,
        SND_FILENAME | SND_SYNC);
}
void playShortFanfare()
{
    PlaySound(
        "sounds\\short-fanfare.wav",
        NULL,
        SND_FILENAME | SND_SYNC);
}

void playShortApplause()
{
    PlaySound(
        "sounds\\short-applause.wav",
        NULL,
        SND_FILENAME | SND_SYNC);
}