#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define endl '\n'
#define N 200005

using namespace std;

struct Node{
	int l=-1,r=-1,Lans,Rans,ans;
};

int n,q,c,color[N],root[3*N],cur=0,calc=0;
map<int,int> colorTransform;
Node node[100*N];

inline void pull(Node &a,int lsize,int rsize)
{
	int L=a.l,R=a.r;
	if(L!=-1 && R!=-1){
		a.ans=max( node[L].Rans+node[R].Lans , max(node[L].ans,node[R].ans) );

		if(node[L].Lans==lsize)
			a.Lans=lsize+node[R].Lans;
		else
			a.Lans=node[L].Lans;

		if(node[R].Rans==rsize)
			a.Rans=node[L].Rans+rsize;
		else
			a.Rans=node[R].Rans;
	}
	else if(L!=-1){
		a.ans=max(node[L].ans,rsize+node[L].Rans);

		if(node[L].Lans==lsize)
			a.Lans=lsize+rsize;
		else
			a.Lans=node[L].Lans;

		a.Rans=rsize+node[L].Rans;
	}
	else if(R!=-1){
		a.ans=max(node[R].ans,lsize+node[R].Lans);
		
		a.Lans=lsize+node[R].Lans;

		if(node[R].Rans==rsize)
			a.Rans=lsize+rsize;
		else
			a.Rans=node[R].Rans;
	}
	else{
		a.Lans=a.Rans=a.ans=lsize+rsize;
	}
}

inline void update(int &now,int l,int r,int pos,int val)
{
	if(now==-1)
		now=cur++;

	if(l==r){
		node[now].ans=node[now].Lans=node[now].Rans=val;
		return ;
	}

	int mid=(l+r)>>1;
	if(pos<=mid)
		update(node[now].l,l,mid,pos,val);
	else
		update(node[now].r,mid+1,r,pos,val);

	pull(node[now],mid-l+1,r-mid);
}

inline Node query(int l,int r,int L,int R,int now)	//return Lans,Rans,ans
{
	if(l<=L && r>=R){
		if(now==-1)
			return Node{-1,-1,R-L+1,R-L+1,R-L+1};
		else
			return node[now];
	}

	int mid=(L+R)>>1;
	Node RETURN,RETURN2,RETURN3;
	
	if(mid>=l)
		RETURN=query(l,r,L,mid, (now==-1?-1:node[now].l) );

	if(r>=mid+1){
		RETURN2=query(l,r,mid+1,R, (now==-1?-1:node[now].r) );

		if(l>mid)
			return RETURN2;
		else{
			RETURN3.ans=max( max(RETURN.ans,RETURN2.ans) , RETURN.Rans+RETURN2.Lans );
			if(RETURN.Lans==mid-L+1)
				RETURN3.Lans=mid-L+1+RETURN2.Lans;
			else
				RETURN3.Lans=RETURN.Lans;

			if(RETURN2.Rans==R-mid)
				RETURN3.Rans=R-mid+RETURN.Rans;
			else
				RETURN3.Rans=RETURN2.Rans;

			return RETURN3;
		}
	}
	else
		return RETURN;

}

inline void init()
{
	cin >> n >> q >> c;
	memset(root,-1,sizeof(root));
	for(int i=0;i<n;++i){
		cin >> color[i];
		if( colorTransform.find(color[i])==colorTransform.end() )
			colorTransform[color[i]]=calc++;
		update(root[colorTransform[color[i]]],0,n-1,i,0);
	}
}

inline void solve()
{
	int l,r,type,pos,Color;
	while(q--){
		cin >> type;

		if(type==0){
			cin >> pos >> Color;
			if(colorTransform.find(Color)==colorTransform.end())
				colorTransform[Color]=calc++;
			update(root[colorTransform[color[pos]]],0,n-1,pos,1);
			color[pos]=Color;
			update(root[colorTransform[Color]],0,n-1,pos,0);
		}
		else{
			cin >> l >> r >> Color;
			--r;

			if(colorTransform.find(Color)==colorTransform.end())
				cout << r-l+1 << endl;
			else 		
				cout << query(l,r,0,n-1,root[colorTransform[Color]]).ans << endl;
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

/*
	10 6 4
	1 2 3 0 1 3 4 2 6 5  
	1 1 10 3
	0 9 10
	0 8 6
	1 0 10 10
	0 3 6
	1 1 9 6

 */
