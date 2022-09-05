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
int main(){
	queue<Node*> q;
	vector< vector<int> > ans;
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	q.push(root);
	while(!q.empty()){
		vector<int> a;
		int n=q.size();
		for(int i=0;i<n;i++){
			Node* temp=q.front();
			q.pop();
			a.push_back(temp->data);
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
		ans.push_back(a);
	}
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
