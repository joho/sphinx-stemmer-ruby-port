#include <stdio.h>

#include "sphinxstem.h"

int main(int argc, const char* argv[])
{
  int total_number_of_words, max_length_of_any_word;

  FILE *scrabble_word_list_file;

  scrabble_word_list_file = fopen("words/TWL06.txt", "r");
  
  // i know these cos i cheated and measured them
  // using irb. god files and string are a PITA in C
  total_number_of_words = 178691;
  max_length_of_any_word = 15;

  BYTE words[total_number_of_words][max_length_of_any_word + 3];
  for(int i = 0; i < total_number_of_words; i++) 
  {
    fgets(words[i], max_length_of_any_word + 3, scrabble_word_list_file);
  }

  for(int i = 100; i < 200; i++)
    printf("%s", words[i]);


  stem_en_init();

  // to test
  // stem_en( BYTE * pWord);
  // stem_soundex( BYTE * pWord);
  // stem_dmetaphone( BYTE * pWord, bool bUTF8);

  printf("yes you have compiled correctly\n");
}
