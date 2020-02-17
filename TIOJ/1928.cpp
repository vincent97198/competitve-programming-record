#include <bits/stdc++.h>
#define int long long
#define ll long long
#define N 805

using namespace std;

struct pos{
	int x,y,id;
}tmp[N],p[N];

int n;
vector<pos> ans;
double dp[N][N];

bool cmp(pos a,pos b)
{
    double A=(a.y-p[0].y)/(double)(a.x-p[0].x);
    double B=(b.y-p[0].y)/(double)(b.x-p[0].x);

    return A<B;
}

inline double len(int l,int r)
{
	return sqrt((p[l].x-p[r].x)*(p[l].x-p[r].x)+(p[l].y-p[r].y)*(p[l].y-p[r].y));
}

void TRACE_dfs(int l,int r)
{
	if(l+1==r)
		return ;
    for(int i=l+1;i<r;++i){
        if(dp[l][r]==dp[l][i]+dp[i][r]+len(l,r)){
            ans.push_back(pos{p[l].id,p[r].id,0});
            TRACE_dfs(l,i); TRACE_dfs(i,r);
            break;
        }
    }
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n;
	for(int i=0;i<n;++i){
        cin >> p[i].x >> p[i].y;
        p[i].id=i;
	}

	sort(p+1,p+n,cmp);

	for(int l=n-2;l>=0;--l){
		dp[l][l+1]=0;
		for(int r=l+2;r<n;++r){
			dp[l][r]=1e15;
			for(int k=l+1;k<r;++k)
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+len(l,r));
		}
	}
		
	TRACE_dfs(0,n-1);
	
	for(int i=1;i<ans.size();++i){
        cout << ans[i].x << " " << ans[i].y << endl;
	}

	return 0;
}
/*
 5
 -2 0
 -1 1
 0 -1
 1 0
 1 1
 */
