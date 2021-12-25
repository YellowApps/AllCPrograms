#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int level = 0;
int main(){
		srand(time(NULL));
		system("title no-gui game");
		char game[10][10] = {
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		};
		int player[2] = {0, 0};
		char input = ' ';
		for(int i = 1; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(random(3) == 1){
					game[i][j] = 'X';
				}
			}
		}
		while(input != 'q'){
			system("cls");
			game[player[0]][player[1]] = '@';
			game[9][9] = '>';
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < 10; j++){
					printf("[%c]", game[i][j]);
				}
				printf("\n");
			}
			if(player[0] == 9 && player[1] == 9){
				break;
			}
			//printf("%d, %d\n", player[0], player[1]);
			/*printf("\n> ");
			scanf(" %c", &input);*/
			input = getch();
			switch(input){
				case('w'):
					if(game[player[0]-1][player[1]] != 'X'){
						game[player[0]][player[1]] = ' ';
						player[0]--;
					}
					break;
				case('s'):
				if(game[player[0]+1][player[1]] != 'X'){
					game[player[0]][player[1]] = ' ';
					player[0]++;
				}
				break;
				case('a'):
					if(game[player[0]][player[1]-1] != 'X'){
						game[player[0]][player[1]] = ' ';
						player[1]--;
					}
					break;
				case('d'):
					if(game[player[0]][player[1]+1] != 'X'){
						game[player[0]][player[1]] = ' ';
						player[1]++;
					}
					break;
				case('t'):
					system("cls");
					printf("---TOOLS---\n\n");
					printf("\t[h]elp\n\t[c]lose\n\t[e]xit\n");
					while(input != 'c'){
						input = getch();
						if(input == 'h'){
							system("cls");
							printf("---HELP---\n\n\t[w] = Move Up\n\t[s] = Move Down\n\t[a] = Move left\n\t[d] = Move Right\n\t[t] = Open Tools");
							input = 'c';
							system("pause > NUL");
						}else if(input == 'e'){
							exit(0);
						}
					}
				}
			}
		system("cls");
		printf("Level completed!");
		system("pause > NUL");
		return 0;
}
int random(max){
	return rand()%max;
}
