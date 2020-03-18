#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

std::mt19937_64 RAND(228922);

int ans[N];

struct node{

  node *l,*r;
  int val,pri,lazy,sz,id,ans_lazy,ans;

  node(int VAL,int ID){
      l=nullptr;   r=nullptr;
      val=VAL;
      sz=1;
      lazy=ans_lazy=ans=0;
      id=ID;
      pri=RAND();
  }
}*root;

int size(node *now)
{
    if(now==nullptr)
        return 0;
    return now->sz;
}

void push(node *now)
{
    if(now==nullptr )
        return ;

    if(now->l!=nullptr){
        now->l->val+=now->lazy;
        now->l->ans_lazy+=now->ans_lazy;
        now->l->ans+=now->ans_lazy;
        now->l->lazy+=now->lazy;
    }
    if(now->r!=nullptr){
        now->r->val+=now->lazy;
        now->r->lazy+=now->lazy;
        now->r->ans_lazy+=now->ans_lazy;
        now->r->ans+=now->ans_lazy;
    }
    now->ans_lazy=0;
    now->lazy=0;
}

void pull(node *now)
{
    if(now==nullptr)
        return ;
    now->sz=size(now->l)+size(now->r)+1;
}

void split(node *now,int k,node *&L,node *&R)
{
    if(now==nullptr){
        L=nullptr,R=nullptr;
        return ;
    }

    push(now);

    if(now->val>=k){
        R=now;
        split(now->l,k,L,R->l);
        pull(R);
    }
    else{
        L=now;
        split(now->r,k,L->r,R);
        pull(L);
    }
}

node *MERGE(node *L,node *R)
{
    if(L==nullptr || R== nullptr)
        return (L==nullptr?R:L);

    if(L->pri>R->pri){
        push(L);
        L->r=MERGE(L->r,R);
        pull(L);
        return L;
    }
    else{
        push(R);
        R->l=MERGE(L,R->l);
        pull(R);
        return R;
    }
}

void insert(int value,int ID)
{
    node *L=nullptr,*R=nullptr;
    split(root,value,L,R);
    node *tmp=new node(value,ID);
    root=MERGE(MERGE(L,tmp),R);
}

struct shirt{
  int c,q,id;
}arr[N];

bool cmp(shirt a,shirt b)
{
    if(a.q==b.q)
        return a.c<b.c;

    return a.q>b.q;
}

int n,k;

void init()
{
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> arr[i].c >> arr[i].q;
        arr[i].id=i;
    }

    cin >> k;
    int b;
    for(int i=0;i<k;++i){
        cin >> b;
        insert(b,i);
    }

    sort(arr,arr+n,cmp);
}

void travel(node *now)
{
    if(now==nullptr)
        return ;
    push(now);
    travel(now->l);
    ans[now->id]=now->ans;
    travel(now->r);
}

void magic_merge(node *&target,node *from)
{
    if(from==nullptr)   return ;

    push(from);
    node *L=from->l,*R=from->r;
    from->l=from->r=nullptr;

    magic_merge(target,L);
    node *l,*r;
    split(target,from->val,l,r);
    target=MERGE(MERGE(l,from),r);
    magic_merge(target,R);
}

void solve()
{
    for(int i=0;i<n;++i){
        node *L=nullptr,*R=nullptr,*tmp=nullptr;
        split(root,arr[i].c,L,R);
        if(R!=nullptr){
            R->val-=arr[i].c;   R->lazy-=arr[i].c;
            ++R->ans;   ++R->ans_lazy;
        }
        split(R,arr[i].c,tmp,R);
        magic_merge(L,tmp);
        root=MERGE(L,R);
    }
    travel(root);

    for(int i=0;i<k;++i)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}
