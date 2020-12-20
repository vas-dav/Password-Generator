
#include <stdio.h>
#include <stdlib.h>


int main () {

    int passcode_l, nums_pass [150];
    const char source []= "1234567890qwertyuiopasdfghjklzxcvbnm#@*QWERTYUIOPASDFGHJKLZXCVBNM";

    FILE*typer;
    if((typer = fopen("/Users/VFilms/Desktop/SavedPasswords/passwords.txt", "r")) == NULL)
    {
      printf("File is not created or program failed to open it.");
    } else
    {
      printf("File is found.\n");
    }
    



    system("echo This program will generate your password randomly and write it in a file");

    printf("\n\n Please, enter the lenght of your passcode: ");
    scanf("%d", &passcode_l);
    printf("\nYour password is: ");
    for(int i = 0; i < passcode_l; i++)
    {
      printf("%c", source[rand()%67]);
    }
    printf("\n");
  



   return(0);
} 