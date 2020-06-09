#include <bits/stdc++.h>
#define N 105

using namespace std;

int main()
{
    const int MAXN = (1<<15);
    int bits[MAXN+5];
    bits[0]=0;
    for(int i=1;i<MAXN+5;++i)
        bits[i]=bits[i>>1]+(i&1);

    int n,pre[N],suf[N];
    cin >> n;
    for(int i=0;i<n;++i){
        int tmp;    cin >> tmp;
        pre[i]=tmp/MAXN;
        suf[i]=tmp%MAXN;
    }


    map< vector<int> , int > mp;
    for(int i=0;i<MAXN;++i){
        vector<int> v(n);
        for(int j=0;j<n;++j)
            v[j]=bits[i^suf[j]];
        mp[v]=i;
    }

    for(int i=0;i<MAXN;++i){
        vector<int> v(n);
        for(int j=0;j<n;++j)
            v[j]=-bits[i^pre[j]];
        for(int j=0;j<=30;++j){
            if(mp.find(v)!=mp.end()){
                cout << mp[v]+MAXN*i << endl;
                return 0;
            }
            for(int k=0;k<n;++k)    ++v[k];
        }
    }
    cout << -1 << endl;
    return 0;
}

