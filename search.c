#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
  string name;
  string number;
}
person;

int linear_search_int(void);
int linear_search_string(void);
int search_data_structure(void);
int iteration(void);
void draw(int n);

int main(void)
{
  // linear_search_int();
  // linear_search_string();
  // search_data_structure();
  iteration();
 }


// Searching with an iteration

int iteration(void)
{
  int height = get_int("Height: ");
  draw (height);

}

void draw(int n)
  {
  // If nothing to draw
    if (n <= 0)
    {
      return;
    }
    // Print pyramid of height n - 1
    draw(n - 1);

    // Print one more row
    for (int i = 0; i < n; i++)
    {
      printf("#");
    }
    printf("\n");


  }


// Searching with a pre-defined data structure
int search_data_structure()
{
  person people[3]; 

  people[0].name = "churchill";
  people[0].number ="+1-617-486-2343";

  people[1].name = "blair";
  people[1].number = "+1-384-234-1254";

  people[2].name = "cameron";
  people[2].name = "+1-293-232-5232";

  string name = get_string("Name: ");
  for (int i = 0; i < 3; i++)
  {
    if (strcmp(people[i].name, name) == 0)
    {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }
  printf("Not found \n");
  return 1;
}

// Implementation of linear search with strings
int linear_search_string(void)
{
string strings[] = {"bath", "boot", "cheese", "pokemon", "top hat"};
string s = get_string("String: ");
for (int i = 0; i < 6; i++)
  {
    if (strcmp(strings[i], s) == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}



// Implemetation of linear search
int linear_search_int(void)
{
int numbers[] = {20,500,10,5,100,1,50};
int n = get_int("Number: ");
for (int i  = 0; i < 7; i++)
  {
    if (numbers[i] == n)
    {
      printf("Found\n");
      return 0;

    }
  }
  printf("Not found\n");
  return 1; 
}


