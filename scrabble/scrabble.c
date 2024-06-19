#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int score_checker(string w);
int main(void){

 // Prompt the user for two words
  string w_1 = get_string("Word 1: ");
  string w_2 = get_string("Word 2: ");


  // Check the score
  int w_1_score = score_checker(w_1);
  int w_2_score = score_checker(w_2);


  // Print the winner
  if (w_1_score > w_2_score)
  {
    printf("Player 1 wins!\n");
  }
  else if (w_2_score > w_1_score)
  {
    printf("Player 2 wins!\n");
  }
  else
 {
  printf("Tie!\n");
  }

   
  

  

}


int score_checker(string w)
{
  

  int score = 0;
  for (int i = 0, len = strlen(w); i < len; i++)
  { 
    char upper_l =  toupper(w[i]);
    if (upper_l == 'A' || upper_l == 'E' || upper_l == 'I' || upper_l == 'L' || upper_l == 'N' || upper_l == 'O' || upper_l == 'R' || upper_l == 'S' || upper_l == 'T' || upper_l == 'U')
    {
      score += 1;
    }
      else if (upper_l == 'B' || upper_l == 'C' || upper_l == 'M' || upper_l == 'P' )
      {
        score += 3;
      }
      else if (upper_l == 'D' || upper_l == 'G')
      {
        score += 2;
      }
       else if (upper_l == 'F' || upper_l == 'V' || upper_l == 'W' || upper_l == 'Y')
      {
        score += 4;
      }
      else if (upper_l == 'J' || upper_l == 'X')
      {
        score += 8;
      }
      else if (upper_l == 'K')
      {
        score += 5;
      }
      else if (upper_l == 'Q' || upper_l == 'Z')
      {
      score += 10;
      }
  }

  return score;

}
