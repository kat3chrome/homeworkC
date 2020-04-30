#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "string.h"

struct HashTable;
typedef struct HashTable HashTable;

HashTable* createHashTable(int capacity);
void deleteHashTable(HashTable* hashtable);
bool isInHashTable(String* key, HashTable* hashtable);
int getValueFromHashTable(String* key, HashTable* hashtable);
void pushBucketToHashTable(String* key, int value, HashTable* hashtable);
void deleteBucketFromHashTable(String* key, HashTable* hashtable);
void changeBucketInHashTable(String* key, int newValue, HashTable* hashtable);
void printHashTable(HashTable* hashtable);
void printHashTableInfo(HashTable* hashtable);

#endif
