#include <bits/stdc++.h>
#define N 300005
#define ll long long

using namespace std;

int boss[30],group[30];

int find(int x)
{
    if(boss[x]==x)
        return x;
    else{
        boss[x]=find(boss[x]);
        return boss[x];
    }
}

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        string A,B; cin >> A >> B;
        bool flag=false;
        for(int i=0;i<30;++i)   boss[i]=i,group[i]=1;
        for(int i=0;i<n;++i){
            if(A[i]>B[i])
                flag=true;
            else{
                int AA=A[i]-'a',BB=B[i]-'a';
                AA=find(AA);    BB=find(BB);
                if(AA==BB)  continue;
                boss[AA]=BB;
                group[BB]+=group[AA];
            }
        }
        if(flag)
            cout << -1 << endl;
        else{
            int ans=0;
            for(int i=0;i<26;++i){
                if(i==find(i))
                    ans+=group[i]-1;
            }
            cout << ans << endl;
        }
    }

    return 0;
}

/*
 *
 */
