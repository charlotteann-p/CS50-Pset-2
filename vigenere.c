////
////
//// THIS IS VIGENERE, JUST USING CAESAR CODE AS A STARTING POINT!
////
////

//////DOWN TO THE PSEUDOCODE SECTION, THIS IS WHAT I HAVE: PSEUDOCODE IS VER 2

// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main(int argc, string argv[])
// {
//     int i;
//     int key;
//     int ascii;
//     int newAscii;
//     char cipher;

//     if (argc != 2)
//     {
//         printf("Please input a string.\n");
//         return 1;
//     }
//     else
//     {
//         string text = get_string("plaintext: ");
//         printf("ciphertext: ");
//         for (i = 0; i < strlen(argv[1]); i++) {


//           if (isupper(argv[i])) {
//                   key = atoi(argv[i]);
//                   key = key - 65;
//               } else {
//                   key = atoi(argv[i]);
//                   key = key - 97;
//               }

//           for (int j = 0; j < strlen(text); j++)
//           {
//              ascii = (int)text[i];
//              if (isalpha(text[i])) {

//               if (isupper(text[i])) {
//                   ascii = ascii - 65;
//                   newAscii = ((ascii + key) % 26) + 65;
//               } else {
//                   ascii = ascii - 97;
//                   newAscii = ((ascii + key) % 26) + 97;
//               }
//              cipher = newAscii;
//              }
//              else
//              {
//                  cipher = text[i];
//              }
//             printf("%c", cipher);
//           }


//         }
//     }
//     printf("\n");
// }


// PSEUDOCODE ---> CODE
// TRY TO BREAK UP EACH LOOP INTO A SEPARATE FUNCTION
// AS OF JUL 28: I took the text loop out of the key loop.

// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// int main(int argc, string argv[])
// {
//     int i = 0;
//     int j;
//     int key;
//     // int upperkey;
//     // int lowerkey;
//     int ascii;
//     int newAscii;
//     char cipher;
//     if (argc != 2)
//     {
//         printf("Please input a string.\n");
//         return 1;
//     }
//     else
//     {
//         string plaintext = get_string("plaintext: ");
//         printf("ciphertext:\n");
//         if (!isalpha(argv[1])) {
//           printf("input an alphabetic string");
//           return 1;
//         } else {
//         for (i = 0; i < strlen(argv[1]); i++) {
//           key = (int)(argv[1][i]);
//           // printf("%i", key);
//           // if (isupper((argv[1])[i])) {
//           //   upperkey = key - 65;
//           // } else {
//           //   lowerkey = key - 97;
//           // }
//           if(key > 64 && key < 97)
//           {
//               printf("upper key:%i\n", key);
//           }
//           else
//           {
//               printf("lower key: %i\n", key);
//           }
//         }
//       //// HOW TO LOOP THE KEY??? will this help with the segmentation fault error??
//       for (j = 0; j < strlen(plaintext); j++) {
//           // if (isalpha(plaintext[i])) {
//               if (isupper(plaintext[i])) {
//                   ascii = ascii - 65;
//                   newAscii = ((ascii + key) % 26) + 65; // used to use upperkey
//               } else {
//                   ascii = ascii - 97;
//                   newAscii = ((ascii + key) % 26) + 97; // used to use lowerkey
//               }
//               cipher = newAscii;
//             // } else {
//             //     cipher = plaintext[i];
//             // }
//         }
//       printf("%c", cipher); /// NEW

//   /// OLD LOCATION OF THAT CODE FROM ABOVE
//         }
//   }
// }

/////// AS OF JULY 29: WORKING WITH TIM'S HELP

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
    // int upperkey;
    // int lowerkey;
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
        // printf("ciphertext:\n");
        for (i = 0; i < strlen(argv[1]); i++) {
          key = (int)(argv[1][i]); //loop through arv
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
            /// if (isalpha(text[i])) {
              if (isupper(text[j])) {
                  //ascii = ascii - 65;
                  newAscii = ascii + keyarray[j]; //+ 65;
                  // newAscii = ((ascii + key) % 26) + 65;
              } else {
                  //ascii = ascii - 97;
                  newAscii = ascii + keyarray[j]; //+ 65;
                  // newAscii = ((ascii + key) % 26) + 97;
              }
              cipher = newAscii;

            ///}
            ///else {
            ///      cipher = text[i];
            ///}
            printf("%c", cipher); /// NEW LOCATION
          }
          printf("\n");
    // printf("%c", cipher);
    } // new
}