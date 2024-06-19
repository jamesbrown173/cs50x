#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int count_letters(string w);
int count_words(string t);
int count_sentences(string t);

int main(void)
{
    // Prompt the user for some text
    //string user_text = get_string("Enter text: ");
    string user_text = "This is an example of a sentence."
    // Count the number of letters, words, and sentences in the text
  int num_letters = count_letters(user_text);
  int num_words = count_words(user_text);
  int num_sentences = count_sentences(user_text);


    // Cast into float
    float num_l_f;
    float num_w_f;
    float num_s_f;

    num_l_f = (float) num_letters;
    num_w_f = (float) num_words;
    num_s_f = (float) num_sentences;
    
    // Compute the Coleman-Liau index

  float L = (num_l_f / num_w_f) * 100;
  float S = (num_s_f / num_w_f) * 100;
  
  float index = 0.0588 * L - 0.296 * S - 15.8;
  float index_r = round(index);
  int f_s = (int) index_r;
  if (index_r < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index_r > 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %d\n", f_s); 
  }
}



int count_sentences(string t)
{

  int count = 0;
  int len_t = strlen(t);
  
  for (int i = 0; i < len_t; i++ )
  {
    if (t[i] == '!' || t[i] == '.' || t[i] == '?')
    {
      count++;
    }
  }
  return count;

}


int count_words(string t)
{
  int count = 0;
  int len_t = strlen(t);
  
  for (int i = 0; i < len_t; i++ )
  {
    if (t[i] == ' ')
    {
      count++;
    }
  }
  count += 1;
  return count;

}


int count_letters(string t)
{
  int count = 0;
  int len_t = strlen(t);
  for (int i = 0; i < len_t; i++)
  {
    if (isalpha(t[i]))


    count++;
  }
  return count;
}

