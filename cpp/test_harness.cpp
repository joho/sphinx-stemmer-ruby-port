#include <stdio.h>

#include "sphinxstem.h"

int main(int argc, const char* argv[])
{
  stem_en_init();

  // to test
  // stem_en( BYTE * pWord);
  // stem_soundex( BYTE * pWord);
  // stem_dmetaphone( BYTE * pWord, bool bUTF8);

  printf("yes you have compiled correctly\n");
}
