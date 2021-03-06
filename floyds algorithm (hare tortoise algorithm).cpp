#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Creating a node
class node {
 public:
  int value;
  node* next;
};
void makeCycle(node* &head,int pos){
	node* temp=head;
	node* startNode;
	
	int count = 1;
	while(temp->next!=NULL){
		if(count==pos){
			startNode=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=startNode;
}
void removeCycle(node* &head){
	node* slow=head;
	node* fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}
bool detectCycle(node* &head){
	node* slow=head;
	node* fast=head;
	
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		
		if(fast==slow){
			return true;
		}
	}
	return false;
}
int main(){
	node *head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtTail(head,6);
	makeCycle(head,3);
	
	return 0;
}
