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
		string a,b,c;
		bool flag=true;
		cin >> a >> b >> c;
		for(int i=0;i<a.size();++i){
			if(!(a[i]==c[i] || b[i]==c[i])){
				cout << "NO";
				flag=false;
				break;
			}
		}
		if(flag)
			cout << "YES";
		cout << endl;
	}

	return 0;
}
