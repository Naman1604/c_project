#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void newGame(); 
void emptyPosition();
void copy();
bool moveApply(int direction);
void moveLeft();
void moveRight();
void moveUP();
void moveDown();
bool checkAnyDifference();
bool hasWon();
bool hasLost();
bool endGame(bool flag);
void print(bool flag);

int board[4][4];
int copyBoard[4][4];
int score=0;


void newGame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    
    emptyPosition();
    emptyPosition();
    
}

void emptyPosition() {
    // Create an array to store the coordinates of empty cells
    int emptyCells[16][2];
    int emptyCount = 0;

    // Find and store the coordinates of empty cells
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyCells[emptyCount][0] = i;
                emptyCells[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }

    // If there are no empty cells, return (game over)
    if (emptyCount == 0) {
        return;
    }

    // Generate a random index to choose an empty cell
    int randomIndex = rand() % emptyCount;

    // Generate a random value (2 or 4)
    int randomValue = (rand() % 2 + 1) * 2;

    // Place the random value in the chosen empty cell
    board[emptyCells[randomIndex][0]][emptyCells[randomIndex][1]] = randomValue;

}

void copy(){
 	for(int i=0;i<4;i++){
 		for(int j=0;j<4;j++){
 			copyBoard[i][j]=board[i][j];
 		} 
 	}
}

bool moveApply(int direction) {
	
     copy(); //copy the  board grid into copying the another matirx
    
    // Determine the  calling of function based on direction
    if (direction == 3) {
        moveLeft();
    } else if (direction == 1) {
        moveRight();
    } else if (direction == 2) {
       moveUP();
    } else if (direction == 0) {
        moveDown();
    }
    
    //checking copy matrix and original board 
    if(checkAnyDifference())emptyPosition();
    
    //calling endgame function while returning as to when stop the game;
    return endGame(hasLost());
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


bool checkAnyDifference(){
	for(int i=0;i<4;i++){
 		for(int j=0;j<4;j++){
 			if(copyBoard[i][j]!=board[i][j])return true;
 		} 
 	}
 	return false;
}


bool hasWon() {
    // Loop through the board to check if any tile has the value 2048
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 2048) {
                return 1; // Player has won
            }
        }
    }
    return 0; // Player has not won yet
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
    for (int i = 0; i < 4; i++) {
    	for(int j=0;j<4;j++){
        if (( i<3 && board[i][j] == board[i + 1][j] ) || (j<3 && board[i][j] == board[i][j + 1] )) {
                return true;  // There's at least one valid move, game can continue
            }
        }
    }

    return false; // Player has lost
}



bool endGame(bool flag){
	if(flag==0 && !hasWon()){ 
	printf("                    GAME OVER \n \n");
	printf("       YOUR SCORE IS: %d \n ",score);
	printf("    To play again \n    please restart the game\n");
	
	return true;		
	}
	else if(hasWon()){
		printf("                    CONGRATS U HAVE WON!!  :) \n \n");
		printf("       YOUR SCORE IS: %d ",score);
		printf("    To play again \n    please restart the game\n");
		return true;
	}
	return false;
}


void print(bool flag) {
	printf("\n \n                SCORE : %d \n \n",score);
    
    printf(".___________________________.\n");

    for (int i = 0; i < 4; i++) {
    	printf("|      |      |      |      |\n");
        for (int j = 0; j < 4; j++) {
            printf("|");
            if (board[i][j] == 0)
                printf("      ");
            else
                printf("%4d  ", board[i][j]);
        }
        printf("|\n");
        printf("|______|______|______|______|\n");
    }
    if(flag==0){
    	printf("Enter the character to give command as follows:\n");
    printf("New game: n\n");
    printf("Quit the game: q\n");
    printf("Move upwards: w\n");
    printf("Move downwards: s\n");
    printf("Move left: a\n");
    printf("Move right: d\n");
    }
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
        print(flag);
        command = getchar();
        if (command == 'n') {
            newGame();
            flag = 1;
        } else if (command == 'q') {
        printf("    GAME OVER! \n    YOUR SCORE IS %d \n",score);
            break;
        } 
        else if (flag == 1 && (command=='a' || command=='w' || command=='s'  ||command=='d')) {
            int currentDir = instruction[command];
            
            if(moveApply(currentDir))break;;
        }
        int inputChar;
        while ((inputChar = getchar()) != '\n' && inputChar != EOF) {
        }
    }

    return 0;
}

