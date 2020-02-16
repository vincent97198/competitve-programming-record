#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 1000005

using namespace std;

int n,seg[4*N],num[N];

void build(int l,int r,int id)
{
	if(l==r){
		seg[id]=num[l];
		return ;
	}
	int mid=(l+r)/2;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	seg[id]=min(seg[id*2],seg[id*2+1]);
}

int query(int l,int r,int L,int R,int id)
{
	if(L>r || R<l)
		return INT_MAX;
	
	if(L<=l && R>=r)
		return seg[id];

	int mid=(l+r)/2;

	return min(query(l,mid,L,R,id*2),query(mid+1,r,L,R,id*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> num[i];
	
	build(1,n,1);

	int L,R;
	for(int i=0;i<n;++i){
		cin >> L >> R;
		cout << query(1,n,L,R,1)+1 << endl;
	}

	return 0;
}
