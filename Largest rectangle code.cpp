#include<bits/stdc++.h>
using namespace std;

int get_max_area(vector<int> arr){
//Brute force
//	int n=arr.size();
//	int area=0;
//	int minh=0;
//	for(int i=0;i<n;i++)
//	{
//		minh=INT_MAX;
//		for(int j=i;j<n;j++){
//			minh=min(arr[j],minh);
//			int len=j-i+1;
//			area=max(area,len*minh);
//		}
//	}
//	return area;

//using stack
    int n=arr.size();
	int ans=0;
	stack<int> st;
	arr.push_back(0);
	for(int i=0;i<n;i++){
		while(!st.empty() && arr[st.top()]>arr[i]){
			int h= arr[st.top()];
			st.pop();
			if(st.empty()){
				ans=max(ans,h*i);
			}
			else{
				ans= max(ans,h*(i-st.top()-1));
			}
		}
		st.push(i);
	}
	return ans;
}
int main(){
	vector<int> a;
	a.push_back(2);
	a.push_back(1);
	a.push_back(5);
	a.push_back(6);
	a.push_back(2);
	a.push_back(3);
	cout<<get_max_area(a)<<endl;
	return 0;
}
