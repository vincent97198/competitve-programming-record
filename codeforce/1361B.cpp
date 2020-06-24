#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

const ll MOD = 1000000007;

ll power(ll x,ll POWER)
{
    ll ret=1;
    while(POWER){
        if(POWER&1)
            ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        POWER>>=1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        ll n,p; cin >> n >> p;
        ll arr[N];
        for(int i=0;i<n;++i)    cin >> arr[i];
        sort(arr,arr+n);    reverse(arr,arr+n);

        ll diff_result=0,cur=0,preExp=1e6+10,cnt=0;
        bool infinity=false;
        for(int i=0;i<n;++i){
            ll delta=preExp-arr[i];
            preExp=arr[i];

            diff_result=(diff_result*power(p,delta))%MOD;
            for(int j=0;j<min(delta,20LL);++j){
                cur*=p;
                if(cur>1e9) infinity=true;
            }

            while(cnt<n && arr[cnt]==arr[i]){
                ++cnt;
                if(infinity || cur>0){
                    --cur;
                    diff_result+=MOD-1;
                }
                else{
                    ++cur;
                    ++diff_result;
                }
                diff_result%=MOD;
            }
        }
        diff_result=(diff_result*power(p,preExp))%MOD;

        cout << diff_result << endl;
    }

    return 0;
}
