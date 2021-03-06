
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

    struct Passcode p1;
    int passcode_l, funct;
    const char source_all []= "1234567890qwertyuiopasdfghjklzxcvbnm#@QWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_nums []= "1234567890";
    const char source_letter []= "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    const char source_letter_nums []= "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    
    printf("\n\n\n=============== Random Password Generator ================\n\n");
    system("echo You are seeing this, if you are using Mac.");
    system("echo This program will generate your password randomly and write it in a file.");

    printf("\nPlease tell the program, which password you want to generate:\n\n");
    printf("[1] Password with letters only\n");
    printf("[2] Password with numbers only\n");
    printf("[3] Password with letters and numbers\n");
    printf("[4] Password with symbols, letters and numbers\n\n Enter your choice: ");
    scanf("%d", &funct);


    switch(funct)
  {
    case 1:
    {
        printf("\nPlease enter the platform, where you will use this password: ");
        scanf("%s", &p1.platform[0]);
        printf("\nPlease enter the username for your platform:  ");
        scanf("%s", &p1.username[0]);
        printf("\nPlease, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        //printf("\nIt's %d\n", passcode_l);
        for(int i = 0; i < passcode_l; i++)
        {
          p1.nums_pass[i] = source_letter[rand()%52];
        }

        break;
    }
    case 2:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &p1.platform[0]);
        printf("\nPlease enter the username for your platform:  ");
        scanf("%s", &p1.username[0]);         
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        //printf("\nIt's %d\n", passcode_l);
        for(int k = 0; k < passcode_l; k++)
        {
          p1.nums_pass[k] = source_nums[rand()%10];
        }

        break;
    }
    case 3:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &p1.platform[0]);
        printf("\nPlease enter the username for your platform:  ");
        scanf("%s", &p1.username[0]);        
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        //printf("\nIt's %d\n", passcode_l);
        for(int j = 0; j < passcode_l; j++)
        {
          p1.nums_pass[j] = source_letter_nums[rand()%61];
        }

        break;
    }
    case 4:
    {
        printf("\n Please enter the platform, where you will use this password: ");
        scanf("%s", &p1.platform[0]);
        printf("\nPlease enter the username for your platform:  ");
        scanf("%s", &p1.username[0]);        
        printf("\n\n Please, enter the lenght of your passcode: ");
        scanf("%d", &passcode_l);
        //printf("\nIt's %d\n", passcode_l);
        for(int m = 0; m < passcode_l; m++)
        {
          p1.nums_pass[m] = source_all[rand()%64];
        }

        break;
    }
    default:
    {
      printf("Your input is wrong");
      
    }
  }

  clipboard(p1.nums_pass);
  printf("Your password is generated: %s \nAnd copied to a clipboard\n", p1.nums_pass);
  
  FILE*typer;
  if((typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords.txt", "r")) == NULL)
  {
    printf("File is not created or program failed to open it.\n");    
  } else
  {
    typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords.txt", "r");
    
    typer = fopen("/Users/VFilms/Desktop/IT/C-code/PasswordGenerator/SavedPasswords/passwords.txt", "a+");
    printf("File is found.\n");
    fprintf(typer, "\n1.%s - 2.%s - 3.%s", p1.nums_pass, p1.platform, p1.username);
    printf("This password is saved in your passwords.txt or passwords2.txt file.\n\n");
  }
  
  fclose(typer);


   return(0);
} 