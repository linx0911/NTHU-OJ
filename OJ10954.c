#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int abcd[4],site;
char input[20];
typedef struct _Node{
    struct _Node *left,*right;
    char op;
}Node;
Node* BT(){
    Node *t;
    t = (Node*)malloc(sizeof(Node));
    t->op = input[site];
    t->left = NULL;
    t->right = NULL;
    if(input[site] >= 'A' && input[site] <= 'D'){
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
    if(temp->op>='A' && temp->op<='D') return abcd[temp->op-'A'];
    int l = w(temp->left),r = w(temp->right);
    if(temp->op=='|') return l|r;
    else return l&r;
}
void prefix(){
    int i,j,k;
    Node *head;
    head = (Node*)malloc(sizeof(Node));
    head = BT();
    for(i = 0; i < 16; i++){
        for(j = 1,k = 3; j <= 8; j*=2,k--)
            abcd[k] = (i & j)>>(3-k);
        int ans = w(head);
        for(j = 0; j < 5; j++){
            if(j >= 0 && j < 4) printf("%d ",abcd[j]);
            else printf("%d\n",ans);
        }
    }

}
int main(){
    scanf("%s",input);
    site = 0;
    prefix();
    return 0;
}
