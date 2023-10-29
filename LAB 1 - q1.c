#include <stdio.h>
#include <stdlib.h>

/*
Write a function that adds all odd numbers to the beginning of the list and all even 
numbers to the end of the list until -1 is entered from the keyboard
*/

struct Node { 
	//creating the Node
	int data;
	struct Node* next;

};
//func do that add new nodes, if its even end of the list or its odd beginning of the list
void insertNode(struct Node **head, int value){
	//value = input
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	
	if (*head == NULL)
		*head = newNode; //if the lsit is empty the head is input
	else if (newNode->data % 2 != 0){
		struct Node *current = newNode;
		current->data = value;
		current->next = *head;
		*head = current;
	}	
	else {
		struct Node *current = *head;
		while (current->next != NULL){
			current = current->next;
		}
	current->next = newNode;
	
	}
}

int main(){

	int value;
	struct Node *head = NULL;
	while(1){//loop up to -1
	
	printf("Enter datas to add the list ( For exit -1 )\n");
		scanf("%d",&value);
		if(value == -1)
			break;
		insertNode(&head, value);//call the func
	}
	struct Node *current = head;
	
	printf("List start with : ");
	
	while(current != NULL){
		printf("%d->", current->data);
		current = current -> next;
	}
	
	printf("end of the list \n");

}