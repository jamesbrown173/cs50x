#include <stdio.h>
#include <cs50.h>

void checksum(long n);
int main(void)
{

  // Get the users input and print the input
  long user_input = get_long("Number : ");
  checksum(user_input);

  return 0;
}

void checksum(long n)
{

  int num_div_10 = n / 10;
  int snd_last_num = num_div_10 % 100000;

  printf("%i\n", snd_last_num);
  
}

  // Calculate the checksum
  
      // Multiply every other digit by 2, 
      // starting with the number’s second-to-last digit, 
      // and then add those products’ digits together.

      // Add the sum to the sum of the digits that weren’t multiplied by 2.

      // If the total’s last digit is 0 
      // (or, put more formally, if the 
      // total modulo 10 is congruent to 0), 
      // the number is valid!

  

    

  // Check for card length and starting digits
  

  // Print AMEX, MASTERCARD, VISA or INVALID


