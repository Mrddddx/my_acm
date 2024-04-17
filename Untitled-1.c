#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;              //数据元素
    struct node *lchild;        //指向左孩子
    struct node *rchild;        //指向右孩子
} BTNode;
void CreateBTNode(BTNode *&b, char *str) {
    if (str == NULL || strlen(str) == 0) {
        b = NULL;
        return;
    }

    b = (BTNode *)malloc(sizeof(BTNode));
    b->data = str[0];
    b->lchild = NULL;
    b->rchild = NULL;

    BTNode *current = b;
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] == '(') {
            current->lchild = (BTNode *)malloc(sizeof(BTNode));
            current->lchild->data = str[i + 1];
            current->lchild->lchild = NULL;
            current->lchild->rchild = NULL;
            current = current->lchild;
            i += 2;
        } else if (str[i] == ')') {
            current = current->rchild;
            i++;
        } else {
            current->rchild = (BTNode *)malloc(sizeof(BTNode));
            current->rchild->data = str[i];
            current->rchild->lchild = NULL;
            current->rchild->rchild = NULL;
            current = current->rchild;
            i++;
        }
    }
}

BTNode *FindNode(BTNode *b, ElemType x) {
    if (b == NULL) {
        return NULL;
    }

    if (b->data == x) {
        return b;
    }

    BTNode *leftResult = FindNode(b->lchild, x);
    if (leftResult != NULL) {
        return leftResult;
    }

    return FindNode(b->rchild, x);
}

BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

int BTNodeDepth(BTNode *b) {
    if (b == NULL) {
        return 0;
    }

    int leftDepth = BTNodeDepth(b->lchild);
    int rightDepth = BTNodeDepth(b->rchild);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

void DispBTNode(BTNode *b) {
    if (b == NULL) {
        return;
    }

    printf("%c", b->data);

    if (b->lchild != NULL || b->rchild != NULL) {
        printf("(");
        DispBTNode(b->lchild);

        if (b->rchild != NULL) {
            printf(",");
            DispBTNode(b->rchild);
        }

        printf(")");
    }
}

void DestroyBTNode(BTNode *&b) {
    if (b == NULL) {
        return;
    }

    DestroyBTNode(b->lchild);
    DestroyBTNode(b->rchild);

    free(b);
    b = NULL;
}

int main() {
    BTNode *root = NULL;

    // Create a binary tree from a string representation
    char treeString[] = "A(B(D,E),C(F,G))";
    CreateBTNode(root, treeString);

    // Display the binary tree using parentheses notation
    printf("Binary Tree: ");
    DispBTNode(root);
    printf("\n");

    // Find a node with data 'D' in the binary tree
    ElemType searchData = 'D';
    BTNode *foundNode = FindNode(root, searchData);
    if (foundNode != NULL) {
        printf("Node with data '%c' found in the tree.\n", searchData);
    } else {
        printf("Node with data '%c' not found in the tree.\n", searchData);
    }

    // Display the depth of the binary tree
    int depth = BTNodeDepth(root);
    printf("Depth of the binary tree: %d\n", depth);

    // Destroy the binary tree to free memory
    DestroyBTNode(root);

    return 0;
}
