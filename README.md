# ⚽ Football Quiz

<p align="center">
  <img src="assets/banner.png" alt="Football Quiz Banner" width="800">
</p>

A feature-rich football quiz game developed in **C** for Windows. Test your football knowledge across multiple difficulty levels with timed questions, background music, sound effects, colorful console UI, and a leaderboard system.

---

# ✨ Features

- ⚽ 60 Football Questions (20 Easy, 20 Medium, 20 Hard)
- 🎯 Three Difficulty Levels
- ⏱️ Timed Quiz (15s, 30s, 45s, 60s & Custom Time)
- 🔀 Random Question Selection
- 🔄 Randomized Answer Options
- ⏸️ Pause & Resume Feature
- 🎵 Background Music
- 🎶 Alternates between two songs on every launch
- 🔊 Sound Effects for:
  - Correct Answer
  - Wrong Answer
  - Timeout
  - Menu Click
  - Pause/Resume
  - Celebrations
- 🏆 Separate Top 5 Leaderboards for Easy, Medium & Hard
- 📊 Quiz Statistics
  - Correct Answers
  - Wrong Answers
  - Accuracy
  - Final Score
- 🎉 Perfect Score Celebration
- 🌈 ANSI Colored Console Interface
- 🔨 One-click Build Script (`build.bat`)

---

# 📸 Screenshots

## Main Menu

![Main Menu](assets/main-menu.png)

---

## Difficulty Selection

![Difficulty](assets/difficulty-menu.png)

---

## Time Selection

![Time Selection](assets/time-selection.png)

---

## Quiz Screen

![Question Screen](assets/question-screen.png)

---

## Pause Screen

![Pause Screen](assets/pause-screen.png)

---

## Leaderboard

![Leaderboard](assets/leaderboard.png)

---

## Quiz Result

![Result](assets/result-screen.png)

---

## Perfect Score

![Perfect Score](assets/perfect-score.png)

---

# 🎮 Controls

| Key | Function |
|------|----------|
| A / B / C / D | Answer Question |
| Space | Pause / Resume Quiz |
| Enter | Continue |

---

# 🛠 Technologies Used

- Language: **C**
- Compiler: **GCC (MinGW)**
- Platform: **Windows**

### Libraries

- windows.h
- mmsystem.h
- conio.h
- stdio.h
- stdlib.h
- string.h
- time.h

---

# 📂 Project Structure

```
Football-Quiz/
│
├── assets/
│   ├── banner.png
│   ├── main-menu.png
│   ├── difficulty-menu.png
│   ├── time-selection.png
│   ├── question-screen.png
│   ├── pause-screen.png
│   ├── leaderboard.png
│   ├── result-screen.png
│   └── perfect-score.png
│
├── data/
│   ├── easy.txt
│   ├── medium.txt
│   ├── hard.txt
│   ├── highscores.txt
│   └── music.dat
│
├── include/
├── sounds/
├── src/
│
├── build.bat
├── footballquiz.exe
├── README.md
└── LICENSE
```

---

# 🚀 How to Build

Simply run

```
build.bat
```

The executable `footballquiz.exe` will be generated automatically.

---

# ▶️ How to Run

Double-click

```
footballquiz.exe
```

or run it from the terminal.

---

# 🏅 Quiz Flow

```
Main Menu
      ↓
Choose Difficulty
      ↓
Choose Time Limit
      ↓
Enter Player Name
      ↓
Play 10 Random Questions
      ↓
View Final Statistics
      ↓
Save High Score
      ↓
Return to Main Menu
```

---

# 📊 Quiz Statistics

After every quiz, the game displays:

- Correct Answers
- Wrong Answers
- Accuracy (%)
- Final Score
- Difficulty
- Time Limit

Players achieving a perfect **10/10** receive a special celebration with exclusive sound effects and a congratulatory message.

---

# 🔮 Future Improvements

- More football questions
- Quiz categories (World Cup, Champions League, Premier League, etc.)
- Lifelines (50:50, Skip, Hint)
- Achievement system
- Player statistics
- Quiz history
- Automatic background music looping
- Cross-platform support

---

# 👨‍💻 About

This project was developed as a first-year Computer Science project to practice:

- Modular Programming
- File Handling
- Structures
- Arrays
- Randomization
- Console UI Design
- Sound Integration using Windows Multimedia API
- ANSI Escape Sequences
- Git & GitHub

---

# 📜 License

This project is released under the **MIT License**.

Feel free to use, modify, and learn from it.

---

## ⭐ If you enjoyed this project, consider giving it a star on GitHub!