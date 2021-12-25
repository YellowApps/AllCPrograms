#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char cmd[] = "glash.d\\";
  char input[255];

  while(1){
    strcpy(cmd, "");
    system("type glash.d\\text\\glash.txt");
    gets(input);
    system("cls");
    strcat(cmd, input);
    system(cmd);
  }
}
