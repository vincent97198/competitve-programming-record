#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

ll n,b[N],num[N];
map<ll,ll> MAP;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> b[i];
        MAP[i-b[i]]+=b[i];
    }

    ll MAX=0;
    for(auto iter=MAP.begin();iter!=MAP.end();++iter)
        MAX=max(MAX,iter->second);

    cout << MAX << endl;
    return 0;
}

