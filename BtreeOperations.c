//B tree operations

#include <stdio.h>
#include <stdlib.h>
#define DEGREE 3
typedef struct BTreeNode {
int *keys;
int t;
struct BTreeNode **C;
int n;
int leaf;
} BTreeNode;
BTreeNode *createNode(int t, int leaf) {
BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
node->t = t;
node->leaf = leaf;
node->keys = (int *)malloc((2 * t - 1) * sizeof(int));
node->C = (BTreeNode **)malloc(2 * t * sizeof(BTreeNode *));
node->n = 0;
return node; }
BTreeNode *createBTree(int t) {
return createNode(t, 1);
}
void inOrderTraversal(BTreeNode *root) {
if (root != NULL) {
for (int i = 0; i < root->n; i++) {
inOrderTraversal(root->C[i]);
printf("%d ", root->keys[i]); }
inOrderTraversal(root->C[root->n]);
}
}
BTreeNode *search(BTreeNode *root, int key) {
int i = 0;
while (i < root->n && key > root->keys[i])
i++;
if (i < root->n && key == root->keys[i])
return root;
if (root->leaf)
return NULL;
return search(root->C[i], key);
}
void splitChild(BTreeNode *parent, int i, BTreeNode *child) {
int t = child->t;
BTreeNode *newNode = createNode(t, child->leaf);
newNode->n = t - 1;
for (int j = 0; j < t - 1; j++)
newNode->keys[j] = child->keys[j + t];
if (!child->leaf) {
for (int j = 0; j < t; j++)
newNode->C[j] = child->C[j + t];
}
child->n = t - 1;
for (int j = parent->n; j >= i + 1; j--)
parent->C[j + 1] = parent->C[j];
parent->C[i + 1] = newNode;
for (int j = parent->n - 1; j >= i; j--)
parent->keys[j + 1] = parent->keys[j];
parent->keys[i] = child->keys[t - 1];
parent->n++;
}
void insertNonFull(BTreeNode *node, int key) {
int i = node->n - 1;
if (node->leaf) {
while (i >= 0 && key < node->keys[i]) {
node->keys[i + 1] = node->keys[i];
i--;
}
node->keys[i + 1] = key;
node->n++;
} else {
while (i >= 0 && key < node->keys[i])
i--;
if (node->C[i + 1]->n == 2 * node->t - 1) {
splitChild(node, i + 1, node->C[i + 1]);
if (key > node->keys[i + 1])
i++;
}
insertNonFull(node->C[i + 1], key);
}
}
BTreeNode *insert(BTreeNode *root, int key) {
if (root->n == 2 * root->t - 1) {
BTreeNode *newRoot = createNode(root->t, 0);
newRoot->C[0] = root;
splitChild(newRoot, 0, root);
int i = 0;
if (key > newRoot->keys[0])
i++;
insertNonFull(newRoot->C[i], key);
return newRoot;
} else {
insertNonFull(root, key);
return root;
}
}
int main() {
int choice, value;
BTreeNode *tree = createBTree(DEGREE);
printf("\n1. Insertion\n 2. Searching\n3 . Display (Inorder Traversal)\n 4.Exit\n");
do {
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: 
printf("Enter the value to insert: ");
scanf("%d", &value);
tree = insert(tree, value); 
break;
case 2: 
printf("Enter the value to search: ");
scanf("%d", &value);
BTreeNode *result = search(tree, value);
if (result != NULL)
printf("Value %d found in the tree.\n", value);
else
printf("Value %d not found in the tree.\n", value);
break;
case 3: 
printf("Inorder Traversal: ");
inOrderTraversal(tree);
printf("\n");
break;
case 4: 
printf("Exiting...\n"); 
break;
default: printf("Invalid choice!\n"); }
} while (choice != 4);
return 0;
}