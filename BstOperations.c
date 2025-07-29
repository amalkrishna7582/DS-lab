//Binary search tree opeartions

#include <stdio.h>
#include <stdlib.h>
struct BSTNode {
int data;
struct BSTNode *left, *right;
};
struct BSTNode* createNode(int data) {
struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
node->data = data;
node->left = node->right = NULL;
return node;
}
struct BSTNode* insert(struct BSTNode* root, int data) {
if (root == NULL)
return createNode(data);
if (data < root->data) {
root->left = insert(root->left, data);
} else if (data > root->data) {
root->right = insert(root->right, data);}
return root;
}

struct BSTNode* findMin(struct BSTNode* root) {
while (root && root->left != NULL) {
root = root->left; }
return root;
}
struct BSTNode* delete(struct BSTNode* root, int data) {
if (root == NULL) {
return root;
}
if (data < root->data) {
root->left = delete(root->left, data);
} else if (data > root->data) {
root->right = delete(root->right, data);
} else {
if (root->left == NULL) {
struct BSTNode* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct BSTNode* temp = root->left;
free(root);
return temp;
}
struct BSTNode* temp = findMin(root->right);
root->data = temp->data;
root->right = delete(root->right, temp->data);
}
return root;
}
void inorder(struct BSTNode* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void preorder(struct BSTNode* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right); }
}
void postorder(struct BSTNode* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);}
}

int main() {
struct BSTNode* root = NULL;
int choice, data;
printf("1. Insert\n2. Delete\n3. In-order Traversal\n4. Pre-order Traversal\n5. Post-order Traversal\n6. Exit\n");
do {
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: printf("Enter data to insert: ");
scanf("%d", &data);
root = insert(root, data);
printf("Node %d inserted.\n", data);
break;
case 2: printf("Enter data to delete: ");
scanf("%d", &data);
root = delete(root, data);
printf("Node %d deleted (if it existed).\n", data);
break;
case 3: printf("In-order Traversal: ");
inorder(root);
printf("\n");
break;
case 4: printf("Pre-order Traversal: ");
preorder(root);
printf("\n");
break;
case 5: printf("Post-order Traversal: ");
postorder(root);
printf("\n");
break;
case 6: printf("Exiting...\n");
break;
default: printf("Invalid choice! Please try again.\n");
}
} while (choice != 6);
return 0;
}