#include <stdio.h>

#include "sphinxstem.h"

int main(int argc, const char* argv[])
{
  int stem_return_code = stem_en_init();
  printf("yes you have compiled correctly\n%d\n", stem_return_code);
}
