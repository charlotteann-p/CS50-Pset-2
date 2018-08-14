#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int i;
    int newAscii;
    char cipher;
    if (argc != 2)
    {
        printf("Please input a non-negative number.\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext: ");
        int key = atoi(argv[1]);
        printf("ciphertext: ");
        for (i = 0; i < strlen(text); i++)
        {
             int ascii = (int)text[i];
             if (isalpha(text[i])) {
               if (key > 26)
               {
                 key = key % 26;
               }
               if (isupper(text[i])) {
                   ascii = ascii - 65;
                   newAscii = ((ascii + key) % 26) + 65;
               } else {
                   ascii = ascii - 97;
                   newAscii = ((ascii + key) % 26) + 97;
               }
             cipher = newAscii;
             }
             else
             {
                 cipher = text[i];
             }
           printf("%c", cipher);
         }
    }
    printf("\n");
}