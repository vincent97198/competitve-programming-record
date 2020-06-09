#include <bits/stdc++.h>
#define N 100005

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,a[N];
		cin >> n;
		for(int i=0;i<n;++i)
			cin >> a[i];
		
		int pre=0,ed=n-1;
		for(int i=0;i<n;++i){
			int tmp;	cin >> tmp;
			a[i]-=tmp;
		}
		for(int i=0;i<n;++i){
			if(a[i]!=0){
				pre=i;
				break;
			}
		}
		for(int i=n-1;i>=0;--i){
			if(a[i]!=0){
				ed=i;
				break;
			}
		}
		if(pre==ed){
			if(a[pre]>0)
				cout << "NO";
			else
				cout << "YES";
			cout << endl;
			continue;
		}
		bool flag=true;
		for(int i=pre;i<ed;++i){
			if(a[i]!=a[i+1] || a[i]>0){
				flag=false;
				break;
			}
		}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
