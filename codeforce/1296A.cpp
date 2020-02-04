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
		int n,a[N];
		bool odd=false,even=false;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> a[i];
			if(a[i]%2==1)
				odd=true;
			else
				even=true;
		}
 
		if(n%2==1){
			if(odd)
				cout << "YES";
			else
				cout << "NO";
		}
		else{
			if(odd&&even)
				cout << "YES";
			else
				cout << "NO";
		}
		cout << endl;
	}
 
	return 0;
}
