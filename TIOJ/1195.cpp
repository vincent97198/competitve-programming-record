#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;
	ll ans=0;
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		if(s[2]==s[3] && s[3]==s[4] && s[4]==s[5])
			ans+=2000;
		else if(s[2]==s[3] && s[4]==s[5])
			ans+=1500;
		else
			ans+=1000;
	}
	cout << ans << endl;

	return 0;
}
