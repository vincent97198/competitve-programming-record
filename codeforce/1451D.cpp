#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100005;
vector<int> v;

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;	cin >> t;
	while(t--){
		int d,k;	cin >> d >> k;

		int cnt;
		for(cnt=0;cnt*cnt*2<=d*d;cnt+=k);
		if(cnt*cnt+(cnt-k)*(cnt-k)<=d*d)
			cout << "Ashish\n";
		else
			cout << "Utkarsh\n";
	}

}

