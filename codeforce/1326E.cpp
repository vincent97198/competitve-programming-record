#include <bits/stdc++.h>
#define ll long long
#define N 300005

using namespace std;

int n,seg[4*N],p[N],lazy[4*N],re[N];

void push(int id,int L,int R)
{
    if(lazy[id]==0) return ;
    lazy[id*2]+=lazy[id];
    lazy[id*2+1]+=lazy[id];
    int mid=(L+R)/2;
    seg[id*2]+=lazy[id];
    seg[id*2+1]+=lazy[id];
    lazy[id]=0;
}

void add(int id,int L,int R,int l,int r,int val)
{
    if(R<l || L>r)  return ;
    if(r>=R && l<=L){
        lazy[id]+=val;
        seg[id]+=val;
        return ;
    }
    push(id,L,R);
    int mid=(L+R)/2;
    add(id*2,L,mid,l,r,val);
    add(id*2+1,mid+1,R,l,r,val);
    seg[id]=min(seg[id*2],seg[id*2+1]);
}

int query(int id,int L,int R,int l,int r)
{
    if(R<l || L>r) return 0;
    if(r>=R  && l<=L)
        return seg[id];
    push(id,L,R);
    int mid=(L+R)/2;
    return min(query(id*2,L,mid,l,r),query(id*2+1,mid+1,R,l,r));
}

void init()
{
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> p[i];
        re[p[i]]=i;
    }
}

bool check(int now)
{
    add(1,1,n,1,re[now],-1);
    if(query(1,1,n,1,re[now])>=0)
        return true;
    else
        add(1,1,n,1,re[now],1);
    return false;
}

void solve()
{
    int q,ans=n;
    for(int i=0;i<n;++i){
        while(check(ans))   --ans;
        cout << ans << endl;
        cin >> q;
        add(1,1,n,1,q,1);
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );

    init();
    solve();

    return 0;
}
