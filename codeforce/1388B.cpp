#include <bits/stdc++.h>
#define N 200005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        for(int i=0;i<n-ceil(n/4.0);++i)    cout << 9;
        for(int i=0;i<ceil(n/4.0);++i)  cout << 8;
        cout << endl;
        //1000
    }

    return 0;
}

/*
 *
 */
