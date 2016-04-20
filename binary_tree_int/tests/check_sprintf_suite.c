#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include <binary_tree_int.h>

#include "check_suites.h"

#define ROOT_ELEMENT (11)
#define NUM_ELEMENTS (10)

#define BUFFER_SIZE (64)

START_TEST(sprintf_test)
{
    bt_node_int_t *tree;
    bt_node_int_err_t ret;
    char buf[BUFFER_SIZE];

    tree = bt_int_create(ROOT_ELEMENT);
    ck_assert_ptr_ne(NULL, tree);

    ret = bt_int_snprintf(tree, BT_INT_PREORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("11 ", buf);

    ret = bt_int_snprintf(tree, BT_INT_INORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("11 ", buf);

    ret = bt_int_insert(tree, 5);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);

    ret = bt_int_snprintf(tree, BT_INT_PREORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("11 5 ", buf);

    ret = bt_int_snprintf(tree, BT_INT_INORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("5 11 ", buf);

    ret = bt_int_insert(tree, 16);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);

    ret = bt_int_snprintf(tree, BT_INT_PREORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("11 5 16 ", buf);

    ret = bt_int_snprintf(tree, BT_INT_INORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("5 11 16 ", buf);

    ret = bt_int_insert(tree, 19);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ret = bt_int_insert(tree, 3);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ret = bt_int_insert(tree, 8);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ret = bt_int_insert(tree, 7);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ret = bt_int_insert(tree, 10);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);

    ret = bt_int_snprintf(tree, BT_INT_PREORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("11 5 3 8 7 10 16 19 ", buf);

    ret = bt_int_snprintf(tree, BT_INT_INORDER, buf, sizeof(buf));
    ck_assert_int_eq(BT_INT_SUCCESS, ret);
    ck_assert_str_eq("3 5 7 8 10 11 16 19 ", buf);

    ret = bt_int_destroy(tree);
    ck_assert_int_eq(BT_INT_SUCCESS, ret);

    tree = NULL;
    ck_assert_ptr_eq(NULL, tree);
}
END_TEST

Suite *
sprintf_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Sprintf Suite");
    tc = tcase_create("Sprintf Test");
    tcase_add_test(tc, sprintf_test);
    suite_add_tcase(s, tc);

    return s;
};