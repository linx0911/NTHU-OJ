#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int site;
int input[1000];
typedef struct _Node{
    struct _Node *left,*right;
    int op;
}Node;
Node* BT(){
    Node *t;
    t = (Node*)malloc(sizeof(Node));
    t->op = input[site];
    t->left = NULL;
    t->right = NULL;
    if(input[site] > 0){
        site++;
        return t;
    }
    else{
        site++;
        t->left = BT();
        t->right = BT();
        return t;
    }

}
int w(Node *temp){
    if(temp->op>0) return temp->op;
    int l = w(temp->left),r = w(temp->right);
    if(temp->op==-1) return l+r;
    else return l-r;
}
void prefix(){
    int i,j,k;
    Node *head;
    head = (Node*)malloc(sizeof(Node));
    head = BT();
    int ans = w(head);
    printf("%d",ans);
}
int main(){
    char e[10];
    int i = 0,j,k;
    while(1){
        scanf("%s",e);
        if(e[0] == '0') break;
        else if(e[0] == '+') input[i++] = -1;
        else if(e[0] == '-') input[i++] = -2;
        else{
            for(j = strlen(e) - 1,k = 0; j >= 0; j--,k++)
                input[i] += (e[j] - '0')*pow(10,k);
            i++;
        }
    }
    site = 0;
    prefix();
    return 0;
}
