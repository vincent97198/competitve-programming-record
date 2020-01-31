#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

ll segment[4*N],lazy[4*N];

void pushdown(int id,int L,int R)
{
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	segment[id*2]+=lazy[id];
	segment[id*2+1]+=lazy[id];
	lazy[id]=0;
}

void add(int l,int r,int L,int R,ll val,int id)
{
	if(l>r || L>=r || R<=l)
		return;

	if(L>=l && R<=r){
		segment[id]+=(val);
		lazy[id]+=val;
		return;
	}
	if(lazy[id]!=0)
		pushdown(id,L,R);

	int mid=(L+R)/2;

	add(l,r,L,mid,val,id*2);
	add(l,r,mid,R,val,id*2+1);
	segment[id]=min(segment[id*2],segment[id*2+1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n,num[N],penalty[N];
	cin >> n;

	for(int i=0;i<n;++i)
		cin >> num[i];
	for(int i=0;i<n;++i)
		cin >> penalty[i];

	for(int i=0;i<n;++i)
		add(num[i],n+1,0,n+1,penalty[i],1);

	ll ans=1e18;
	for(int i=0;i<n-1;++i){
		add(num[i],n+1,0,n+1,-penalty[i],1);
		add(0,num[i],0,n+1,penalty[i],1);
		ans=min(ans,segment[1]);
	}
	cout << ans << endl;

	return 0;
}

