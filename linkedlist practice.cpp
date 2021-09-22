#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	
	Node(int data)
	{
		this->data=data;
		next= NULL;
	}
};
class Pair{
	public:
		Node* head;
		Node* tail;
};
Pair reverse_better(Node *head)
{
	if(head==NULL || head->next==NULL)
	{
		Pair ans;
		ans.head=head;
		ans.tail=head;
	}
	Pair smallans=reverse_better(head->next);
	smallans.tail->next=head;
	head->next=NULL;
	Pair ans;
	ans.head=smallans.head;
	ans.tail=head;
	return ans;
}
Node *reversereturnconversion(Node* head)
{
	return reverse_better(head).head;
}
/*
Node *takeinput()
{
	int data;
	cin>>data;
	Node *head=NULL;
	while(data!=-1)
	{
		Node *newNode=new Node(data);
		if(head==NULL)
		{
		head=newNode;
		}
		else
		{
			Node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
		}
		
		cin>>data;
	}
		return head;
}*/
Node *takeinput_better()
{
	int data;
	cin>>data;
	Node *head=NULL;
	Node *tail=NULL;
	while(data!=-1)
	{
		Node *newNode=new Node(data);
		if(head==NULL)
		{
		head=newNode;
		tail=newNode;
		}
		else
		{
			
			tail->next=newNode;
			tail=tail->next;
			//OR tail=newNode;
		}
		
		cin>>data;
	}
		return head;
}
Node* insertNode(Node *head,int i,int data)
{
	Node *newNode = new Node(data);
	int count =0;
	Node *temp=head;
	if(i==0)
	{
		newNode->next=head;
		head=newNode;
		return head;
	}
	while(temp!=NULL && count<=i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		Node *a=temp->next;
    	temp->next=newNode;
	    newNode->next=a;
	}
	return head;
	
}
void middle(Node *head,int l)
{
	Node *temp=head;
	int count=0;
	if(l%2==0)
	{
	while(temp!=NULL && count<(l/2)-1)
	{
		temp=temp->next;
		count++;
	}
	cout<<"\nMiddle node of the linked list is: "<<temp->data;	
	}
	else if(l%2!=0)
	{
	while(temp!=NULL && count<l/2)
	{
		temp=temp->next;
		count++;
	}
	cout<<"\nMiddle node of the linked list is: "<<temp->data;
	}	
//	cout<<"Middle node of the linked list is: "<<temp->data;
}
int length(Node *head)
{
	Node *temp=head;
	int count=0;
	while(temp!=NULL)
	{
      	temp=temp->next;
      	count++;
	}
	return count;
}
void print(Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
      	temp=temp->next;
	}
/*	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
      	temp=temp->next;
	}*/
}
Node *reverse(Node *head)
{
	if(head==NULL || head->next==NULL)
	return head;
	Node *smallans=reverse(head->next);
	Node *temp=smallans;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return smallans;
}
Node* deleteNode(Node *head,int i)
{
	//Node *newNode = new Node(data);
	int count =0;
	Node *temp=head;
	if(i==0)
	{
		head=head->next;
		return head;
	}
	i=i-1;
	while(temp!=NULL && count<=i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		Node *a=NULL;
		Node *b=NULL;
    //	temp->next=newNode;
	    //newNode->next=a;
		a=temp->next;
		b=a->next;
		temp->next=b;
		delete a;
	}
	return head;	
}
int main()
{
	Node *head=takeinput_better();
	print(head);
	//int i,data;
	//cin>>i;
	//head=deleteNode(head,i);
	//print(head);
	int a;
	a=length(head);
	middle(head,a);
/*
	//statically
	Node n1(1);
	Node *head=&n1;
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	print(head);
	
	//dynamically
	Node *n3=new Node(10);
	Node *head=n3;
	Node *n4=new Node(20);
	n3->next=n4;
*/	
}
