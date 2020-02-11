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
		vector<int> v;
		int tmp;
		for(int i=0;i<2*n;++i){
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end());
		cout << v[n]-v[n-1] << endl;
	}

	return 0;
}
