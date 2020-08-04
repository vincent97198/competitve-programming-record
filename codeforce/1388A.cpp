#include <bits/stdc++.h>
#define N 200005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        if(n<=30)   cout << "NO\n";
        else{
            cout << "YES\n";
            if(n==36 || n==40 || n==44)
                cout << "6 10 15 " << n-31 << endl;
            else
                cout << "6 10 14 " << n-30 << endl;
        }
    }

    return 0;
}

/*
 *
 */
