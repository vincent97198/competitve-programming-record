#include <bits/stdc++.h>
#define N 1005
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,root,deg[N],u,v;
		cin >> n >> root;
		memset(deg,0,sizeof(deg));
		for(int i=1;i<n;++i){
			cin >> u >> v;
			++deg[u],++deg[v];
		}
		if(deg[root]<=1)
			cout << "Ayush";
		else{
			if(n&1)
				cout << "Ashish";
			else
				cout << "Ayush";
		}
		cout << '\n';
	}
}
