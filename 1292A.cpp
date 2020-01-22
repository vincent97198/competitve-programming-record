#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n,q,block=0;
	cin >> n >> q;
	bool visit[2][N];
	memset(visit,0,sizeof(visit));
	while(q--){
		int x,y;
		cin >> x >> y;
		--x;
		--y;
		if(visit[x][y]){
			for(int i=-1;i<=1;++i){
				if(y+i>=0 && y+i<n && visit[(x+1)%2][y+i])
					--block;
			}
			visit[x][y]=false;
		}
		else{
			for(int i=-1;i<=1;++i){
				if(y+i>=0 && y+i<n && visit[(x+1)%2][y+i])
					++block;
			}
			visit[x][y]=true;
		}
		if(block!=0)
			cout << "No";
		else
			cout << "Yes";
		cout << endl;
	}

	return 0;
}
