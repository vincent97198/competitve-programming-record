#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n,a[N];
		cin >> n;
		for(int i=0;i<n;++i)
			cin >> a[i];
		
		int MIN=INT_MAX,MAX=-100;

		for(int i=0;i<n;++i){
			if(a[i]!=-1 && ((i>0 && a[i-1]==-1) || (i<n-1 && a[i+1]==-1))){
				MIN=min(MIN,a[i]);
				MAX=max(MAX,a[i]);
			}
		}

		if(MIN==INT_MAX && MAX==-100)
			cout << 0 << " " << 0;
		else{
			int ans=(MAX+MIN)/2,d=0;
			for(int i=0;i<n-1;++i){
				if(a[i]==-1 && a[i+1]!=-1)
					d=max(d,abs(ans-a[i+1]));
				else if(a[i]!=-1 && a[i+1]!=-1)
					d=max(d,abs(a[i]-a[i+1]));
				else if(a[i]!=-1 && a[i+1]==-1)
					d=max(d,abs(a[i]-ans));
			}
			cout << d << " " << ans;
		}

		cout << endl;
	}

	return 0;
}

