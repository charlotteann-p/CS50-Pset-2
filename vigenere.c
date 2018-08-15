#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int i = 0;
    int j;
    string text;
    int key;
    int keyarray[10];
    int ascii;
    int newAscii;
    char cipher;
    if (argc != 2)
    {
        printf("Please input a string.\n");
        return 1;
    }
    else
    {
        text = get_string("plaintext: ");
        for (i = 0; i < strlen(argv[1]); i++) {
          key = (int)(argv[1][i]); //loop through argv
          if(key > 64 && key < 97)
          {
              keyarray[i] = key - 65;
              printf("keyarray: %i\n", keyarray[i]);
          }
          else
          {
              keyarray[i] = key - 97;
              printf("keyarray: %i\n", keyarray[i]);
          }

        }
        printf("ciphertext: ");
          for (j = 0; j < strlen(text); j++) { // new brace
            ascii = (int)(text[j]);
              if (isupper(text[j])) {
                  newAscii = ascii + keyarray[j];
              } else {
                  //ascii = ascii - 97;
                  newAscii = ascii + keyarray[j]; //+ 65;
                  // newAscii = ((ascii + key) % 26) + 97;
              }
              cipher = newAscii;
            printf("%c", cipher);
          }
          printf("\n");
    }
}