#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int n,m,arr[N];
string s;

void init()
{
    cin >> n >> m >> s;
    for(int i=0;i<m;++i)
        cin >> arr[i];
    sort(arr,arr+m);
}

void solve()
{
    ll ans[26],basic[26];
    memset(ans,0,sizeof(ans));
    memset(basic,0,sizeof(basic));
    int p=0;
    for(int i=0;i<n;++i){
        ++basic[s[i]-'a'];
        while(arr[p]==i+1 && p<m){
            ++p;
            for(int j=0;j<26;++j)
                ans[j]+=basic[j];
        }
    }
    for(int j=0;j<26;++j)
        ans[j]+=basic[j];

    for(int i=0;i<26;++i)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        init();
        solve();
    }

    return 0;
}

