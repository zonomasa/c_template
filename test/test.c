/*
  main.c

  Copyright (c) 2016 Masaki TATEZONO

  This software is released under the MIT License.
  http://opensource.org/licenses/mit-license.php
*/

#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

#include "../src/myutil.h"
#include "../src/library.h"

void test_func01_OK();
void test_func01_NG();


/**
 * @test case for lib_func01
 */
void
test_func01_OK(){
    CU_ASSERT_EQUAL(lib_func01(),1);
    return;
}

/**
 * @test case for lib_func02
 */
void
test_func02_OK(){
    CU_ASSERT_EQUAL(lib_func02(),2);
    return;
}

int
main()
{
    CU_pSuite base_suite;

    CU_initialize_registry();
    base_suite = CU_add_suite("Base functions", NULL, NULL);
    CU_add_test(base_suite, "func01_OK", test_func01_OK);
    CU_add_test(base_suite, "func02_OK", test_func02_OK);
    CU_console_run_tests();
    CU_cleanup_registry();

    return 0;
}
