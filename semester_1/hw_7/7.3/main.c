#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

void checkCurrentWord(char* word)
{
    for (int i = 0; word[i] != '\00'; i++)
    {
        if (word[i] == '.' || word[i] == ',' || word[i] == ':' || word[i] == ';' || word[i] == '!' || word[i] == '?')
        {
            word[i] = '\00';
            return;
        }
    }
}

char* getCurrentWord(FILE* inputFile)
{
    int size = 0;
    char* word = calloc(1, sizeof(char));
    char inputChar = (char) fgetc(inputFile);
    while (inputChar != EOF && inputChar != ' ' && inputChar != '\n')
    {
        word = realloc(word, sizeof(char) * (size + 2));
        word[size] = inputChar;
        size++;
        inputChar = (char) fgetc(inputFile);
    }
    word[size] = '\00';
    return word;
}

int main()
{
    const unsigned int startSizeOfHashtable = 50;
    FILE* text = fopen("text.txt", "r");
    HashTable* hashtable = createHashTable(startSizeOfHashtable);

    while (!feof(text))
    {
        char* word = getCurrentWord(text);
        checkCurrentWord(word);
        if (word[0] != '\00')
        {
            String* currentKeyWord = convertCharsToString(word);
            if (!isInHashTable(currentKeyWord, hashtable))
            {
                pushBucketToHashTable(currentKeyWord, 1, hashtable);
            }
            else
            {
                int entries = getValueFromHashTable(currentKeyWord, hashtable);
                changeBucketInHashTable(currentKeyWord, ++entries, hashtable);
            }
            deleteString(currentKeyWord);
        }
        free(word);
    }

    printHashTable(hashtable);
    printf("\n");
    printHashTableInfo(hashtable);
    printf("\n");

    deleteHashTable(hashtable);
    fclose(text);
    return 0;
}
