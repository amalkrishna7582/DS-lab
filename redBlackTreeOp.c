
//RedBlack tree oprations.

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node* parent;
struct Node* left;
struct Node* right;
int color;
} Node;
typedef struct RedBlackTree {
Node* root;
} RedBlackTree;
Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL) {
printf("Memory allocation error\n");
exit(1);
}
newNode->data = data;
newNode->parent = newNode->left = newNode->right = NULL;
newNode->color = 1;
return newNode;
}
RedBlackTree* createRedBlackTree() {
RedBlackTree* newTree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
if (newTree == NULL) {
printf("Memory allocation error\n");
exit(1);
}
newTree->root = NULL;
return newTree;
}
void leftRotate(RedBlackTree* tree, Node* x) {
Node* y = x->right;
x->right = y->left;
if (y->left != NULL) y->left->parent = x;
y->parent = x->parent;
if (x->parent == NULL) tree->root = y;

else if (x == x->parent->left) x->parent->left = y;
else x->parent->right = y;
y->left = x;
x->parent = y;
}
void rightRotate(RedBlackTree* tree, Node* y) {
Node* x = y->left;
y->left = x->right;
if (x->right != NULL) x->right->parent = y;
x->parent = y->parent;
if (y->parent == NULL) tree->root = x;
else if (y == y->parent->left) y->parent->left = x;
else y->parent->right = x;
x->right = y;
y->parent = x;
}
void fixInsert(RedBlackTree* tree, Node* z) {
while (z != tree->root && z->parent->color == 1) {
if (z->parent == z->parent->parent->left) {
Node* y = z->parent->parent->right;
if (y != NULL && y->color == 1) {
z->parent->color = 0;
y->color = 0;
z->parent->parent->color = 1;
z = z->parent->parent;
} else {
if (z == z->parent->right) {
z = z->parent;
leftRotate(tree, z);
}
z->parent->color = 0;
z->parent->parent->color = 1;
rightRotate(tree, z->parent->parent);
}
} else {
Node* y = z->parent->parent->left;
if (y != NULL && y->color == 1) {
z->parent->color = 0;
y->color = 0;
z->parent->parent->color = 1;
z = z->parent->parent;
} else {
if (z == z->parent->left) {
z = z->parent;
rightRotate(tree, z);
}
z->parent->color = 0;
z->parent->parent->color = 1;

leftRotate(tree, z->parent->parent);
}
} }
tree->root->color = 0;
}
void insert(RedBlackTree* tree, int data) {
Node* z = createNode(data);
Node* y = NULL;
Node* x = tree->root;
while (x != NULL) {
y = x;
if (z->data < x->data) x = x->left;
else x = x->right;
}
z->parent = y;
if (y == NULL) tree->root = z;
else if (z->data < y->data) y->left = z;
else y->right = z;
fixInsert(tree, z);
}
void inOrderTraversal(Node* root) {
if (root != NULL) {
inOrderTraversal(root->left);
printf("%d (%s) -> ", root->data, root->color == 0 ? "BLACK" : "RED");
inOrderTraversal(root->right);
}
}
int main() {
int choice, value;
RedBlackTree* tree = createRedBlackTree();
printf("\n1. Create Red-Black Tree\n2. Insert a new node\n 3. Left-Rotate\n 4. Right Rotate\n5. Inorder Traversal\n6. Exit\n ");
do {
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1: tree = createRedBlackTree();
printf("Red-Black Tree created successfully!\n");
break;
case 2: printf("Enter the value to be inserted: ");
scanf("%d", &value);
insert(tree, value);
printf("Node inserted successfully!\n");
break;
case 3:{
int rotateValue;
printf("Enter the node value to perform left rotation: ");
scanf("%d", &rotateValue);

Node* nodeToRotate = tree->root;
while (nodeToRotate != NULL && nodeToRotate->data !=rotateValue) {
if (rotateValue < nodeToRotate->data)
nodeToRotate = nodeToRotate->left;
else
nodeToRotate = nodeToRotate->right;
}
if (nodeToRotate != NULL) {
leftRotate(tree, nodeToRotate);
printf("Left rotation performed on node %d\n", rotateValue);
} else {
printf("Node with value %d not found!\n", rotateValue);
}
}break;
case 4:{
int rotateValue;
printf("Enter the node value to perform right rotation: ");
scanf("%d", &rotateValue);
Node* nodeToRotate = tree->root;
while (nodeToRotate != NULL && nodeToRotate->data !=
rotateValue) {
if (rotateValue < nodeToRotate->data)
nodeToRotate = nodeToRotate->left;
else
nodeToRotate = nodeToRotate->right;
}
if (nodeToRotate != NULL) {
rightRotate(tree, nodeToRotate);
printf("Right rotation performed on node %d\n", rotateValue);
} else {
printf("Node with value %d not found!\n", rotateValue);
}
} break;
case 5: printf("Inorder Traversal: ");
inOrderTraversal(tree->root);
printf("NULL\n"); break;
case 6: printf("Exiting...\n");
break;
default: printf("Invalid choice. Please try again!\n"); }
} while (choice != 6);
return 0;
}
