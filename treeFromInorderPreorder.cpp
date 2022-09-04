#include<bits/stdc++.h>
using namespace std;
#define COUNT 10
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
//	Node *buildtree(int []pre,int []in,int instrt,int inEnd){
//		static int preIndex = 0;
//		if(instrt>inEnd)return NULL;
//		Node *root=new Node(pre[preIndex++]);
//		if(instrt==inEnd)return root;
//		int inIndex= search(pre,instrt,inEnd,root->data);
//		root->left=buildtree(pre,in,instrt,inIndex-1);
//		root->right= buildtree(pre,in,inIndex+1,inEnd);
//		return root;
//		int r;
//		for(int i=0;i<n;i++){
//		if(pre[1]==in[i]){
//			r=i;
//			for(int j=0;j<r;j++){
//				
//			}
//		}
//		
//	}
//	}
};
int search(int arr[],int cur,int str,int end){
		for(int i=str;i<=end;i++){
			if(arr[i]==cur)
			return i;
		}
		return -1;	
	}
Node* buildTree(int pre[],int in[],int start,int end){
	static int idx=0;
	if(start>end){
		return NULL;
	}
	int cur=pre[idx];
	Node *curr=new Node(cur);
	idx++;
	if(start==end){
		return curr;
	}
	int position=search(in,cur,start,end);
	curr->left=buildTree(pre,in,start,position-1);
	curr->right=buildTree(pre,in,position+1,end);
	return curr;
}

void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
    print2DUtil(root->left, space);
}
void print2D(Node *root)
{
    print2DUtil(root, 0);
}
int main(){
	int preorder[]={1,2,4,3,5};
	int inorder[]={4,2,1,5,3};
	int n=4;
	Node *root=buildTree(preorder,inorder,0,n);
	print2D(root);
}
