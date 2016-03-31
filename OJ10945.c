#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
void insert_increase_list(Node**, int);

void printList(Node *head);
void freeList(Node*);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

	while(1){
		scanf("%d", &data);
		if (data >= 0) {
			insert_increase_list(&head, data);
		} else break;
	}

	printList(head);
	freeList(head);
	return 0;
}

void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}
//#include "function.h"
void insert_increase_list(Node **head, int num){
    Node *pre,*cur,*temp;
    temp = (Node*)malloc(sizeof(Node));
    pre = (Node*)malloc(sizeof(Node));
    cur = (Node*)malloc(sizeof(Node));
    int i = 0;
    cur->data = num;
    cur->next = NULL;
    if(*head == NULL) *head = cur;
    else
        for(temp = *head,pre = *head; temp != NULL; temp = temp->next){
            i++;
            if(temp->data >= num) {
                cur->next = temp;
                if(i == 1) *head = cur;
                else pre->next = cur;
                break;
            }
            pre = temp;
            if(temp->next == NULL){
                pre->next = cur;
                cur->next = NULL;
                break;
            }
        }
    printList(*head);
}
