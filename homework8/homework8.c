#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1
typedef int bool;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;

int countNodes(BinTreeIntNode *node)
{
    int cnt = 0;

    if (node == NULL) {
        
        return cnt;
    }
    if (node->left != NULL) {
        cnt += countNodes(node->left);
    }
    if (node->right != NULL) {
        cnt += countNodes(node->right);
    }

    return ++cnt;
}

bool isBalanced(BinTreeIntNode *root)
{
    if (root == NULL) {
        
        return false;
    }

    return abs(countNodes(root->left) - countNodes(root->right)) <= 1;
}

BinTreeIntNode* treeInsert(BinTreeIntNode *tree, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = tree;
    BinTreeIntNode *parent = tree;
    if (tree == NULL) {
        tree = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return tree;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return tree;
                }
            }
        }
    }

    return tree;
}

BinTreeIntNode* createTree(int size, int range)
{
    srand(time(NULL));
    BinTreeIntNode *root = NULL;
    BinTreeIntNode *tree = treeInsert(root, rand() % range);
    for (int i = 0; i < size; ++i) {
       treeInsert(tree, rand() % range);
    }

    return tree;
}

BinTreeIntNode* searchNode(BinTreeIntNode *node, int data)
{
    if (node != NULL && node->key != data) {
        if (data > node->key) {
            
            return searchNode(node->right, data);
        } else {

            return searchNode(node->left, data);
        }  
    }

    return node;
}

int main(int argc, const char** argv)
{
    const int TREES_COUNT = 50;
    const int TREE_SIZE = 10000;
    const int TREE_RANGE = 10000;

    int balanced = 0;
    BinTreeIntNode *searchTree = NULL;

    for (int i = 0; i < TREES_COUNT; ++i) {
        BinTreeIntNode *tree = createTree(TREE_SIZE, TREE_RANGE);
        if (isBalanced(tree)) {
            balanced++;
        }
        if (i == 0) {
            searchTree = tree;
        } else {
            free(tree);
        }
    }
    printf("Balanced trees %g%% (%d from %d)\n", (float)balanced / TREES_COUNT * 100, balanced, TREES_COUNT);

    srand(time(NULL));
    int num = rand() % TREE_RANGE;
    BinTreeIntNode *node = searchNode(searchTree, num);
    printf("Number %d is %sfound in tree\n", num, node == NULL ? "not " : "");
    free(node);

    return 0;
}
