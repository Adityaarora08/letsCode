#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* left, *right;
	Node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};
bool checkBST(Node* root,Node* min,Node *max){
	if(root==NULL){
		return true;
	}
	if(min!=NULL && root->data<=min->data){
		return false;
	}
	if(max!=NULL && root->data>=max->data){
		return false;
	}
	return checkBST(root->left,min,root)&&checkBST(root->right,root,max);
}
//wrong approach as it only compares from parent and not with parent of parent
//bool checkBST(Node* root){
//	if(root==NULL || (root->left==NULL && root->right==NULL)){
//		return true;
//	}
//	if(root->left!=NULL && root->right!=NULL){
//		if(root->left->data<root->data && root->right->data>root->data )
//		return (checkBST(root->left)&&checkBST(root->right));
//		else{
//			return false;
//		}
//	}
//	if(root->left!=NULL && root->right==NULL){
//		if(root->left->data<root->data)
//		return checkBST(root->left);
//		else{
//			return false;
//		}
//	}
//	if(root->left==NULL && root->right!=NULL){
//		if(root->right->data>root->data)
//		return checkBST(root->right);
//		else{
//			return false;
//		}
//	}
//	return true;
//}
int main(){
	Node *root = new Node(6);
	root->left = new Node(2);
	root->right = new Node(7);
	root->left->right = new Node(4);
	root->left->right->left = new Node(3);
	root->left->right->right = new Node(5);
	root->right->right = new Node(8);
	int max=INT_MAX,min=INT_MIN;
	cout<<checkBST(root);
}
