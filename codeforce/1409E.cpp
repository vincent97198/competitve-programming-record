#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=200050;

int n,k,cnt,dp[N],sufMAX[N];
pair<int,int> arr[N];
map<int,int> mp;

void init()
{
    mp.clear();
    cin >> n >> k;
	for(int i=0;i<=n;++i)	dp[i]=0,arr[i].first=0,arr[i].second=0,sufMAX[i]=0;
    for(int i=0;i<n;++i){
		int tmp;   cin >> tmp;
		++mp[tmp];
    }
	for(int i=0;i<n;++i){
		int tmp;   cin >> tmp;
	}
    cnt=0;
    auto END=mp.begin();
    int num=0;
    for(auto iter=mp.begin();iter!=mp.end();++iter){
        while(END!=mp.end() && iter->first+k>=END->first){
            num+=END->second;
            ++END;
        }
		arr[cnt].first=iter->first;
        arr[cnt++].second=num;
		num-=iter->second;
    }
	sufMAX[cnt-1]=arr[cnt-1].second;
    for(int i=cnt-2;i>=0;--i)   sufMAX[i]=max(sufMAX[i+1],arr[i].second);
}

void solve()
{
	int B=0,ans=0;
    for(int i=0;i<cnt;++i){
		while(B<cnt && arr[B].first<=arr[i].first+k)
			++B;
		ans=max(ans,sufMAX[B]+arr[i].second);
    }
	cout << ans << endl;
}

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;  cin >> t;
    while(t--){
        init();
        solve();
    }
}
