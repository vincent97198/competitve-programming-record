#include <bits/stdc++.h>
#define N 200005

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n,tmp,ans=N;
		map<int,int> mp;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> tmp;
			if(mp.find(tmp)!=mp.end())
				ans=min(ans,i-mp[tmp]+1);
			mp[tmp]=i;
		}
		cout << ((ans==N)?-1:ans) << endl;
	}
	return 0;
}
