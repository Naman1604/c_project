#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int board[4][4];
int line_dir[4];
int column_dir[4];


void emptyPosition(int * a,int *b){
	int filled=1;
	while(filled){
		*a=rand()%4;
		*b=rand()%4;
		if(board[*a][*b]==0)filled=0;
	}

}
void newGame(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			board[i][j]=0;

		}
	}
	int a=0,b=0;
	emptyPosition(&a,&b);
	board[a][b]=2;

}

void moveApply(int direction){
	

}

void print(){
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(board[i][j])printf("%d ",board[i][j]);
			else printf(". ");
		}
		printf("\n");
	}
	printf(" enter the character to give command as follows :- \n  new game: n  \n  quit the game: q \n move upwards: w \n move downwords: s \n move left: a \n move right: d \n");
}

int main(){
	char instruction[128];
	instruction['s']=0;
	instruction['d']=1;
	instruction['w']=2;
	instruction['a']=3;
	
	char command;
	bool flag=0;
	while(true){
		//system("clear");
		print();
		//scanf("%c",&command);
		command=getchar();
		if(command=='n'){
			newGame();
			flag=1;
			}
		else if(command=='q')break;
		else if(flag==1 ){	
				int currentDir=instruction[command];
				moveApply(currentDir);
			}
	}
	
	return 0;
}
