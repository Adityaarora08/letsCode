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
int maxPathSum(Node* root,int &sum){
	if(root==NULL){
		return sum;
	}
	int ls=maxSum(root->left,sum);
	int rs=maxSum(root->right,sum);
	int nodeMax= max(max(root->data,ls+rs+root->data),max(root->data+ls,root->data+rs));
	sum=max(sum,nodeMax);
	int singlePathSum= max(root->data,max(root->data+ls,root->data+rs));
	return singlePathSum;
}
int maxSum(Node* root){
	int sum=INT_MIN;
	maxPathSum(root,sum);
	return sum;
}
int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	cout<<maxSum(root);
}
