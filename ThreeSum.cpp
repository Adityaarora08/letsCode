#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(2);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(5);
	arr.push_back(3);
	int n=arr.size();
	int target=1;
	bool found=false;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		int low=i+1,high=n-1;
		while(low<high){
			int sum=arr[i]+arr[low]+arr[high];
			if(sum==target){
				found=true;
			}
			if(sum<target){
				low++;
			}else{
				high--;
			}
		}
	}
	if(found){
		cout<<"FOUND"<<endl;
	}
	else{
		cout<<"NOT FOUND"<<endl;
	}
	return 0;
}
