#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    while (1) {     // 🔁 RESTART LOOP START

        int x = 1;
        int step = 0;
        int obstaclePos = rand() % 3;
        int score = 0;
        int lives = 3;

        // Load high score
        int highScore = 0;
        FILE *f = fopen("highscore.txt", "r");
        if (f != NULL) {
            fscanf(f, "%d", &highScore);
            fclose(f);
        }

        // ----------- GAME LOOP ------------
        while (1) {
            if (_kbhit()) {
                int ch = getch();
                if (ch == 224) {
                    ch = getch();
                    if (ch == 75 && x > 0) x--;
                    if (ch == 77 && x < 2) x++;
                }
            }

            system("cls");
            printf("|--- --- ---|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {
                    if (obstaclePos == 0) printf("| @         |\n");
                    else if (obstaclePos == 1) printf("|     @     |\n");
                    else printf("|        @  |\n");
                } else {
                    printf("|           |\n");
                }
            }

            if (x == 0) printf("| *         |\n");
            else if (x == 1) printf("|     *     |\n");
            else printf("|        *  |\n");
             
            printf("Score: %d   Lives: %d   High Score: %d\n", score, lives, highScore);
            if(lives==0){
                break;
            }
            Sleep(140);
            step++;

            // Collision check
            if (step >= 10) {
                if (x == obstaclePos) {
                    lives--;
                    if (lives <= 0) {
                        printf("\nGAME OVER!\n");
                    }
                    printf("\nYou lost a life! Lives left: %d\n", lives);
                    Sleep(500);
                } else {
                    score++;
                }

                step = 0;
                obstaclePos = rand() % 3;
            }
        }
        // ----------- GAME LOOP END -----------

        // Save high score
        if (score > highScore) {
            FILE *fw = fopen("highscore.txt", "w");
            if (fw != NULL) {
                fprintf(fw, "%d", score);
                fclose(fw);
            }
            printf("New High Score!\n");
        }

        printf("Final Score: %d\n", score);
        printf("High Score: %d\n", (score > highScore ? score : highScore));

        // ------------ RESTART OPTION -------------
        printf("\nPlay again? (Y/N): ");
        char again = getch();

        if (again == 'n' || again == 'N') {
            printf("\nThanks for playing!\n");
            break;   // break OUTSIDE restart loop → EXIT PROGRAM
        }
        // If 'Y', loop continues automatically
    }

    return 0;
}
