#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t,num[10]={6,2,5,5,4,5,6,3,7,6};
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%2==0){
			for(int i=0;i<n/2;++i)
				cout << 1;
		}
		else{
			cout << 7;
			for(int i=1;i<n/2;++i)
				cout << 1;
		}
		cout << endl;
	}

	return 0;
}
