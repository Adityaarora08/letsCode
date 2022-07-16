#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st,int last){
	if(st.empty()){ 
		st.push(last);
		return;
	}
	int topele=st.top();
	st.pop();
	insertAtBottom(st,last);
	st.push(topele);
}
void reverse(stack<int> &st){
	if(st.empty()){
		return;
	}
	int last= st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st,last);
}
int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	reverse(st);
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}
