#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
int main(int argv, char *args[]){

		char files[255][255];
		char cmd[50];
		char input = ' ';
		char dn[50];
		char fn[50];
		int vof = 0;
		int cf = 0;
		DIR * dir;
		struct dirent *ent;

		system("color 1f");
		system("chcp 1251 > nul");
		system("title YShell 2.0.1");

		if(args[1] == NULL){
			strcpy(dn, ".");
		}else{
			strcpy(dn, args[1]);
			strcat(dn, "\\");
		}

		while(input != 'q'){
			system("cls");
			printf("%s\n\n", dn);

			if((dir = opendir(dn)) != NULL){
				while((ent = readdir(dir)) != NULL){
					if(vof == cf){
						printf("\t[%s]\n", ent->d_name);
					}else{
						printf("\t%s\n", ent->d_name);
					}
					strcpy(files[vof], ent->d_name);
					vof++;
				}
				closedir(dir);
				vof = 0;
			}else{
				printf("YShell can't open this directory");
			}

			input = getch();

			switch(input){
				case('/'):
					cf++;
					break;
				case('z'):
					cf--;
					break;
				case(' '):
					strcpy(cmd, "start ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					system(cmd);
					break;
				case('y'):
					strcpy(cmd, "yshell2 ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					system(cmd);
					system("color 1f");
					break;
				case('o'):
					strcpy(cmd, "start yshell2 ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					system(cmd);
					break;
				case('e'):
					strcpy(cmd, "notepad ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					system(cmd);
					break;
				case('d'):
					strcpy(cmd, "del ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					system(cmd);
					break;
				case('r'):
					strcpy(fn, "");
					system("cls");
					strcpy(cmd, "ren ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					strcat(cmd, " ");
					printf("Rename File: %s\n", files[cf]);
					printf("Enter new filename: ");
					gets(fn);
					strcat(cmd, fn);
					system(cmd);
					break;
				case('c'):
					strcpy(cmd, "copy ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					strcat(cmd, " ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					strcat(cmd, ".copy");
					system(cmd);
					break;
				case('m'):
					strcpy(fn, "");
					system("cls");
					strcpy(cmd, "move ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					strcat(cmd, " ");
					printf("Move File: %s\n", files[cf]);
					printf("Move File To: ");
					gets(fn);
					strcat(cmd, fn);
					system(cmd);
					break;
				case('n'):
					strcpy(fn, "");
					system("cls");
					strcpy(cmd, "copy con ");
					strcat(cmd, dn);
					printf("New File\nEnter filename: ");
					gets(fn);
					strcat(cmd, fn);
					printf("Enter text (Ctrl+Z) to save and exit: \n");
					system(cmd);
					break;
				case('w'):
					strcpy(cmd, "openWith ");
					strcat(cmd, dn);
					strcat(cmd, files[cf]);
					system(cmd);
					break;
				case('f'):
					strcpy(fn, "");
					system("cls");
					strcpy(cmd, "md ");
					strcat(cmd, dn);
					printf("New Folder\nEnter folder name: ");
					gets(fn);
					strcat(cmd, fn);
					system(cmd);
					break;
				case('l'):
					strcpy(cmd, "start cmd /k \"cd ");
					strcat(cmd, dn);
					strcat(cmd, "\"");
					system(cmd);
					break;
				case('i'):
				system("cls");
					printf("YShell ver. 2.0.1\n\nYShell is a CLI file manager for Windows.\n\n");
					printf("Controls: \n");
					printf("\t<z>\tMove Up\n");
					printf("\t</>\tMove Down\n");
					printf("\t<space>\tOpen selected file in default program\n");
					printf("\t<r>\tRename selected file\n");
					printf("\t<c>\tCopy selected file\n");
					printf("\t<m>\tMove selected file\n");
					printf("\t<d>\tDelete selected file\n");
					printf("\t<e>\tEdit selected file\n");
					printf("\t<w>\tShow dialog \"Open With...\"\n");
					printf("\t<n>\tCreate new file\n");
					printf("\t<o>\tOpen selected folder in new YShell window\n");
					printf("\t<y>\tOpen selected folder\n");
					printf("\t<l>\tOpen Command Line\n");
					printf("\t<i>\tShow this information\n");
					printf("\t<q>\tGo back / Exit YShell\n");
					system("pause > nul");
					break;
			}

		}

		system("cls");
		system("color 0f");
    return 0;
}
