#include <cs50.h>
#include <stdio.h>

bool check_sum(long num);

int main(void)
{
    int digits = 0, single_digit = 0, two_digit = 0;
    bool checksum;
    long user_input = get_long("Number: ");
    checksum = check_sum(user_input);
    if (checksum == false)
        return 0;
    while(user_input > 0)
    {
        if (user_input < 10)
        {
            single_digit = user_input;
        }
        if (user_input > 10 && user_input < 100)
        {
            two_digit = user_input;
        }
        user_input /= 10;
        digits ++;
    }
    if ((two_digit == 34 || two_digit == 37) && digits == 15)
    {
        printf("AMEX\n");
        return 0;
    }
    else if ((two_digit == 51 || two_digit == 52 || two_digit == 53 || two_digit == 54 || two_digit == 55) && digits == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if (single_digit == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
        return 0;
    }
    else
        printf("INVALID\n");
    return 0;
}

bool check_sum(long num)
{
    int total = 0, buffer = 0;
    bool var = true;
    while(num > 0)
    {
        if (var == true)
        {
            total += num % 10;
            num /= 10;
            var = false;
        }
        else
        {
            buffer = num % 10;
            buffer *= 2;
            if (buffer >= 10)
            {
                total += buffer % 10;
                total += buffer / 10;
            }
            else
            {
                total += buffer;
            }
            var = true;
            num /= 10;
        }
    }
    if (total % 10 == 0)
        return true;
    printf("INVALID\n");
    return false;
}


// Changed repo name to cs50-problems - LOCAL & BROWSER
// branch 2
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


