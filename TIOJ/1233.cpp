#include <bits/stdc++.h>
#define ll long long
#define N 5005

using namespace std;

bool v[N][N];
int dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1},n,m;

bool check(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<m);
}

void dfs(int x,int y)
{
	for(int i=0;i<8;++i){
		if(check(x+dx[i],y+dy[i]) && v[x+dx[i]][y+dy[i]]){
			v[x+dx[i]][y+dy[i]]=false;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	char tmp;
	cin >> n >> m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> tmp;
			if(tmp=='1')
				v[i][j]=true;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(v[i][j]){
				dfs(i,j);
				++ans;
			}
		}
	}

	if(ans<=3)
		;
	else if(ans==4)
		ans=3;
	else if(ans<=6)
		ans=4;
	else if(ans<=10)
		ans=5;
	else if(ans<=20)
		ans=(ans+1)/2;
	else
		ans=10;

	cout << ans << endl;

	return 0;
}
