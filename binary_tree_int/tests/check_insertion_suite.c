#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <binary_tree_int.h>

#include "check_suites.h"

#define ROOT_ELEMENT (11)
#define NUM_ELEMENTS (10)

START_TEST(insertion_test)
{
    bt_node_int_t *tree;
    bt_node_int_err_t ret;
    int idx;
    int count;

    tree = bt_int_create(ROOT_ELEMENT);
    fail_if(NULL == tree);
    count = 1;
    for (idx = ROOT_ELEMENT - 1; idx > 0; --idx) {
        ret = bt_int_insert(tree, idx);
        fail_if(BT_INT_SUCCESS != ret);
        ++count;
        fail_if(bt_int_get_height(tree) != count);
    }

    ret = bt_int_destroy(tree);
    fail_if(BT_INT_SUCCESS != ret);

    tree = NULL;
    fail_if(NULL != tree);
}
END_TEST

Suite *
insertion_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Insertion Suite");
    tc = tcase_create("Insertion Test");
    tcase_add_test(tc, insertion_test);
    suite_add_tcase(s, tc);

    return s;
};