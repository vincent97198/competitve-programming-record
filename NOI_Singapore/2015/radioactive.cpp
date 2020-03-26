#include <bits/stdc++.h>
#define ll long long
#define N 205

using namespace std;

const unsigned ll MOD=1000000007;
unsigned ll n,c;
vector<unsigned ll> w,tmpw,v,c_vector;

unsigned ll power(ll x,ll POWER)
{
    ll ret=1;
    while(POWER>0){
        if(POWER&1)
            ret=(ret*x)%MOD;

        x=(x*x)%MOD;
        POWER>>=1;
    }
    return ret;
}

vector<unsigned ll> expand(const vector<unsigned ll> &V, const vector<unsigned ll> &w_p){
    vector<unsigned ll> ret((int)(V.size()+w_p.size()-1));
    for(int i=0;i<V.size();++i)
        for(int j=0;j<w_p.size();++j)
            ret[i+j]=(ret[i+j]+(V[i]*w_p[j])%MOD)%MOD;
    return ret;
}

vector<unsigned ll> shrink(vector<unsigned ll> V,const vector<unsigned ll> &c){
    for(int i=0;i+c.size()<V.size();++i)
        for(int j=0;j<c.size();++j)
            V[i+j+1]=(V[i+j+1]+(V[i]*c[j])%MOD)%MOD;
    return vector<unsigned ll>(V.begin()+(V.size()-c.size()),V.end());
}

void init()
{
    for(int i=0;i<=c;++i){
        w.push_back(1);
        c_vector.push_back(1);
        tmpw.push_back(1);
        if(n%(c+1)==(c-i))
            v.push_back(1);
        else
            v.push_back(0);
    }
}

void matrix_power(unsigned ll POWER)
{
    --POWER;
    while(POWER>0){
        if(POWER&1)
            w=shrink(expand(w,tmpw),c_vector);

        POWER>>=1;
        tmpw=shrink(expand(tmpw,tmpw),c_vector);
    }
}

void solve()
{
    init();
    matrix_power(n/(c+1));
}

unsigned ll calc()
{
    v=shrink(expand(v,w),c_vector);
    unsigned ll ret=0;
    for(int i=0;i<=c;++i)
        ret=(ret+(v[i]*power(2,c-i))%MOD)%MOD;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    cin >> n >> c;

    if(n<=c)
        cout << power(2,n) << endl;
    else{
        solve();
        cout << calc() << endl;
    }


    return 0;
}

