#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL) return NULL;
    TreeNode* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    return root;
}

int areIdentical(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == NULL && tree2 == NULL) return 1;
    if (tree1 == NULL || tree2 == NULL) return 0;
    return (tree1->val == tree2->val &&
            areIdentical(tree1->left, tree2->left) &&
            areIdentical(tree1->right, tree2->right));
}

int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

TreeNode* buildSampleTree1() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    return root;
}

TreeNode* buildSampleTree2() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    return root;
}

TreeNode* buildSampleTree3() {
    TreeNode* root = newNode(5);
    root->right = newNode(6);
    return root;
}

int main() {
    TreeNode* tree1 = buildSampleTree1();
    TreeNode* tree2 = buildSampleTree2();
    TreeNode* tree3 = buildSampleTree3();

    int choice;
    do {
        printf("\nBinary Tree Operations Menu\n");
        printf("===========================\n");
        printf("1. Mirror Tree1\n");
        printf("2. Compare Tree1 and Tree2\n");
        printf("3. Count Nodes in Tree3\n");
        printf("4. Print Tree1 (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                mirrorTree(tree1);
                printf("Tree1 mirrored.\n");
                break;
            case 2:
                if (areIdentical(tree1, tree2))
                    printf("Tree1 and Tree2 are identical.\n");
                else
                    printf("Tree1 and Tree2 are NOT identical.\n");
                break;
            case 3:
                printf("Tree3 has %d nodes.\n", countNodes(tree3));
                break;
            case 4:
                printf("Tree1 (Inorder): ");
                inorder(tree1);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
