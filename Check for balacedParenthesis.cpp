#include<iostream>
#include<stack>
//#include<algorithm>

using namespace std;
bool checkParenthesis(string s){
	stack<char> st;
	for(int i=0;i<s.length();i++){
		if(s[i]=='{'||s[i]=='['||s[i]=='('){
			st.push(s[i]);
		}
		else{
			if(s[i]=='}' && st.top()=='{')
			{
				st.pop();
			}
			else if(s[i]==']' && st.top()=='[')
			{
				st.pop();
			}
			else if(s[i]==')' && st.top()=='(')
			{
				st.pop();
			}
			else{
				return false;
			}
		}
	}
	if(st.empty())
		return true;
		else 
		return false;
}
int main(){
	cout<<checkParenthesis("{([)]}");
}
