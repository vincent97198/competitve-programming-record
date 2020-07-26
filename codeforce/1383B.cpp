#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[N];
        for(int i=0;i<n;++i)    cin >> a[i];

        int cnt;
        bool flag=false;
        for(int bit=30;bit>=0;--bit){
            cnt=0;
            for(int i=0;i<n;++i){
                if(a[i]&(1<<bit))   ++cnt;
            }
            if(cnt%2){
                if(cnt%4==3 && n%2)
                    cout << "LOSE\n";
                else
                    cout << "WIN\n";
                flag=true;
            }
            if(flag)    break;
        }
        if(!flag)
            cout << "DRAW\n";
    }
    return 0;
}

/*
 *
 */
