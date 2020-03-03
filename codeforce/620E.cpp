#include <bits/stdc++.h>
#define ll long long
#define N 400005

using namespace std;

struct item{
  int l,r;
};

const int ROOT=1;
item dfs_order[N];
int n,m,color[N],cnt=1,re[N];
ll seg[4*N],lazy[4*N];
vector<int> G[N];

void dfs(int now,int p)
{
    dfs_order[now].l=cnt;   re[cnt++]=now;
    for(auto next:G[now]){
        if(next!=p)
            dfs(next,now);
    }
    dfs_order[now].r=cnt-1;
}

void build(int l,int r,int id)
{
    if(l==r){
        seg[id]=1ll<<color[re[l]];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    seg[id]=seg[id*2]|seg[id*2+1];
}

void push(int id)
{
    lazy[id*2]=lazy[id];
    lazy[id*2+1]=lazy[id];
    seg[id*2]=lazy[id];
    seg[id*2+1]=lazy[id];
    lazy[id]=0;
}

void update(int l,int r,int L,int R,int id,int val)
{
    if(L>r || l>R)
        return ;

    if(l<=L && r>=R){
        seg[id]=1ll<<val;
        lazy[id]=1ll<<val;
        return ;
    }
    if(lazy[id]!=0)
        push(id);
    int mid=(L+R)/2;
    update(l,r,L,mid,id*2,val);
    update(l,r,mid+1,R,id*2+1,val);
    seg[id]=seg[id*2]|seg[id*2+1];
}

void init()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i)
        cin >> color[i];

    int a,b;
    for(int i=0;i<n-1;++i){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(ROOT,-1);
    build(1,n,1);
}

ll query(int l,int r,int L,int R,int id)
{
    if(L>r || l>R)
        return 0;
    if(l<=L && r>=R)
        return seg[id];

    if(lazy[id]!=0)
        push(id);
    int mid=(L+R)/2;
    return query(l,r,L,mid,id*2)|query(l,r,mid+1,R,id*2+1);
}

void solve()
{
    int type;
    while(m--){
        cin >> type;
        if(type==1){
            int v,c;
            cin >> v >> c;
            update(dfs_order[v].l,dfs_order[v].r,1,n,1,c);
        }
        else{
            int v;
            cin >> v;
            ll ans=query(dfs_order[v].l,dfs_order[v].r,1,n,1);
            int ANS=0;
            while(ans){
                if(ans&1)
                    ++ANS;
                ans>>=1;
            }
            cout << ANS << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}

