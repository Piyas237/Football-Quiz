# ⚽ Football Quiz

A feature-rich football quiz game written in **C**, featuring multiple difficulty levels, customizable timers, colored console UI, sound effects, leaderboards, and file-based score management.

---

## 📸 Preview

> *(Screenshots will be added here.)*

- Main Menu
- Difficulty Selection
- Quiz Settings
- Quiz Gameplay
- High Score Leaderboard
- Quiz Over Screen

---

## ✨ Features

- ⚽ Football-themed quiz
- 🎯 Three difficulty levels
  - Easy
  - Medium
  - Hard
- ⏱ Custom time per question
  - 15 seconds
  - 30 seconds
  - 45 seconds
  - 60 seconds
  - Custom (5–120 seconds)
- 🎨 Colored console interface
- 🔊 Sound effects
- 🏆 Top 5 leaderboard
- 📊 Quiz statistics
  - Correct Answers
  - Wrong Answers
  - Accuracy
- 💾 High score saving
- 🎲 Randomized questions
- ✅ Input validation
- ⌨ Real-time countdown timer

---

## 📂 Project Structure

```text
Football-Quiz/
│
├── data/
│   ├── easy.txt
│   ├── medium.txt
│   ├── hard.txt
│   └── highscores.txt
│
├── include/
│   ├── color.h
│   ├── game.h
│   ├── questions.h
│   └── score.h
│
├── src/
│   ├── main.c
│   ├── game.c
│   ├── questions.c
│   └── score.c
│
├── footballquiz.exe
├── README.md
├── LICENSE
└── .gitignore
```

---

## 🛠 Built With

- C
- GCC (MinGW)
- Windows API
- ANSI Escape Colors
- Git
- GitHub

---

## 🚀 How to Compile

```bash
gcc -Iinclude src/*.c -o footballquiz.exe
```

---

## ▶ How to Run

```bash
./footballquiz.exe
```

---

## 🎮 How to Play

1. Start the game.
2. Select a difficulty.
3. Choose the time per question.
4. Enter your name.
5. Answer each question before the timer expires.
6. Check your final score and leaderboard ranking.

---

## 🏅 Scoring

| Score | Rating |
|------:|---------|
| 10/10 | Football Genius |
| 8–9 | Excellent |
| 6–7 | Good |
| 4–5 | Keep Practicing |
| 0–3 | Better Luck Next Time |

---

## 📈 Current Features

- Multiple difficulty levels
- Random questions
- Timer with sound effects
- Colored interface
- High score leaderboard
- Accuracy calculation
- Input validation
- Professional project structure

---

## 🚀 Future Expansion Pack (v2.0)

Planned features include:

- 🏅 Achievements
- 🎖 Badges
- ❤️ Lifelines
- 📚 Category Mode
- 📜 Quiz History
- 📊 Player Statistics
- 🎲 Question Shuffle Options
- 🌍 Hundreds of New Football Questions
- 👤 Player Profiles
- 💾 Save & Continue
- 🏆 Seasonal Challenges
- 🎮 More Game Modes

---

## 👨‍💻 Author

**P7S**

Created as a learning project while exploring:

- C Programming
- File Handling
- Modular Programming
- Git
- GitHub
- Windows Console Programming

---

## 📄 License

This project is licensed under the MIT License.