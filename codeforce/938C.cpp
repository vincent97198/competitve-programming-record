#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n; cin >> n;
        bool flag=true;
        if(n==0){
            cout << "1 1\n" << endl;
            continue;
        }
        for(int i=1;i<=sqrt(n);++i){
            if(n%i==0 && (i+n/i)%2==0){
                int N=(i+(n/i))/2,k=(n/i-i)/2,tmp;
                if(k==0)    break;
                tmp=N/k;
                if(N-tmp*k<tmp){
                    cout << N << " " << tmp << endl;
                    flag=false;
                }
            }
            if(!flag)   break;
        }
        if(flag)
            cout << "-1\n";
    }

    return 0;
}

