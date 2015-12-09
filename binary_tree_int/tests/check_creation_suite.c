#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <binary_tree_int.h>

#include "check_suites.h"

START_TEST(creation_success)
{
    bt_node_int_t *tree;
    tree = bt_int_create(5);
    fail_if(NULL == tree);
    bt_int_destroy(tree);
    tree = NULL;
    fail_if(NULL != tree);
}
END_TEST

Suite *
creation_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Creation Suite");
    tc = tcase_create("Creation Success");
    tcase_add_test(tc, creation_success);
    suite_add_tcase(s, tc);

    return s;

};