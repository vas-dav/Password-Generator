
#include <stdio.h>
#include <stdlib.h>


int main () {

    int passcode_l, nums_pass [150];
    const char source []= "1234567890qwertyuiopasdfghjklzxcvbnm#@*QWERTYUIOPASDFGHJKLZXCVBNM";


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