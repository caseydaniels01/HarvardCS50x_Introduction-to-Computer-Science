// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 26;
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_num = hash(word);
    node *cursor = table[hash_num];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // return toupper(word[0]) - 'A';
    unsigned long count = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        count += tolower(word[i]);
    }

    return count % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(dict, "%s", buffer) != EOF)
    {
        node *dict_entry = malloc(sizeof(node));

        if (dict_entry == NULL)
        {
            fclose(dict);
            return false;
        }

        strcpy(dict_entry->word, buffer);
        int hash_num = hash(dict_entry->word);
        dict_entry->next = table[hash_num];
        table[hash_num] = dict_entry;
        word_count++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *existing = table[i];
        while (existing)
        {
            node *temp_table = existing;
            existing = existing->next;
            free(temp_table);
        }

        if (i == N - 1 && existing == NULL)
        {
            return true;
        }
    }
    return false;
}
