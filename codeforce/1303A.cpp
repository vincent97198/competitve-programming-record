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
		string s;
		cin >> s;
		int now=0,ans=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0')
				++ans;
		}
		if(ans==s.size()){
			cout << 0 << endl;
			continue;
		}
		for(int i=0;i<s.size();++i){
			if(s[i]!='1')
				--ans;
			else
				break;
		}
		for(int i=s.size()-1;i>=0;--i){
			if(s[i]!='1')
				--ans;
			else
				break;
		}
		cout << ans << endl;
	}

	return 0;
}
