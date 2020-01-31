#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		string s,t;
		cin >> s >> t;
		vector<int> v[26];
		for(int i=0;i<s.size();++i)
			v[s[i]-'a'].push_back(i);

		int ans=1,now=0;
		auto pos=v[0].begin();
		bool flag=false;
		for(int i=0;i<t.size();++i){
			if(v[t[i]-'a'].empty()){
				flag=true;
				break;
			}
			pos=lower_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),now);
			if(pos==v[t[i]-'a'].end()){
				++ans;
				now=0;
				--i;
			}
			else{
				now=(*pos)+1;
			}
		}
		if(flag)
			ans=-1;
		cout << ans << endl;
	}

	return 0;
}
