#include <stdio.h>

int add(int a, int b);

int main(void){
  int x, y;

  // Prompt the use for input and store it in x and y
  printf("x: ");
  scanf("%d", &x);

  printf("y: ");
  scanf("%d", &y);
  
  

  int z = add(x,y);
  printf("%d\n", z);

  return 0;
}


int add(int a, int b) {
  return a + b;
}
