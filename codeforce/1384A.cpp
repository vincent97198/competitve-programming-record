#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int a[1000];
        for(int i=0;i<n;++i)    cin >> a[i];
        string s[1000]; s[0]="";
        for(int i=0;i<max(a[0],1);++i)
            s[0]+="a";
        for(int i=1;i<=n;++i){
            s[i]="";
            for(int j=0;j<min((int)s[i-1].size(),a[i-1]);++j)
                s[i]+=s[i-1][j];
            if(s[i-1].size()>a[i-1])
                s[i]+=(((s[i-1][a[i-1]]-'a'+1)%26)+'a');
            while(s[i].size()<a[i])
                s[i]+="a";
        }
        for(int i=0;i<=n;++i)
            cout << s[i] << endl;
        //cout << endl;
    }

    return 0;
}

/*
 *
 */
