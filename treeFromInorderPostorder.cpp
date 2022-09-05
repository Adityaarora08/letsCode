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
};
int search(int arr[],int cur,int str,int end){
		for(int i=str;i<=end;i++){
			if(arr[i]==cur)
			return i;
		}
		return -1;	
	}
Node* buildTree(int post[],int in[],int start,int end){
	static int idx=end;
	if(start>end){
		return NULL;
	}
	int cur=post[idx];
	Node *curr=new Node(cur);
	idx--;
	if(start==end){
		return curr;
	}
	int position=search(in,cur,start,end);
	curr->right=buildTree(post,in,position+1,end);
	curr->left=buildTree(post,in,start,position-1);
	
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
	int postorder[]={4,2,5,3,1};
	int inorder[]={4,2,1,5,3};
	int n=4;
	Node *root=buildTree(postorder,inorder,0,n);
	print2D(root);
}
