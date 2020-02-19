#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

struct pos{
	int y,z,id;
};

int ans[N],BIT[N];
vector<vector<pos>> p;

inline int lowbit(int x)
{
	return x&(-x);
}

bool cmp(pos a,pos b)
{
	if(a.y==b.y)
		return a.z<b.z;
	else
		return a.y<b.y;
}

void add(int POS,int val)
{
	for(;POS<N;POS+=lowbit(POS))
		BIT[POS]+=val;
}

int query(int POS)
{
	int ret=0;
	for(;POS>0;POS-=lowbit(POS))
		ret+=BIT[POS];
	return ret;
}

void solve(int l,int r)
{
	if(r-l==1)
		return ;
	int mid=(l+r)/2;
	solve(l,mid);	solve(mid,r);
	
	vector<pos> L,R;
	for(int i=l;i<mid;++i)
		for(int j=0;j<p[i].size();++j)
			L.push_back(p[i][j]);
	for(int i=mid;i<r;++i)
		for(int j=0;j<p[i].size();++j)
			R.push_back(p[i][j]);

	sort(L.begin(),L.end(),cmp);
	sort(R.begin(),R.end(),cmp);

	int index=0;
	for(int i=0;i<R.size();++i){
		while(index<L.size() && R[i].y>L[index].y)
			add(L[index++].z,1);
		ans[R[i].id]+=query(R[i].z-1);
	}
	for(int i=0;i<index;++i)
		add(L[i].z,-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n,x,y,z;
	cin >> n;
	p.resize(n+5);

	for(int i=0;i<n;++i){
		cin >> x >> y >> z;
		p[n-x].push_back(pos{n-y+1,n-z+1,i});
	}

	solve(0,n);

	for(int i=0;i<n;++i)
		cout << ans[i] << endl;

	return 0;
}
