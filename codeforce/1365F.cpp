#include <bits/stdc++.h>
#define ll long long
#define N 505

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[N],b[N];
        for(int i=0;i<n;++i)    cin >> a[i];
        for(int i=0;i<n;++i)    cin >> b[i];
        multiset<pair<int,int>> s;
        for(int i=0;i<n;++i)
            s.insert(make_pair(b[i],b[n-i-1]));

        for(int i=0;i<n;++i){
            auto iter = s.find(make_pair(a[i],a[n-i-1]));
            if(iter !=s.end())
                s.erase(iter);
        }
        if(!s.empty())
            cout << "No\n";
        else
            cout << "yes\n";
    }

    return 0;
}

