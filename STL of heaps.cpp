#include<bits/stdc++.h>
using namespace std;
int main(){
	//max heap- root is greater than all sub-elements
	priority_queue<int,vector<int> > pq;
	pq.push(1);
	pq.push(5);
	pq.push(2);
	cout<<pq.top()<<endl;
	
	//min heap- root is smaller than all other sub-emelents
	priority_queue<int,vector<int>, greater<int> > pqg;
	pqg.push(1);
	pqg.push(5);
	pqg.push(2);
	cout<<pqg.top()<<endl;
}
