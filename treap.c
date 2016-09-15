#include <stdio.h>
#include <stdlib.h>
#include "treap.h"

treap_t *leftRotate(treap_t * A)
{
	treap_t *B = A->right;
	A->right = B->left;
	B->left = A;

	return B;
}

treap_t *rightRotate(treap_t * B)
{
	treap_t *A = B->left;
	B->left = A->right;
	A->right = B;

	return A;
}

inline int randPriority(int a, int b)
{
	return a + rand() % (b - a + 1);
}

treap_t *createNode(VAL_TYPE val)
{
	treap_t *node = (treap_t *) malloc(sizeof(treap_t));
	if (!node) {
		fprintf(stderr, "Out of memory!\n");
		exit(1);
	}

	node->val = val;
	node->priority = randPriority(0, 100);
	node->left = node->right = NULL;
	return node;
}

treap_t *insert(treap_t * root, VAL_TYPE val)
{
	treap_t *node = createNode(val);
	if (!root)
		return (root = node);
	if (val <= root->val) {
		root->left = insert(root->left, val);
		if (root->left->priority < root->priority)
			root = rightRotate(root);
	} else {
		root->right = insert(root->right, val);
		if (root->right->priority < root->priority)
			root = leftRotate(root);
	}

	return root;
}

treap_t *delete(treap_t * root, VAL_TYPE val)
{
	if (root == NULL) {
		printf("Empty treap, delete failed\n");
		return NULL;
	}

	if (val < root->val)
		root->left = delete(root->left, val);
	else if (val > root->val)
		root->right = delete(root->right, val);
	else {
		if (!root->left || !root->right) {
			treap_t *temp = root;
			if (!root->left)
				root = root->right;
			else
				root = root->left;
			free(temp);
		} else {
			if (root->left->priority < root->right->priority) {
				root = rightRotate(root);
				delete(root->right, val);
			} else {
				root = leftRotate(root);
				delete(root->left, val);
			}
		}
	}
	return root;
}

void printInOrder(treap_t * root)
{
	if (root) {
		printInOrder(root->left);
		printf("key: %d | priority: %d ", root->val, root->priority);
		printf("\n");
		printInOrder(root->right);
	}
}

VAL_TYPE first(treap_t * root)
{
	if (root->left)
		return first(root->left);
	else
		return root->val;
}
