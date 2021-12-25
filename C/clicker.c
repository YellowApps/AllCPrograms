#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
	int score = 0;
	printf("Clicker written on C++");
	system("title clicker.exe");
	while(score < 100){
		system("cls");
		printf("Score: ");
		printf("%d", score);
		printf(", ");
		system("pause");
		score++;
	}
	system("cls");
	printf("You won!\n");
	system("pause");
	return 0;
}
