#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

bool vis[2000][2000];
pair<int,int> d[4]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n;  cin >> n;
    cout << 3*n+4 << endl;
    for(int i=0;i<n;++i){
        cout << i << " " << i << endl;
        cout << (i+1) << " " << i << endl;
        cout << i << " " << (i+1) << endl;
    }
    cout << n << " " << n << endl;
    cout << (n+1) << " " << n << endl;
    cout << n << " " << (n+1) << endl;
    cout << (n+1) << " " << (n+1) << endl;

    return 0;
}
