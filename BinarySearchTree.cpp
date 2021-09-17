#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class Node {
	public:
    T data;
	Node *left,*right;
	Node(T val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
	~Node()
	{
		delete left;
		delete right;
	}
};
void print(Node<int>* root){
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" : ";
	if(root->left)
	{
		cout<<"L"<<root->left->data<<" ";
	}
	if(root->right)
	{
		cout<<"R"<<root->right->data<<" ";
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
Node <int>* takeInputLevelWise()
{
	int rootData;
	cout<<"Enter data: ";
	cin>>rootData;
	if(rootData==-1)
	{
		return NULL;
	}
	Node <int>* root=new Node <int>(rootData);
	queue<Node<int>*> pendingNodes; 
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		
	}
}
Node <int>* takeInput()
{
	int rootData;
	cout<<"Enter data: ";
	cin>>rootData;
	if(rootData==-1)
	{
		return NULL;
	}
	Node <int>* root=new Node <int>(rootData);
	Node <int>* leftChild=takeInput();
	Node <int>* rightChild=takeInput();
	root->left=leftChild;
	root->right=rightChild;
	return root;
}
/*
Node *insert(Node *root,int val)
{
	if(root=NULL)
	{
		return new Node(val);
	}
	if(val<root->data)
	{
		root->left=insert(root->left,val);
	}
	else 
	{
		root->right=insert(root->right,val);	
	}
	return root;
}
void inorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node *PrintTreeTriangle(Node *tree, int level) {
	int i;
	if(tree) {
		PrintTreeTriangle(tree->right,level+1);
		cout<<"\n\n";
		for (i=0;i<level;i++)
				cout<<"       ";
		cout<<tree->data;
		PrintTreeTriangle(tree->left,level+1);
	}
	return(NULL);
} */
int main()
{
	/*
	Node<int> *root= new Node<int>(5);
	Node<int> *node1= new Node<int>(1);
	Node<int> *node2= new Node<int>(2);
	root->left=node1;
	root->right=node2;
	*/
	Node<int> *root= takeInput();
	print(root);
	delete root;
	/*
	insert(root,1);
	insert(root,3);
	insert(root,4);
	insert(root,2);
	insert(root,7);
//	PrintTreeTriangle(root,0);
//	inorder(root);
*/
return 0;
}
