#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

int arr[5001*5001];
ll x,a,b,c,d,n,m,q;
int T[5001*5001],L[5001],R[5001];

ll calc(ll X)
{
    x=(a*X*X+b*X+c)%d;
    return x;
}

void init()
{
    cin >> x >> a >> b >> c >> d;
    cin >> n >> m >> q;
    for(int i=1;i<=n*m;++i)
        T[i]=i;
    for(int i=1;i<=n*m;++i)
        swap(T[i],T[(calc(x)%i)+1]);
    int u,v;
    while(q--){
        cin >> u >> v;
        swap(T[u],T[v]);
    }
/*
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cout << T[(i-1)*m+j] << " ";
        cout << endl;
    }
    */
    for(int i=1;i<=n*m;++i)
        arr[T[i]]=i;

    for(int i=0;i<5001;++i)
        L[i]=0,R[i]=5005;
}

void solve()
{
    int now=1,t=0;
    while(now<=n*m){
        int x=arr[now]/m+1,y=arr[now]%m;
        if(y==0)
            --x,y+=m;

        if(y>=L[x] && y<=R[x]){
            cout << now << " ";
            if(++t==n+m-1)
                break;
            for(int i=1;i<x;++i)
                R[i]=min(R[i],y);
            for(int i=x+1;i<=n;++i)
                L[i]=max(L[i],y);
        }
        ++now;
    }
}

int main()
{
    //freopen("random.txt","r",stdin);
    //freopen("random.out","w",stdout);
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );

    init();
    solve();

    return 0;
}
