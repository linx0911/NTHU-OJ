#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef struct _node{
    struct _node *left;
    struct _node *right;
    int number;
}Node;
Node* new_node(int num){
    Node *tmp;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->number = num;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void build(Node* head, Node* tmp){
    if(tmp->number > head->number){
        if(head->right != NULL) build(head->right, tmp);
        else head->right = tmp;
    }
    else if(tmp->number < head->number){
        if(head->left != NULL) build(head->left, tmp);
        else head->left = tmp;
    }
}

void pre(Node *head){
    if(head == NULL) return;
    printf(" %d",head->number);
    pre(head->left);
    pre(head->right);
    return;
}

void in(Node *head){
    if(head == NULL) return;
    in(head->left);
    printf(" %d",head->number);
    in(head->right);
    return;
}

void post(Node *head){
    if(head == NULL) return;
    post(head->left);
    post(head->right);
    printf(" %d",head->number);
    return;
}

int main(){
    int n, v;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&v);
        Node *head;
        for(int i = 0; i < v; i++){
            int t;
            scanf("%d",&t);
            Node *tmp = new_node(t);
            if(i == 0) head = tmp;
            else  build(head, tmp);
        }
        printf("preorder:");
        pre(head);
        printf("\ninorder:");
        in(head);
        printf("\npostorder:");
        post(head);
        printf("\n");
    }
    return 0;
}
