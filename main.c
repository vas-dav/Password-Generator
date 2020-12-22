
#include "passcode.h"

//Function for copying generated password in a clipboard v1
int clipboard(const char *str) {

    const char proto_cmd[] = "echo '%s' | pbcopy";

    char cmd[strlen(str) + strlen(proto_cmd) - 1]; 
    sprintf(cmd ,proto_cmd, str);

    return system(cmd);
}

int main () 
{

    int passcode_l, funct;
    char nums_pass [150];
    char platform [100];
    const char source_all []= "1234567890qwertyuiopasdfghjklzxcvbnm#@QWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_nums []= "1234567890";
    const char source_letter []= "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_letter_nums []= "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    
    printf("\n\n\n=============== Random Password Generator ================\n\n");
    system("echo You are seeing this, if you are using Mac. This program will generate your password randomly and write it in a file. ");


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
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_letter[rand()%54];
        }

        break;
    }
    case 2:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]);     
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_nums[rand()%10];
        }

        break;
    }
    case 3:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]); 
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_letter_nums[rand()%64];
        }

        break;
    }
    case 4:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &platform[0]);
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        for(int i = 0; i < passcode_l; i++)
        {
          nums_pass[i] = source_all[rand()%66];
        }

        break;
    }
    default:
    {
      printf("Your input is wrong");
      
    }
  }

  clipboard(nums_pass);
  printf("Your password is generated: %s\nAnd copied to a clipboard\n", nums_pass);
  
  FILE*typer;
  if((typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords2.txt", "r")) == NULL)
  {
    printf("File is not created or program failed to open it.\n");
    system("echo Generating a storage file...");
    system("cd SavedPasswords"); 
    system("echo Password - Platform > passwords2.txt");
    system("cd ..");
    if((typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords2.txt", "r")) == NULL)
    {
      printf("File is CREATED.\n");
      fprintf(typer, "\n%s - %s", platform, nums_pass);
    }
    
  } else
  {
    typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords2.txt", "a+");
    printf("File is found.\n");
    fprintf(typer, "\n%s - %s", platform, nums_pass);
    printf("This password is saved in your passwords.txt or passwords2.txt file.\n\n");
  }
  
  fclose(typer);


   return(0);
} 