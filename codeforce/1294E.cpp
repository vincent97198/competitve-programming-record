#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int n,m;
vector<int> arr[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n >> m;
	int TMP;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> TMP;
			arr[i].push_back(TMP);
		}
	}

	int ans=0,cnt[N];
	for(int j=0;j<m;++j){

		for(int i=0;i<n;++i)	//用memset會TLE while n=1,m=200000
			cnt[i]=0;

		for(int i=0;i<n;++i){
			if( (arr[i][j]%m) == ((j+1)%m) ){
				int pos=( arr[i][j]-(j+1) )/m;
				if(pos<n)
					++cnt[(i-pos+n)%n];
			}
		}
		int tmp=1e8;
		for(int i=0;i<n;++i){
			tmp=min(tmp,n-cnt[i]+i);
		}
		ans+=tmp;
	}
	
	cout << ans << endl;

	return 0;
}
