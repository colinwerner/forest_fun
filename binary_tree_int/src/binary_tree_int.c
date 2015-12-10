#include <stdio.h>
#include <stdlib.h>

#include "binary_tree_int.h"

struct bt_node_int
{
	int value;
	struct bt_node_int *left;
	struct bt_node_int *right;
};

bt_node_int_t *
bt_int_create(int value)
{
	bt_node_int_t *root;

	root = calloc(1, sizeof(bt_node_int_t));
	if (NULL != root) {
		root->value = value;
	}

	return root;
}

bt_node_int_err_t
bt_int_destroy(bt_node_int_t *root)
{
	bt_node_int_err_t ret;

	ret = BT_INT_ERROR;

	if (NULL != root) {
		bt_int_destroy(root->left);
		bt_int_destroy(root->right);
		free(root);
		ret = BT_INT_SUCCESS;
	}

	return ret;
}

static bt_node_int_err_t
insert_node(bt_node_int_t *root, bt_node_int_t *node)
{
	bt_node_int_err_t ret;

	ret = BT_INT_ERROR;

	if ((NULL != root) && (NULL != node)) {
		if (root->value > node->value) {
			// go left
			if (NULL == root->left) {
			    root->left = node;
			    ret = BT_INT_SUCCESS;
			} else {
			    ret = insert_node(root->left, node);
			}
        } else {
            // go right
            if (NULL == root->right) {
                root->right = node;
                ret = BT_INT_SUCCESS;
            } else {
                ret = insert_node(root->right, node);
            }
        }
	}

	return ret;
}

bt_node_int_err_t
bt_int_insert(bt_node_int_t *root, int value)
{
	bt_node_int_t *new;
	bt_node_int_err_t ret;

	ret = BT_INT_ERROR;

	if (NULL != root) {
		new = calloc(1, sizeof(bt_node_int_t));
		if (NULL != new) {
		    new->value = value;
		    new->left = NULL;
		    new->right = NULL;
			ret = insert_node(root, new);
		}
	}

	return ret;
}

static bt_node_int_err_t
print_preorder(bt_node_int_t *root, char *buf, size_t buf_size,
               size_t printed)
{
    bt_node_int_err_t ret;
    ret = BT_INT_ERROR;
    if (NULL != root) {
        printed += snprintf(buf + printed, buf_size - printed, "%d ",
            root->value
        );
        print_preorder(root->left, buf, buf_size, printed);
        print_preorder(root->right, buf, buf_size, printed);
        if (printed < buf_size) {
            ret = BT_INT_SUCCESS;
        }
    }

    return ret;
}

static bt_node_int_err_t
print_inorder(bt_node_int_t *root, char *buf, size_t buf_size, size_t printed)
{
    bt_node_int_err_t ret;
    ret = BT_INT_ERROR;
    if (NULL != root) {
        print_preorder(root->left, buf, buf_size, printed);
        printed += snprintf(buf + printed, buf_size - printed, "%d ",
            root->value
        );
        print_preorder(root->right, buf, buf_size, printed);
        if (printed < buf_size) {
            ret = BT_INT_SUCCESS;
        }
    }

    return ret;
}

static bt_node_int_err_t
print_postorder(bt_node_int_t *root, char *buf, size_t buf_size,
                size_t printed)
{
    bt_node_int_err_t ret;
    ret = BT_INT_ERROR;
    if (NULL != root) {
        print_preorder(root->left, buf, buf_size, printed);
        print_preorder(root->right, buf, buf_size, printed);
        printed += snprintf(buf + printed, buf_size - printed, "%d ",
            root->value
        );
        if (printed < buf_size) {
            ret = BT_INT_SUCCESS;
        }
    }

    return ret;
}

bt_node_int_err_t
bt_int_sprintf(bt_node_int_t *root, bt_int_order_type_t type, char *buf, size_t buf_size) {
    bt_node_int_err_t ret;
    ret = BT_INT_ERROR;
    switch (type) {
        case BT_INT_PREORDER:
            ret = print_preorder(root, buf, buf_size, 0);
        break;

	    case BT_INT_INORDER:
            ret = print_inorder(root, buf, buf_size, 0);
	    break;

	    case BT_INT_POSTORDER:
	        ret = print_postorder(root, buf, buf_size, 0);
	    break;

	    case BT_INT_LEVEL_ORDER:
	        // TODO: need a queue
	    break;

	    default:
	        ret = BT_INT_INVALID_INPUT;
	    break;
	}

    return ret;
}

int
bt_int_get_value(bt_node_int_t *root) {
    return root->value;
}

bt_node_int_t *
bt_int_get_left(bt_node_int_t *root) {
    return root->left;
}

bt_node_int_t *
bt_int_get_right(bt_node_int_t *root) {
    return root->right;
}

int
bt_int_get_height(bt_node_int_t *root) {
    int left_height;
    int right_height;

    if (NULL == root) {
        left_height = right_height = 0;
    } else {
        left_height = 1 + bt_int_get_height(root->left);
        right_height = 1+ bt_int_get_height(root->right);
    }

    return ((left_height > right_height) ? left_height : right_height);
}