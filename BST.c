#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value in BST
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }

    struct Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

// Find height (longest path nodes count)
int findHeight(struct Node* root) {
    if (root == NULL) return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Mirror the tree
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// Search value in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Inorder Traversal (for display)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function with switch-case
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Find Number of Nodes in Longest Path\n");
        printf("4. Find Minimum Value\n");
        printf("5. Mirror the Tree\n");
        printf("6. Search a Value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Number of nodes in longest path: %d\n", findHeight(root));
                break;

            case 4:
                value = findMin(root);
                if (value != -1)
                    printf("Minimum value in BST: %d\n", value);
                break;

            case 5:
                mirror(root);
                printf("Tree mirrored successfully.\n");
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value %d found in BST.\n", value);
                else
                    printf("Value %d not found in BST.\n", value);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
