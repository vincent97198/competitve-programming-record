#include <bits/stdc++.h>
#define N 305
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k;    cin >> n >> k;

        bool mp[N][N];  memset(mp,0,sizeof(mp));
        if(k==0){
            cout << "0\n";
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j)
                    cout << "0";
                cout << '\n';
            }
            continue;
        }
        int r=k%n;

        if(r==0)
            cout << "0\n";
        else
            cout << "2\n";

        for(int i=0;i<n;++i){
            for(int j=k/n+(r>0),cnt=0;j>0;--j,++cnt)
                mp[i][(i+cnt)%n]=true;
            --r;
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)
                cout << mp[i][j];
           cout << '\n';
        }
    }

    return 0;
}

/*
 * 1 1 0 0
 * 1 1 1 0
 * 0 0 1 1
 * 0 0 0 1
 *
 * 1 1 1 1
 * 0 1 1 1
 * 0 0 1 1
 * 0 0 0 1
 *
 * 1 1 0 1
 * 1 1 1 0
 * 1 0 1 1
 * 0 1 1 1
 *
 * k/n
 *
 * 1 1 1 1 0
 * 0 1 1 1 1
 * 0 0 1 1 1
 * 1 0 0 1 1
 * 1 1 0 0 1
 *
 */
