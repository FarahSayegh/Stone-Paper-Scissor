# 🎮 Rock-Paper-Scissors (C++ Console Game)

A fun and colorful Rock-Paper-Scissors console game built in C++.
Battle against the computer, enjoy animated color feedback, and track your victories across multiple rounds!

---

## ✨ Features
- 🔢 Play 1 to 10 rounds per session
- 🖥️ Randomized computer moves
- 🧠 Automatic winner detection per round and overall
- 🎨 Console color themes for Win, Lose, and Draw
- 🔄 Replayable without restarting
- 🗘️ Clear and easy-to-follow code structure

---

## 📸 Preview
```
Round[1] begins:

Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors: 1
Player Choice  : Rock
Computer Choice: Scissors
Round Winner Name: Player

----------------------------

[Game Results]

Game Rounds       : 5
Player win times  : 3
Computer win times: 1
Draw times        : 1
Final winner      : Player
```

---

## 🏗️ Project Structure
| Component         | Purpose                                |
|------------------|----------------------------------------|
| `choice` enum     | Defines Rock, Paper, Scissors          |
| `winner` enum     | Defines Player, Computer, Draw         |
| `RoundInfo` struct| Stores round-specific details          |
| `GameInfo` struct | Stores full game summary               |
| Utility functions | Randomization, input reading, game logic |
| UI functions      | Display results, change console theme  |

---

## 📋 Requirements
- **Compiler:** C++11 or later
- **Operating System:** Windows (for `system("cls")` and `system("color")`)
  - On Linux/macOS, adapt screen-clearing/color code manually.

---

## 📌 Notes
- 🎨 Colors work best on Windows terminals.
- 🚀 Easy to extend: add custom rules, score history, or multiplayer mode!

---

## 📄 License
This project is licensed under the MIT License.

