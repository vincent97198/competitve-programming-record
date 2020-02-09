#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 500005

using namespace std;

int n;
ll X[N],k,x,y,BF;

ll power(ll xx,ll POWER,ll MOD)
{
    ll ret=1;
    while(POWER>0){
        if(POWER&1)
            ret=(ret*xx)%MOD;
        xx=(xx*xx)%MOD;
        POWER>>=1;
    }
    return ret%MOD;
}

void exgcd(ll a,ll b)
{
    if(b==0){
        x=1;
        y=0;
        return ;
    }

    exgcd(b,a%b);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
}

ll gcd(ll a,ll b)
{
    return (b==0)?a:gcd(b,a%b);
}

void init()
{
    for(int i=0;i<n;++i)
        cin >> X[i];
    cin >> k;
}

ll dfs(ll now,ll MOD)
{
    if(now>=BF)
        return X[now]%MOD;

    ll nextMOD=MOD,tmp=MOD;
    for(ll i=2;i*i<=MOD;++i){
        if(tmp%i==0)
            nextMOD=nextMOD/i*(i-1);
        while(tmp%i==0){
            tmp/=i;
        }
    }
    if(tmp!=1)
        nextMOD=nextMOD/tmp*(tmp-1);

    ll GCD=gcd(MOD,X[now]);
    ll nextPOWER=dfs(now+1,nextMOD);
    if(GCD==1)
        return power(X[now],nextPOWER,MOD);

    nextMOD=MOD;
    for(int i=2;i*i<=MOD;++i){
        while(nextMOD%i==0 && X[now]%i==0){
            nextMOD/=i;
        }
    }

    tmp=power(X[now],nextPOWER,MOD);

    ll ans;
    if(now+1<BF || X[now+1]>1000000){
        exgcd(MOD/nextMOD,nextMOD);
        ans=(((MOD/nextMOD*x)%MOD)*tmp)%MOD;
    }
    else{
        ans=power(X[now],X[now+1],MOD);
    }
    ans=((ans%MOD)+MOD)%MOD;

    return ans;
}

ll POWER2(ll xx,ll power)
{
    ll ret=1;
    while(power>0){
        if(xx>=((ll)1<<32) || ret>=((ll)1<<32))
            return -1;
        if(power&1)
            ret*=xx;
        xx=xx*xx;
        power>>=1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    while(cin >> n && n!=0){
        init();
        BF=-1;
        ll onePROBLEM=n-2;
        for(int i=0;i<n;++i){
            if(X[i]==1){
                onePROBLEM=i;
                break;
            }
        }
        for(int i=onePROBLEM;i>=0;--i){
            ll tmp=POWER2(X[i],X[i+1]);
            if(tmp==-1){
                BF=i+1;
                break;
            }
            else
                X[i]=tmp;
        }

        cout << dfs(0,k) << endl;
        cout << flush;
    }

    return 0;
}

