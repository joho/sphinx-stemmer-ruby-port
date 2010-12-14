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
  while(current_word < total_number_of_words) {
    int current_char = 0;
    if ((words[current_word][current_char] = fgetc(scrabble_word_list_file)) == (BYTE)EOF) {
      break;
    }
    else {
      if (words[current_word][current_char] == '\n') {
        current_word++;
      }
      else {
        current_char++;
      }
    }
  }

  stem_en_init();

  for(int i = 0; i < total_number_of_words; i++)
  {
    stem_en(words[i]);
    printf("%s", words[i]);
  }
  // to test
  // stem_en( BYTE * pWord);
  // stem_soundex( BYTE * pWord);
  // stem_dmetaphone( BYTE * pWord, bool bUTF8);

  printf("yes you have compiled correctly\n");
}
