#include <bits/stdc++.h>
#include "shoes.h"
#define N 100005

using namespace std;

long long BIT[2*N];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int pos,long long val)
{
	for(;pos<2*N;pos+=lowbit(pos))
		BIT[pos]+=val;
}

long long sum(int pos)
{
	int ret=0;
	for(;pos>0;pos-=lowbit(pos))
		ret+=BIT[pos];
	return ret;
}

long long count_swaps(vector<int> S)
{
	map<long long,queue<int>> mp;
	
	long long ans=0;
	S.insert(S.begin(),0);
	for(int i=1;i<=S.size();++i){
		mp[S[i]].push(i);
		add(i,1);
	}
	for(int i=0;i<S.size();++i){
		if(mp[S[i]].empty() || mp[S[i]].front()!=i)	continue;
		mp[S[i]].pop();
		int t=mp[-S[i]].front();	mp[-S[i]].pop();
		if(S[i]>0)
			++ans;
		ans+=(sum(t-1)-sum(i));
		add(t,-1);
	}
	return ans;
}

