#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int num[N];
	int t;	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		string s;	cin >> s;
		int sum=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0')	++sum;
			else	--sum;
		}
		if(sum!=0){
			int ans=0,now=0;
			for(int i=0;i<s.size();++i){
				if((x-now)%sum==0 && (x-now)*(ll)sum>=0)
					++ans;
				if(s[i]=='0')
					++now;
				else
					--now;
			}
			cout << ans;
		}
		else{
			int now=0;
			bool flag=false;
			for(int i=0;i<s.size();++i){
				if(now==x){
					flag=true;
					break;
				}
				if(s[i]=='0')
					++now;
				else
					--now;
			}
			if(flag)
				cout << -1;
			else
				cout << 0;
		}
		cout << endl;
	}

	return 0;
}
