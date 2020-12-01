#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 200005;
int ans[N],power[N];

const int MOD = 998244353;

int calc(int x)
{
    return ((x%MOD)+MOD)%MOD;
}

int inv(int x)
{
    int POWER=MOD-2,ret=1;
    while(POWER){
        if(POWER&1)
            ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        POWER>>=1;
    }
    return ret;
}

signed main()
{
    int n;  cin >> n;
    
    int inv2=inv(2),inv4=inv(4);
    /*
    power[0]=1;
    for(int i=1;i<=n;++i)
        power[i]=calc(power[i-1]*inv2);
    */
    ans[0]=1,ans[1]=inv2,ans[2]=inv4;
    for(int num=3;num<=n;++num){
        ans[num]=calc((ans[num-2])*inv4+ans[num-1]*inv2);
    }
    cout << ans[n] << '\n';
    /*
    cout << "power: \n";
    for(int i=0;i<=n;++i)
        cout << i << ": " << power[i] << '\n';
    
    cout << "\n ans: \n";
    for(int i=0;i<=n;++i)
        cout << i << ": " << ans[i] << '\n';
    */
    return 0;
}