#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* right;
	Node* left;
	Node(int data){
		this->data=data;
		this->right=NULL;
		this->left=NULL;
	}
};
Node *LCA(Node *root, int node1,int node2){
	if(root==NULL){
		return NULL;
	}
	if(root->data==node1 || root->data==node2){
		return root;
	}
	Node* left=LCA(root->left,node1,node2);
	Node* right=LCA(root->right,node1,node2);
	if(left!=NULL && right!=NULL){
		return root;
	}
	else if(left==NULL && right==NULL){
		return NULL;
	}
	else if(left!=NULL &&right==NULL){
		return left;
	}
	else{
		return right;
	}
}
int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	Node* ans=LCA(root,5,7);
	cout<<ans->data;
}
