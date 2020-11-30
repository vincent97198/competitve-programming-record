#include "biscuits.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int ans=0;
const int DEP=60;
 
bool dfs(long long sum,long long dep,long long x,vector<long long> a)
{
	if(dep==0 || sum<=0){
		if(sum>=x)	return true;
		else{
			++ans;
			return false;
		}
	}
 
	if(sum>=x*(1LL<<dep)){
		bool flag=dfs(sum-max(x,a[dep])*(1LL<<dep),dep-1,x,a);
		if(flag)	return flag;
	}
	bool flag=dfs(sum-a[dep]*(1LL<<dep),dep-1,x,a);
	if(flag)
		ans+=(1LL<<dep);
	return false;
 
}
 
long long count_tastiness(long long x, std::vector<long long> a)
{
	ans=0;
	while(a.size()!=DEP)	a.push_back(0);
	long long sum=0;
	for(long long i=0;i<a.size();++i)	sum+=a[i]*(1LL<<i);
	if(dfs(sum,DEP-1,x,a))	ans+=(1LL<<DEP);
	return ans;
}