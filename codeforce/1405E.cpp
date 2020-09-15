#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=300005;

int n,q,a[N],l[N],ans[N],BIT[N];
vector<int> r[N];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int pos,int val)
{
	for(;pos<N;pos+=lowbit(pos))
		BIT[pos]+=val;
}

int query(int pos)
{
	int ret=0;
	for(;pos>0;pos-=lowbit(pos))
		ret+=BIT[pos];
	return ret;
}

int search(int num,int R)
{
	int ret_pos=0,val=0;
	for(int len=(1<<__lg(N));len>=1;len>>=1){
		if(ret_pos+len<=R && val+BIT[ret_pos+len]<=num){

