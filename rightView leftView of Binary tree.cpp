#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
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
	root->right->right->left=new Node(8);
	q.push(root);
	while(!q.empty()){
		vector<int> vec;
		int n=q.size();
		for(int i=0;i<n;i++){
			Node* temp=q.front();
			q.pop();
			vec.push_back(temp->data);
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
		ans.push_back(vec);
	}
	cout<<"Right view: "<<endl;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			if(j==ans[i].size()-1){
				cout<<ans[i][j]<<endl;
			}
		}
	}
	cout<<"Left view: "<<endl;
	for(int i=0;i<ans.size();i++){
	cout<<ans[i][0]<<endl;
	}
	return 0;
}
