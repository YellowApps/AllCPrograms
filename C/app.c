#include <stdio.h>
#include <stdlib.h>
int main(){
	char path[] = "";
	char text[256];
	FILE * file;
	system("title FileWriter");
	printf("Enter the path: ");
	gets(path);
	system("cls");
	printf("Enter the text (10 lines): \n");
	file = fopen(path, "w");
	if(file == 0){
		printf("Error: incorrect path \"%s\"", path);
	}
	for(int i = 0; i < 10; i++){
		gets(text);
		fprintf(file, "%s\n", text);
	}
	fclose(file);
	system("pause");
	return 0;
}
