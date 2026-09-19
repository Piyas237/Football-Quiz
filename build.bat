@echo off
title Football Quiz Builder

echo.
echo ===============================
echo      FOOTBALL QUIZ BUILDER
echo ===============================
echo.

if exist footballquiz.exe del footballquiz.exe

gcc src/main.c ^
src/game.c ^
src/questions.c ^
src/score.c ^
src/ui.c ^
src/sound.c ^
-Iinclude ^
-Wall ^
-Wextra ^
-o footballquiz.exe ^
-lwinmm

if %errorlevel% neq 0 (
    echo.
    echo Build FAILED!
    pause
    exit /b
)

echo.
echo Build Successful!
echo footballquiz.exe has been created.
pause