#include <stdio.h>

#include "sphinxstem.h"

int main(int argc, const char* argv[]) {
  int total_number_of_words, max_length_of_any_word;

  FILE *scrabble_word_list_file;

  scrabble_word_list_file = fopen("words/TWL06.txt", "r");
  
  // i know these cos i cheated and measured them
  // using irb. god files and string are a PITA in C
  total_number_of_words = 178691;
  max_length_of_any_word = 15;

  // FYI BYTE = typedef unsigned char
  BYTE words[total_number_of_words][max_length_of_any_word + 3];
  int current_word = 0;
  int current_char = 0;
  while(current_word < total_number_of_words) {
    if ((words[current_word][current_char] = (BYTE)fgetc(scrabble_word_list_file)) == (BYTE)EOF) {
      printf("reached end of file");
      break;
    }
    else {
      // printf("%c", words[current_word][current_char]);
      if (words[current_word][current_char] == '\n') {
        words[current_word][current_char - 1] = '\0';
        current_word++;
        current_char = 0;

      } else {
        words[current_word][current_char] = tolower((char)words[current_word][current_char]);
        current_char++;
      }
    }
  }

  stem_en_init();

  for(int i = 0; i < total_number_of_words; i++)
  {
    // printf("%s", words[i]);
    BYTE stemmed[15];
    strcpy((char*)stemmed, (char*)words[i]);
    stem_en(stemmed);
    if (strcmp((char*)words[i], (char*)stemmed)) {
      printf("%s %s\n", words[i], stemmed);
    }
  }
  // to test
  // stem_en( BYTE * pWord);
  // stem_soundex( BYTE * pWord);
  // stem_dmetaphone( BYTE * pWord, bool bUTF8);

  printf("yes you have compiled correctly\n");
}
