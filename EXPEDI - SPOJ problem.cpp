#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector< pair<int,int> > stops;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		stops.push_back(make_pair(a,b));
	}
//	for(int i=0;i<n;i++){
//		cout<<stops[i].first<<" "<<stops[i].second<<endl;;
//	}
	int fuel,end;
	cin>>end>>fuel;
	int start=0;
	vector< pair<int,int> > orderedStops;
	for(int i=0;i<n;i++){
		orderedStops.push_back(make_pair(end-stops[i].first,stops[i].second));
	}
	sort(orderedStops.begin(),orderedStops.end());
	priority_queue<int,vector<int> > maxHeap; 
	int i=0;
	int count=0;
	while(end>0){
		maxHeap.push(orderedStops[i].second);
		fuel -= orderedStops[i].first;
		if(fuel<=0){
			fuel += maxHeap.top();
			maxHeap.pop();
			count++;
		}
		end -= orderedStops[i].first+start;
		start = orderedStops[i].first;	
		i++;
	}
	cout<<"Min No. of Stops : "<<count;
}
