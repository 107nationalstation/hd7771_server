
#ifndef __TREAP_H__
#define __TREAP_H__

#define VAL_TYPE int

typedef struct treap {
	VAL_TYPE val;
	int priority;
	struct treap *left;
	struct treap *right;
} treap_t;

int randPriority(int a, int b);
treap_t *leftRotate(treap_t * A);
treap_t *rightRotate(treap_t * B);
treap_t *createNode(VAL_TYPE val);
treap_t *insert(treap_t * root, VAL_TYPE val);
treap_t *delete(treap_t * root, VAL_TYPE val);
void printInOrder(treap_t * root);
VAL_TYPE first(treap_t * root);

#endif
