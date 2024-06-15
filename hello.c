#include <stdio.h>

int main(void)
{

    int userNumber;
    char userName[100]; // Declare a character array to store the user name
    printf("What's your name:\n");
    fgets(userName, sizeof(userName), stdin); // Use fgets to get input from the user
    printf("what's your number:\n");
    scanf("%d", &userNumber); // Use fgets to get input number from user
   
    if ( userNumber > 10 ) {

    printf("hello, %s\n", userName);

  }
   
}

