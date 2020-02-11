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
		int n;
		cin >> n;
		int sum=0,tmp,ans=0;
		for(int i=0;i<n;++i){
			cin >> tmp;
			if(tmp==0){
				++ans;
				++tmp;
			}
			sum+=tmp;
		}
		if(sum==0)
			++ans;
		cout << ans << endl;
	}

	return 0;
}
