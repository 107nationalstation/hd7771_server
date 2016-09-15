#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treap.h"

int main(void)
{
	srand(time(NULL));
	treap_t *root = NULL;

	for (int i = 0; i < 10240; i++) {
		root = insert(root, i);
	}

	printf("InOrder traversal of input treap\n");
	printf("\n");

	printf("Delete first, first\n");
	root = delete(root, first(root));
	printf("First now %d\n", first(root));
	root = delete(root, first(root));
	printf("First now %d\n", first(root));

	printf("InOrder traversal of input treap post deletion\n");

	return 0;

}
