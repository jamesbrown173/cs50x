#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int S_U_C = 2015;

bool key_valid(string k);
void encrypter(string t, string u_k);
int main(int argc, string argv[])
{
  
  //Handle command-line argument errors
  if (argc < 2 || argc > 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  // Get Key
  string u_k = argv[1];
  
  // Validate key
  if (!key_valid(u_k))
  {
    printf("Error: Invalid Key\n");
    return 1;
  }
  

  // Get plain text from user
  string user_input = get_string("plaintext: ");

  // Encrypt the users input & print the cypher text
  encrypter(user_input, u_k);

  // Exit the program
  return 0;


}


bool key_valid(string k)
{
  if (strlen(k) < 26)
    return false;

  int buffer = 0;
  for (int i = 0, len = strlen(k); i < len; i++)
  {
    if(!isalpha(k[i]))
      return false;
    else
      buffer += (int) toupper(k[i]);


    for (int b = 0; b < 27; b++)
    {
      if (b != i && (k[i] == toupper(k[b]) || k[i] == tolower(k[b])))
        return false;
    }
  }

  if (buffer != S_U_C)
    return false;

  return true;

}

void encrypter(string t, string u_k)
{
printf("ciphertext: ");
for (int i = 0, len = strlen(t); i < len; i++)
   {
     if (isalpha(t[i]))
    {
      if (isupper(t[i]))
      {
      int l_i = (int) t[i] - 65;
      printf("%c", toupper(u_k[l_i]));
      }
      else
      {
      int l_i = (int) t[i] - 97;
      printf("%c", tolower(u_k[l_i]));
      }
    }
     else
    {
      printf("%c", t[i]);
    }
  }
  printf("\n");
}




