#include <stdio.h>
#include <cs50.h>

// Constant
const int N = 3; 

// Prototype
float average(int length, int array[]);

int main(void)
{
  
  // Get scores
  int scores[N];
  for (int i = 0; i < N; i++)
  {
    scores[i] = get_int("Score %d: ", i);
  }

  // Print average
  printf("Average: %f\n", average(N, scores));

}

float average(int length, int array[])
{
  // Calculate average
  int sum = 0;
  for (int i = 0; 1 < length; i++)
  {
    sum += array[i];
  }
  return sum / (float) length;
}


