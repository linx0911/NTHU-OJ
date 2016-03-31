#include <stdio.h>

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);
//#include "function.h"
void printInfix(Node *root){
    if(root->left != NULL) printInfix(root->left);
    if(root->data >= 'A' && root->data <= 'D'){
        printf("%c",root->data);
        return;
    }else{
        printf("%c",root->data);
        if(root->right->data == '&' || root->right->data == '|')
            printf("(");
        printInfix(root->right);
        if(root->right->data == '&' || root->right->data == '|')
            printf(")");
        return;
    }
}

void freeTree(Node *root);

void constructTree(Node** head)
{
    char c;

    if((*head)==NULL)
    {
        (*head) = (Node *)malloc(sizeof(Node));
		c = getchar();

		(*head)->data = c;

        (*head)->left = (*head)->right = NULL;

        if((*head)->left == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->left);
        if((*head)->right == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->right);
    }
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        getchar();
        Node *root=NULL;
        constructTree(&root);// construct syntax tree
        printInfix(root);// you have to implement this function
        printf("\n");
        freeTree(root);
        n--;

    }

    return 0;
}
