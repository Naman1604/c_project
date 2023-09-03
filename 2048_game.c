#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
#include <time.h>

int board[4][4];
int score=0;
void emptyPosition() {
int a=0,b=0;
    int filled = 1;
    while (filled) {
        //srand(time(NULL));
        a = rand() % 4;
        b = rand() % 4;
        if (board[a][b] == 0) {
            filled = 0;
        }
    }
     board[a][b] = 2;
}


void newGame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    //int a = 0, b = 0;
    emptyPosition();
    emptyPosition();
    //board[a][b] = 2;
}

void moveLeft() {
    for (int i = 0; i < 4; i++) {
        int mergeIndex = 0;
        for (int j = 1; j < 4; j++) {
            if (board[i][j] != 0) {
                if (board[i][j] == board[i][mergeIndex]) {
                    board[i][mergeIndex] *= 2;
                    
                    score+=board[i][mergeIndex];
                    
                    board[i][j] = 0;
                    mergeIndex++;
                } else if (board[i][mergeIndex] == 0) {
                    board[i][mergeIndex] = board[i][j];
                    board[i][j] = 0;
                } else {
                    mergeIndex++;
                    board[i][mergeIndex] = board[i][j];
                    if (mergeIndex != j) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

void moveRight() {
    for (int i = 3; i >=0; i--) {
        int mergeIndex = 3;
        for (int j = 2; j >=0; j--) {
            if (board[i][j] != 0) {
                if (board[i][j] == board[i][mergeIndex]) {
                    board[i][mergeIndex] *= 2;
                    
                    score+=board[i][mergeIndex];
                    
                    board[i][j] = 0;
                    mergeIndex--;
                } else if (board[i][mergeIndex] == 0) {
                    board[i][mergeIndex] = board[i][j];
                    board[i][j] = 0;
                } else {
                    mergeIndex--;
                    board[i][mergeIndex] = board[i][j];
                    if (mergeIndex != j) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

void moveUP() {
    for (int j = 0; j < 4; j++) {
        int mergeIndex = 0;
        for (int i = 1; i < 4; i++) {
            if (board[i][j] != 0) {
                if (board[i][j] == board[mergeIndex][j]) {
                    board[mergeIndex][j] *= 2;
                    
                    score+=board[mergeIndex][j];
                    
                    board[i][j] = 0;
                    mergeIndex++;
                } else if (board[mergeIndex][j] == 0) {
                    board[mergeIndex][j] = board[i][j];
                    board[i][j] = 0;
                } else {
                    mergeIndex++;
                   board[mergeIndex][j] = board[i][j];
                    if (mergeIndex != i) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}
void moveDown() {
    for (int j = 3; j >=0; j--) {
        int mergeIndex = 3;
        for (int i = 2; i >=0; i--) {
            if (board[i][j] != 0) {
                if (board[i][j] == board[mergeIndex][j]) {
                    board[mergeIndex][j] *= 2;
                    
                   
                            
                    
                    score+=board[mergeIndex][j];
                    
                    board[i][j] = 0;
                    mergeIndex--;
                } else if (board[mergeIndex][j] == 0) {
                    board[mergeIndex][j] = board[i][j];
                    board[i][j] = 0;
                } else {
                    mergeIndex--;
                   board[mergeIndex][j] = board[i][j];
                    if (mergeIndex != i) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

bool endGame(bool flag){
	if(flag==0){ 
	printf("                    GAME OVER \n \n");
	printf("       YOUR SCORE IS: %d ",score);
	printf("    To play again please restart the game\n");		
	}
	return true;
}
bool hasLost(){
    // Check if there are any empty cells
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                return true; 
            // There is at least one empty cell, game can  continue
            }
        }
    }

    // Check if there are any adjacent tiles with the same value (valid moves)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) {
                return true; // There's at least one valid move, game can continue
            }
        }
    }

    return false; // Player has lost
}

void moveApply(int direction) {
    // Determine the step for row and column iteration based on direction
    if (direction == 3) {
        moveLeft();
    } else if (direction == 1) {
        moveRight();
    } else if (direction == 2) {
       moveUP();
    } else if (direction == 0) {
        moveDown();
    }
    bool f=hasLost();
	endGame(f);
    //
    //int a = 0, b = 0;
    emptyPosition();
    
    //board[a][b] = 2;
    f=hasLost();
    endGame(f);
}




void print() {
	printf("Score : %d \n \n",score);
    
    printf("------------------------------\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("|");
            if (board[i][j] == 0)
                printf("      ");
            else
                printf("%4d  ", board[i][j]);
        }
        printf("|\n");
        printf("------------------------------\n");
    }
    printf("Enter the character to give command as follows:\n");
    printf("New game: n\n");
    printf("Quit the game: q\n");
    printf("Move upwards: w\n");
    printf("Move downwards: s\n");
    printf("Move left: a\n");
    printf("Move right: d\n");
}

int main() {
    char instruction[128];
    instruction['s'] = 0;
    instruction['d'] = 1;
    instruction['w'] = 2;
    instruction['a'] = 3;
    char command;
    bool flag = 0;
    while (true) {
         system("clear");
        print();
        command = getchar();
        if (command == 'n') {
            newGame();
            flag = 1;
        } else if (command == 'q') {
        printf("    GAME OVER! \n    YOUR SCORE IS %d \n",score);
            break;
        } 
        else if (flag == 1) {
            int currentDir = instruction[command];
            moveApply(currentDir);
        }
        int inputChar;
        while ((inputChar = getchar()) != '\n' && inputChar != EOF) {
        }
    }

    return 0;
}

