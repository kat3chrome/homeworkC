#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "string.h"

int main()
{
    FILE* text = fopen("text.txt", "r");

    fclose(text);
    return 0;
}
