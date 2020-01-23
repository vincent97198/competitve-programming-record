#include<bits/stdc++.h>
#define N 100005

using namespace std;

struct node{

	int pri,sz,val;
	bool re;

	node *l,*r;

	node()=default;
	node(int value){
		val=value;
		pri=rand();
		sz=1;
	}
}*root;

int size(node *now)
{
	if(now==nullptr)
		return 0;
	else
		return now->sz;
}

void pull(node *now)
{
	if(now==nullptr)
		return;
	now->sz=1;
	if(now->l)	now->sz+=now->l->sz;
	if(now->r)	now->sz+=now->r->sz;
}

void push(node *now)
{
	if(now==nullptr)
		return;
	if(!now->re)	return;
	
	swap(now->l,now->r);
	if(now->l)	now->l->re^=true;
	if(now->r)	now->r->re^=true;
	now->re=false;
}

void split(node *t,int k,node *&L,node *&R)
{
	if(t==nullptr){
		L=nullptr;
		R=nullptr;
		return;
	}
	push(t);
	if(size(t->l)>=k){
		R=t;
		split(t->l,k,L,R->l);
		pull(R);
	}
	else{
		L=t;
		split(t->r,k-size(t->l)-1,L->r,R);
		pull(L);
	}
}

node *merge(node *L,node *R)
{
	if(L==nullptr || R==nullptr)
		return (L==nullptr)?R:L;
	if( L->pri > R->pri ){
		push(L);
		L->r=merge(L->r,R);
		pull(L);
		return L;
	}
	else{
		push(R);
		R->l=merge(L,R->l);
		pull(R);
		return R;
	}
}

void insert(int value)
{
	node *L,*R,*now;
	now=new node(value);
	split(root,value,L,R);
	root=merge(merge(L,now),R);
}

void reverse(int l,int r)
{
	node *L,*R;
	split(root,l-1,L,root);
	split(root,r-l+1,root,R);
	root->re^=true;
	root=merge(merge(L,root),R);
}

void print(node *now)
{
	if(now==nullptr)
		return;
	if(now->re)
		push(now);

	print(now->l);
	cout << now->val << " ";
	print(now->r);
}

int main()
{
	int n,m;
	cin >> n >> m;

	for(int i=1;i<=n;++i)
		insert(i);

	int l,r;
	for(int i=0;i<m;++i){
		cin >> l >> r;
		reverse(l,r);
	}

	print(root);

	return 0;
}
