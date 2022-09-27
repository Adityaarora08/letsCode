#include<bits/stdc++.h>
using namespace std;
//check if there exists a subarray of size k where sum is divisible by 3
bool check(vector<int> nums,int k){
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=nums[i];
	}
	int low=0;
	for(int i=k;i<nums.size();i++){
		if(sum%3==0){
			return true;
		}else{
			sum-=nums[low];
			low++;	
		}
		sum+=nums[i];
	}
	if(sum%3==0){
		return true;
	}
	return false;
}
int main(){
	
	vector<int> arr;
	arr.push_back(84);
	arr.push_back(23);
	arr.push_back(45);
	arr.push_back(12);
	arr.push_back(56);
	arr.push_back(82);
	if(check(arr,3)){
		cout<<"True";
	}else{
		cout<<"False";
	}
}
