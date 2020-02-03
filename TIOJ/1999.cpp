#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int n,m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n >> m;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	
	ll now,cur;
	for(int i=0;i<n;++i){
		cin >> now;
		if(pq.size()<m)
			pq.push(now);
		else{
			cur=pq.top();	pq.pop();
			cur+=now;	pq.push(cur);
		}
	}
	while(pq.size()>1)
		pq.pop();
	cout << pq.top() << endl;


	return 0;
}
