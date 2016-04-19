#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <binary_tree_int.h>

#include "check_suites.h"

#define ROOT_VALUE (5)

START_TEST(creation_success)
{
    bt_node_int_t *tree;
    bt_node_int_err_t ret;

    tree = bt_int_create(ROOT_VALUE);

    ck_assert_ptr_ne(NULL, tree);
    ck_assert_int_eq(ROOT_VALUE, bt_int_get_value(tree));
    ck_assert_ptr_eq(NULL, bt_int_get_left(tree));
    ck_assert_ptr_eq(NULL, bt_int_get_right(tree));

    ret = bt_int_destroy(tree);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);

    tree = NULL;
    ck_assert_ptr_eq(NULL, tree);
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