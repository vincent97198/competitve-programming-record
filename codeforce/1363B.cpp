#include <bits/stdc++.h>
#define N 1005

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int one=0,zero=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0')
				++zero;
			else
				++one;
		}

		int ans=min(one,zero),ONE=0,ZERO=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0')
				++ZERO,--zero;
			else
				++ONE,--one;
			ans=min(min(ans,ONE+zero),ZERO+one);
		}
		cout << ans << endl;
	}

	return 0;
}
