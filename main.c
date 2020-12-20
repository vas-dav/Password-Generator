
#include <stdio.h>
#include <stdlib.h>


int main () 
{

    int passcode_l, nums_pass [150], funct;
    const char source_all []= "1234567890qwertyuiopasdfghjklzxcvbnm#@*QWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_nums []= "1234567890";
    const char source_letter []= "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_letter_nums []= "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    FILE*typer;
    if((typer = fopen("/Users/VFilms/Desktop/SavedPasswords/passwords.txt", "r")) == NULL)
    {
      printf("File is not created or program failed to open it.");
    } else
    {
      printf("File is found.\n");
    }
    



    system("echo This program will generate your password randomly and write it in a file");


    printf("Please tell the program, which password you want to generate:\n\n");
    printf("1. Password with letters only\n");
    printf("2. Password with numbers only\n");
    printf("3. Password with letters and numbers\n");
    printf("4. Password with symbols, letters and numbers\n\n Enter your choice: ");
    scanf("%d", &funct);


    switch(funct)
  {
    case 1:
    {
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          printf("%c", source_letter[rand()%54]);
        }
        printf("\n");
        break;
    }
    case 2:
    {
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          printf("%c", source_nums[rand()%11]);
        }
        printf("\n");
        break;
    }
    case 3:
    {
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          printf("%c", source_letter_nums[rand()%64]);
        }
        printf("\n");
        break;
    }
    case 4:
    {
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          printf("%c", source_all[rand()%67]);
        }
        printf("\n");
        break;
    }
    default:
    {
      printf("Your input is wrong");
      
    }
  }



   return(0);
} 