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
//Node* flattenBinaryTree(Node* root){
//	if(root==NULL){
//		return NULL;
//	}
//	Node* left=flattenBinaryTree(root->left);
//	Node* right=flattenBinaryTree(root->right);
//	if(left||right){
////	Node* temp=root->right;
//	root->right=left;
//	Node* t=root->right;
//	while(t->right!=NULL)
//	{
//		t=t->right;
//	}
//	t->right=right;
//	root->left=NULL;
//	left->left=NULL;
//	}
//	return root;
//}
void flattenTree(Node* root){
	if(root==NULL || root->left==NULL && root->right==NULL){
		return;
	}
	if(root->left!=NULL){
		flattenTree(root->left);
		Node* temp=root->right;
		root->right=root->left;
		root->left=NULL;
		Node* t=root->right;
		while(t->right!=NULL){
			t=t->right;
		}
		t->right=temp;
	}
	flattenTree(root->right);
}
int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
//	root=flattenBinaryTree(root);
flattenTree(root);
	while(root!=NULL){
		cout<<root->data<<endl;
		root=root->right;
	}
}
