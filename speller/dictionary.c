// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int word_count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *locator = table[hash_value];
    while(locator != NULL)
    {
        if (strcasecmp(locator->word, word) == 0)
        {
            return true;
        }
        else
        {
            locator = locator->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *d_file = fopen(dictionary, "r");
    if (d_file == NULL)
    {
        printf("Couldn't open dictionary");
        return false;
    }

    // Read each word in the file
    // Add each word to the hash table
    char buffer[45];
    while(fscanf(d_file, "%s", buffer) != EOF)
    {
        node *n_word = malloc(sizeof(node));
        int hash_value = hash(buffer);
        strcpy( n_word->word, buffer);
        n_word->next = table[hash_value];
        table[hash_value] = n_word;
        word_count++;
    }
    // Close the dictionary file
    fclose(d_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        node *locator = table[i];
        while(locator != NULL)
        {
            locator = locator->next;
            free(temp);
            temp = locator;
        }
    }
    return true;
}
