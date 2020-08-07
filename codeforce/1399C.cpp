#include <bits/stdc++.h>
#define N 500005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n,w[N];  cin >> n;
        for(int i=0;i<n;++i)    cin >> w[i];

        int MAX=0;
        for(int sum=2*n;sum>=0;--sum){
            map<int,int> mp;
            for(int i=0;i<n;++i)    ++mp[w[i]];
            int tmp=0;
            for(auto iter=mp.begin();iter!=mp.end();++iter){
                while(iter->second>0){
                    --(iter->second);
                    if(mp[sum-(iter->first)]>0){
                        ++tmp;
                        --mp[sum-(iter->first)];
                    }
                }
            }
            MAX=max(MAX,tmp);
        }
        cout << MAX << endl;
    }

    return 0;
}

/*
 *
 */
