#include <stdlib.h>
#include <stdio.h>


struct node{
    int data;
    struct node* next;
};

typedef struct node* NODEPTR;

NODEPTR getNode() {
    return (NODEPTR)malloc(sizeof(node));
}

void freeNode(NODEPTR p) {
    free(p);
}

void push(NODEPTR* head, int x){
    NODEPTR p = getNode();
    p -> data = x;
    p -> next = *head;
    *head = p;
}

void insertAfter(NODEPTR head, float x) {
    if(head==NULL)
        printf("Bos liste! \n");
    else{
        NODEPTR p = getNode();
        p-> next = head -> next;
        p-> data = x;
        head -> next = p;
    }
}

float pop(NODEPTR *head){
    if(*head == NULL) {
        printf("Gonderilen liste bos!");
        return -1;
    }else{
        NODEPTR p = *head;
        float x = p->data;
        *head = (*head)->next;
        freeNode(p);
        return x;
    }
}

float deleteAfter(NODEPTR head) {
    if(head == NULL) {
        printf("Zaten liste bos. Silme yapilamaz! \n");
    }else{
        NODEPTR p = head->next;
        float x =  p-> data;
        head->next = head->next->next;
        freeNode(p);
        return x;
    }
}

void printList(NODEPTR head) {

    while(head!=NULL) {

        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");

}

/*
2->1->3->5->6->4->7
*/
NODEPTR oddEvenList(NODEPTR head){
	
	if(head == NULL) {
		printf("Gönderilen liste boş!");
	}

	else
	{
		NODEPTR tek = head, cift = head-> next, cHead = cift;

		while(cift != NULL && cift-> next != NULL) {
			tek -> next = cift -> next;
			tek = tek -> next; 
			cift -> next = tek -> next;
			cift = cift -> next;
		}
		tek -> next = cHead;
		return head;
	}


}

int main(){
    NODEPTR n = NULL;
    push(&n, 7);
    push(&n, 4);
    push(&n, 6);
    push(&n, 5);
    push(&n, 3);
    push(&n, 1);
    push(&n, 2);

    printf("Orjinal Liste: \n");
    printList(n);

    printf("Ayrık Liste: \n");
    printList(oddEvenList(n));
}
