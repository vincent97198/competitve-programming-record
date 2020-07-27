#include <bits/stdc++.h>
#define N 2005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        pair<int,int> st[4]={{0,0},{n,0},{n,n},{0,n}},d[4]={{0,0},{-1,0},{-1,-1},{0,-1}};
        if(n==2){
            cout << "3\n"
                 << "0 0 1\n"
                 << "0 0 2\n"
                 << "1 1 1\n";
            continue;
        }
        else if(n==1){
            cout << "1\n"
                 << "0 0 1\n";
            continue;
        }

        cout << 2*n-2 << endl;

        if(n&1){
            for(int cnt=0;cnt<4;++cnt)
                for(int i=1;i<=n-2;i+=2)
                    cout << st[cnt].first+d[cnt].first*(n+i)/2 << " " << st[cnt].second+d[cnt].second*(n+i)/2 << " " << (n+i)/2 << endl;
        }
        else{
            cout << "0 0 " << n/2 << endl;
            cout << n/2 << " " << n/2 << " " << n/2 << endl;
            for(int cnt=0;cnt<4;++cnt)
                for(int i=1;i<=n/2-1;++i)
                    cout << st[cnt].first+d[cnt].first*(n/2+i) << " " << st[cnt].second+d[cnt].second*(n/2+i) << " " << (n/2+i) << endl;
        }
    }

    return 0;
}

/*
 *
 */
