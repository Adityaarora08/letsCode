#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	sort(arr,arr+n);
	queue<int> q;
	int count_m=0;
	int endarr=n-1;
	 while(m--)
	 {
		int curr_m;
		cin>>curr_m;
		int ans;
		for(;count_m<curr_m;count_m++)
		{
			if(endarr>=0 && (q.empty()||arr[count_m]>=q.front()))
			{
				ans=arr[endarr];
				endarr--;
			}
			else{
				ans=q.front();
				q.pop();
			}
			q.push(ans/2);
		}
		cout<<ans<<endl;
	 }
	return 0;
}
