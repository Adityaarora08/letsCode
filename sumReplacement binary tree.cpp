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
void sumReplacement(Node* root){
	if(root==NULL)return;
	sumReplacement(root->left);
	sumReplacement(root->right);
	if(root->left){
//		root->left->data=sumOfNodes(root->left);
		root->data+=root->left->data;
	}
	if(root->right){
//		root->right->data=sumOfNodes(root->right);
		root->data+=root->right->data;
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
	cout<<root->data<<endl;
	sumReplacement(root);
	cout<<root->data;
	return 0;
}
