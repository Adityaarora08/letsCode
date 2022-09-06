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
//Unoptimized approach
int heightOfTree(Node* root){
	if(root==NULL)return 0;
	int lHeight=heightOfTree(root->left);
	int rHeight=heightOfTree(root->right);
	return max(lHeight,rHeight)+1;
}
bool checkBalanced(Node* root){
	int lh,rh;
	if(root==NULL)return true;
	if(!checkBalanced(root->left) || !checkBalanced(root->right)){
		return false;
	}
	lh=heightOfTree(root->left);
	rh=heightOfTree(root->right);
	if(abs(lh-rh)<=1 ){
		return true;
	}else{
		return false;
	}
	return false;
}
//Optimized
bool checkBalancedOp(Node* root,int* height){
	if(root==NULL){
		return true;
	}
	int lh=0,rh=0;
	if(!checkBalancedOp(root->left,&lh)){
		return false;
	}
	if(!checkBalancedOp(root->right,&rh)){
		return false;
	}
	*height=max(lh,rh)+1;
	if(abs(lh-rh)<=1){
		return true;
	}else{
		return false;
	}
	return false;
}
int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	root->right->right->right=new Node(8);
	root->right->right->right->right=new Node(9);
	int height=0;
	if(checkBalancedOp(root,&height)){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Unbalanced"<<endl;
	}
}
