#include <bits/stdc++.h>
#define ll long long
#define N 5005

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll n,x,m,L[105],R[105],ans,LMIN,RMAX;   cin >> n >> x >> m;
        LMIN=x,RMAX=x;
        for(int i=0;i<m;++i){
            cin >> L[i] >> R[i];
            if(L[i]>R[i])
                swap(L[i],R[i]);
            if((R[i]<=RMAX && R[i]>=LMIN)||(L[i]<=RMAX && L[i]>=LMIN) || (R[i]>=RMAX && L[i]<=LMIN)){
                RMAX=max(RMAX,R[i]);
                LMIN=min(LMIN,L[i]);
            }
        }
        cout << RMAX-LMIN+1 << endl;
    }
    return 0;
}
