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
int countNodes(Node* root){
	if(root==NULL)return 0;
	return countNodes(root->left)+countNodes(root->right)+1;
}
int sumOfAllNodes(Node* root){
	if(root==NULL)return 0;
	return sumOfAllNodes(root->left)+sumOfAllNodes(root->right)+root->data;
}
int heightOfTree(Node* root){
	if(root==NULL)return 0;
	int lHeight=heightOfTree(root->left);
	int rHeight=heightOfTree(root->right);
	return max(lHeight,rHeight)+1;
}
//time complexity O(n^2)
int diameterOfTree(Node* root){
	if(root==NULL)return 0;
	int lDiameter=diameterOfTree(root->left);
	int rDiameter=diameterOfTree(root->right);
	int lHeight=heightOfTree(root->left);
	int rHeight=heightOfTree(root->right);
	return max(lHeight+rHeight+1,max(lDiameter,rDiameter));
}
//time complexity O(n)
int diameterOfTreeOptimised(Node* root,int* height){
	if(root==NULL){
		*height=0;
		return 0;
	}
	int lh=0,rh=0;
	int lDiameter=diameterOfTreeOptimised(root->left,&lh);
	int rDiameter=diameterOfTreeOptimised(root->right,&rh);
	*height=max(lh,rh)+1;
	return max(lh+rh+1,max(lDiameter,rDiameter));
}
int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	int height=0;
	cout<<countNodes(root)<<"\n"<<sumOfAllNodes(root)<<"\n"<<heightOfTree(root)<<"\n"<<diameterOfTreeOptimised(root,&height)<<endl;
}
