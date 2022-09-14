#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int data){
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};

void print(Node* root){
	if(root==NULL){
		return;
	}
	print(root->left);
	cout<<root->data<<endl;
	print(root->right);
}
Node* input(bool isRoot, int parent, bool isLeft){
	if(isRoot)
		cout<<"Enter root data : ";
	else{
		if(isLeft)
			cout<<"Enter left node of "<<parent<<" : ";
		else{
			cout<<"Enter right node of "<<parent<<" : ";
		}
	}
	int n;
	cin>>n;
	if(n == -1)
		return NULL;
	
	Node *rootNode = new Node(n);
	Node *leftChildofRoot = input(false,n,true);
	Node *rightChildOfRoot = input(false,n , false);
	
	rootNode->left = leftChildofRoot;
	rootNode->right = rightChildOfRoot;
	
	return rootNode;
}
int countNodes(Node* root){
	if(root==NULL){
		return 0;
	}
	int ln=countNodes(root->left);
	int rn=countNodes(root->right);
	return ln+rn+1;
}
int sumNodes(Node* root){
	if(root==NULL){
		return 0;
	}
	int ln=sumNodes(root->left);
	int rn=sumNodes(root->right);
	return ln+rn+root->data;
}
int main(){
	int val,left,right;
//	Node* root=input(true,0,false);
Node* root=new Node(1);
root->left=new Node(2);
root->left->left=new Node(4);
	print(root);
	cout<<"No. of Nodes: "<<countNodes(root)<<endl;
	cout<<"Sum of Nodes: "<<sumNodes(root);
}
