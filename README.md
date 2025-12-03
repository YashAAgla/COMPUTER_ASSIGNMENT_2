# 🎮 Console Obstacle Dodging Game (C Language)

## 📌 Overview
This is a simple **console-based obstacle dodging game** written in C.  
The player controls a character (`*`) that can move left, center, or right to avoid falling obstacles (`@`).  
The game runs in the terminal using ASCII graphics and keeps track of **score, lives, and high score**.

---

## 🚀 Features
- **Player Movement**: Use the **arrow keys** (← →) to move your character between three lanes.  
- **Obstacles**: Randomly generated obstacles fall from the top of the screen.  
- **Collision Detection**: Lose a life if your character collides with an obstacle.  
- **Score System**: Gain points for successfully dodging obstacles.  
- **Lives System**: Start with 3 lives. Game ends when all lives are lost.  
- **High Score Tracking**: Highest score is saved in `highscore.txt` and displayed during gameplay.  
- **Restart Option**: After game over, you can choose to **play again (Y/N)** without restarting the program manually.  

---

## 🛠️ Modifications Added
Enhancements made to the original code:
- ✅ **Lives system** → Player starts with 3 lives, loses one on collision.  
- ✅ **Score system** → Score increases when obstacles are avoided.  
- ✅ **High score system** → High score is saved to and loaded from `highscore.txt`.  
- ✅ **Restart option** → After game over, player can press `Y` to restart or `N` to quit.  

---

## 📂 Files
- `main.c` → Source code of the game.  
- `highscore.txt` → Stores the highest score achieved across sessions.  

---

## ▶️ How to Run
1. Compile the program using a C compiler (e.g., GCC):
   ```bash
   gcc main.c -o game