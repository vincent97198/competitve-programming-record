#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n,k;    cin >> n >> k;
        string s;   cin >> s;
        int alphabet[26];  memset(alphabet,0,sizeof(alphabet));
        for(char ch:s)  ++alphabet[ch-'a'];

        int MAX=0;
        for(int i=1;i<=min(n,k);++i){
            if(k%i) continue;
            for(int j=1;i*j<=n;++j){
                int cnt=0;
                for(int u=0;u<26;++u)   cnt+=alphabet[u]/j;
                if(cnt>=i)
                    MAX=max(MAX,i*j);
            }
        }
        cout << MAX << endl;
    }

    return 0;
}
