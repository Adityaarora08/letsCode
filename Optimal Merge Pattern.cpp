#include<bits/stdc++.h>
using namespace std;
int optimalMergePattern(vector<int> files){
	priority_queue<int, vector<int>, greater<int> > minHeap;
	for(int i=0;i<files.size();i++){
		minHeap.push(files[i]);
	}
	int currSum=0;
	while(minHeap.size()>1){
		int e1=minHeap.top();
		minHeap.pop();
		int e2=minHeap.top();
		minHeap.pop();
		currSum+= e1+e2;
		minHeap.push(e1+e2);
	}
	return currSum;
}
int main(){
	vector<int> files;
	files.push_back(5);
	files.push_back(2);
	files.push_back(4);
	files.push_back(7);
	files.push_back(8);
	cout<<"Minimum Merge pattern Sum = "<<optimalMergePattern(files);
}
