#include <bits/stdc++.h>
#define ll long long
#define N 15

using namespace std;

int MAP[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	cin >> n;
	char tmp;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin >> tmp;
			if(tmp=='A')
				MAP[i][j]=0;
			else if(tmp=='X')
				MAP[i][j]=-(1e7);
			else if(tmp=='B')
				MAP[i][j]=0;
			else
				MAP[i][j]=tmp-'0';
		}
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i==0 && j!=0)
				MAP[i][j]+=MAP[i][j-1];
			else if(i!=0 && j==0)
				MAP[i][j]+=MAP[i-1][j];
			else if(i!=0 && j!=0)
				MAP[i][j]+=max(MAP[i-1][j],MAP[i][j-1]);
		}
	}

	if(MAP[n-1][n-1]>=0)
		cout << MAP[n-1][n-1] << endl;
	else
		cout << "X" << endl;

	return 0;
}
