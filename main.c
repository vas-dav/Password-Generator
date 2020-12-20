
#include <stdio.h>
#include <stdlib.h>



int main () 
{

    int passcode_l, funct;
    char nums_pass [150];
    char platform [100];
    const char source_all []= "1234567890qwertyuiopasdfghjklzxcvbnm#@QWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_nums []= "1234567890";
    const char source_letter []= "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_letter_nums []= "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    


    



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
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]);
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_letter[rand()%54];
        }
        printf("%s\n", nums_pass);
        break;
    }
    case 2:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]);     
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_nums[rand()%10];
        }
        printf("%s\n", nums_pass);
        break;
    }
    case 3:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]); 
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_letter_nums[rand()%64];
        }
        printf("%s\n", nums_pass);
        break;
    }
    case 4:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]);
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        printf("\nYour password is: ");
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_all[rand()%66];
        }
        printf("%s\n", nums_pass);
        break;
    }
    default:
    {
      printf("Your input is wrong");
      
    }
  }
  FILE*typer;
  if((typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords.txt", "r")) == NULL)
  {
    printf("File is not created or program failed to open it.\n");
  } else
  {
    typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords.txt", "a+");
    printf("File is found.\n");
    fprintf(typer, "\n%s - %s", platform, nums_pass);
    printf("This password is saved in your passwords.txt file.\n");
  }
  
  fclose(typer);


   return(0);
} 