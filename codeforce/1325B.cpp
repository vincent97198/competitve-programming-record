#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,tmp,ans;
		cin >> n;
		ans=n;
		set<int> s;
		for(int i=0;i<n;++i){
			cin >> tmp;
			if(s.find(tmp)!=s.end())
				--ans;
			s.insert(tmp);
		}
		cout << ans << endl;
	}
	return 0;
}
