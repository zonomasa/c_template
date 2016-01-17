/*
  main.c

  Copyright (c) 2016 Masaki TATEZONO

  This software is released under the MIT License.
  http://opensource.org/licenses/mit-license.php
*/

#include <stdio.h>
#include "myutil.h"
#include "library.h"

int
main(int argc, char *argv[]){
    UNUSE(argc);
    UNUSE(argv);

    printf("hello world\n");
    printf("lib_func01 returned %d\n",lib_func01());
    printf("lib_func02 returned %d\n",lib_func02());
    return 0;
}
