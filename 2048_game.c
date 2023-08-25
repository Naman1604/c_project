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


void print(){
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(board[i][j])printf("%d ",board[i][j]);
			else printf(". ");
		}
		printf("\n");
	}
}

int main(){
	char instruction[128];
	instruction['s']=0;
	instruction['d']=1;
	instruction['w']=2;
	instruction['a']=3;
	while(true){
		system("clear");
		print();
		char command;
		printf(" enter the character to give command as follows :- \n  new game: n  \n  quit the game: q \n move upwards: w \n move downwords: s \n move left: a \n move right: d \n"); 
		scanf("%c",&command);
		printf("%c",command);
		if(command=='n')newGame();
		else if(command=='q')break;
		//else {
		//	printf("%d",instruction[command]);
			//}
	}
	
	return 0;
}
