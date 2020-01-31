#include <bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;

vector<int> G[N];
int p[N],c[N];

vector<int> dfs(int now)
{
	vector<int> tmp;
	for(int i=0;i<G[now].size();++i){
		vector<int> tmp2=dfs(G[now][i]);
		tmp.insert(tmp.end(),tmp2.begin(),tmp2.end());
	}
	if(c[now]>tmp.size()){
		cout << "No" << endl;
		exit(0);
	}
	tmp.insert(tmp.begin()+c[now],now);
	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;
	
	for(int i=1;i<=n;++i){
		cin >> p[i] >> c[i];
		G[p[i]].push_back(i);
	}

	vector<int> ans=dfs(G[0][0]);
	int ANS[N];
	for(int i=0;i<ans.size();++i)
		ANS[ans[i]]=i+1;

	cout << "Yes" << endl;
	for(int i=1;i<=n;++i)
		cout << ANS[i] << " ";
	cout << endl;

	return 0;
}
