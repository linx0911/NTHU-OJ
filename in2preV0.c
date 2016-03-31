/* This program construct a syntax tree from an infix Boolean expression.
   The expression has no parenthesis, and no error checking.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEXPR 256
#define NUMSYM 6
char expr[MAXEXPR];

typedef enum {VAR_A, VAR_B, VAR_C, VAR_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM]="ABCD&|";

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

/* create a node without any child.*/
BTNode* makeNode(char c){
    int i;
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    for (i = 0; i< NUMSYM; i++)
        if (c==sym[i]) node->data = i;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* print a tree by in-order. */
void printInfix(BTNode *root){
    if (root != NULL) {
        printInfix(root->left);
        printf("%c",sym[root->data]);
        printInfix(root->right);
    }
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* parse an infix expression and generate a syntax tree. */
/* Grammar: EXPR := VAR | EXPR OP VAR*/
BTNode* parser(int start, int end)
{
   int i;
   BTNode *node;

   if (start==end) // EXPR = VAR
      return makeNode(expr[end]);
   else            // EXPR = EXPR OP VAR
   {
      node = makeNode(expr[end-1]);
      node->right = makeNode(expr[end]);
      node->left = parser(start, end-2);

      return node;
   }
}

/* parse a prefix expression and generate a syntax tree. */
/* Grammar: prefix := VAR | OP <prefix> <prefix> */
BTNode* pre_parser()
{
   int i;
   BTNode *node;
   static pos=0; // a static variable to remember the current position in the expr[]

   if (expr[pos]>='A' && expr[pos]<='D') // prefix = VAR
      return makeNode(expr[pos++]);
   else            // prefix = OP <prefix> <prefix>
   {
      node = makeNode(expr[pos++]);
      node->left = pre_parser();
      node->right = pre_parser();

      return node;
   }
}

int main(){
    int len;
    gets(expr);
    len = strlen(expr);
    //BTNode *root = parser(0, len-1);
    BTNode *root = pre_parser();
    //printPrefix(root);
    printInfix(root);
    freeTree(root);
    return 0;
}
