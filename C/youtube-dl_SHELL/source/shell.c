#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
  char cmd[] = "youtube-dl ";
  char lnk[255];
  system("title youtube-dl SHELL");
  printf("Type or paste link here: ");
  gets(lnk);
  system("cls");
  strcat(cmd, lnk);
  system(cmd);
  puts("\nCompleted.");
  system("pause > nul");
  return 0;
}
