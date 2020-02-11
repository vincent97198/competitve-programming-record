#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;
	int a[N],m[35];
	memset(m,0,sizeof(m));
	for(int i=0;i<n;++i){
		cin >> a[i];
		int tmp=a[i],id=0;
		while(tmp>0){
			if(tmp&1)
				++m[id];
			tmp>>=1;
			++id;
		}
	}

	int sa=-1;
	for(int i=35;i>=0;--i){
		if(m[i]==1){
			sa=i;
			break;
		}
	}

	int MA=a[0];
	for(int i=0;i<n;++i){
		int tmp=a[i],id=0;
		while(tmp>0){
			if(tmp&1 && id==sa)
				MA=a[i];
			tmp>>=1;
			++id;
		}
	}
	cout << MA << " ";
	bool flag=false;
	for(int i=0;i<n;++i){
		if(a[i]==MA && !flag)
			flag=true;
		else
			cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
