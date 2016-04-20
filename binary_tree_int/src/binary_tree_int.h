#ifndef __BINARY_TREE_INT_H
#define __BINARY_TREE_INT_H

#include <stdio.h>
#include <stdlib.h>

#define BT_INT_SUCCESS 			(0)
#define BT_INT_ERROR 			(-1)
#define BT_INT_INSF_BUF_SIZE 	(-2)
#define BT_INT_INVALID_INPUT	(-3)

typedef enum {
	BT_INT_PREORDER,
	BT_INT_INORDER,
	BT_INT_POSTORDER,
	BT_INT_LEVEL_ORDER,
} bt_int_order_type_t;

typedef struct bt_node_int bt_node_int_t;

typedef int bt_node_int_err_t;

bt_node_int_t *
bt_int_create(int value);

bt_node_int_err_t
bt_int_destroy(bt_node_int_t *root);

bt_node_int_err_t
bt_int_insert(bt_node_int_t *root, int value);

bt_node_int_err_t
bt_int_snprintf(bt_node_int_t *root, bt_int_order_type_t type, char *buf, size_t buf_size);

int
bt_int_get_value(bt_node_int_t *root);

bt_node_int_t *
bt_int_get_left(bt_node_int_t *root);

bt_node_int_t *
bt_int_get_right(bt_node_int_t *root);

int
bt_int_get_height(bt_node_int_t *root);

#endif /* __BINARY_TREE_INT_H */
