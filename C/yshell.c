#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char cmd[] = "";
	char a[7] = "start ";
		printf("Welcome to YShell!");
		system("title YShell");
		system("color 1f");
		while(cmd != "quit"){
			char cmd[] = "";
			char a[7] = "start ";
			system("cls");
			system("tree /f");
			printf("\n> ");
			gets(cmd);
			strcat(a, cmd);
			system(a);
		}
		system("pause");
    return 0;
}
