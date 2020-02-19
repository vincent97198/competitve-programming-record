#include <iostream>
#define ll long long
#define N 1005

using namespace std;

int n,m,arr[N][N],seg[4*N][4*N],x1,y1,x2,y2;

void merge(int l,int r,int L,int R,int id1,int id2)
{
	if(L>R)
		return ;
	if(L==R){
		seg[id1][id2]=max(seg[id1*2][id2],seg[id1*2+1][id2]);
		return ;
	}
	int mid=(L+R)/2;
	merge(l,r,L,mid,id1,id2*2);
	merge(l,r,mid+1,R,id1,id2*2+1);
	seg[id1][id2]=max(seg[id1][id2*2],seg[id1][id2*2+1]);
}

void build1D(int l,int L,int R,int id1,int id2)
{
	if(L>R)
		return ;
	if(L==R){
		seg[id1][id2]=arr[l][L];
		return ;
	}
	int mid=(L+R)/2;
	build1D(l,L,mid,id1,id2*2);
	build1D(l,mid+1,R,id1,id2*2+1);
	seg[id1][id2]=max(seg[id1][id2*2],seg[id1][id2*2+1]);
}

void build2D(int l,int r,int L,int R,int id1,int id2)
{
	if(l>r)
		return ;
	if(l==r){
		build1D(l,L,R,id1,id2);
		return ;
	}

	int mid=(l+r)/2;
	build2D(l,mid,L,R,id1*2,id2);
	build2D(mid+1,r,L,R,id1*2+1,id2);
	merge(l,r,L,R,id1,id2);
}

int query1D(int L,int R,int id1,int id2)
{
	if(L>R || L>y2 || R<y1)
		return 0;
	if(L>=y1 && R<=y2)
		return seg[id1][id2];

	int mid=(L+R)/2;
	return max(query1D(L,mid,id1,id2*2),query1D(mid+1,R,id1,id2*2+1));
}

int query2D(int l,int r,int L,int R,int id1,int id2)
{
	if(l>r || l>x2 || r<x1)
		return 0;
	if(l>=x1 && r<=x2)
		return query1D(L,R,id1,id2);

	int mid=(l+r)/2;
	return max(query2D(l,mid,L,R,id1*2,id2),query2D(mid+1,r,L,R,id1*2+1,id2));
}

void init()
{
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin >> arr[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	init();

	build2D(1,n,1,m,1,1);

	int q;
	cin >> q;
	while(q--){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << query2D(1,n,1,m,1,1) << endl;
	}

	return 0;
}

