#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  if (argc == 3)
  {
    printf("Hello %s %s! \n", argv[1], argv[2]);
    return 0;
  }
  else
  {
    printf("Error: Requires 3 inputs\n");
    return 1;
  }
}
