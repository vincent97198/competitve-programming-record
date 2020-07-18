#include <bits/stdc++.h>
#define N 200003
#define ll long long

using namespace std;

int n,x[N],cnt[N];

void solvemn()
{
    int ans=0;
    for(int i=1;i<=n;++i){
        if(cnt[i]==0) continue;
        ++ans;  i+=2;
    }
    cout << ans << endl;
    //return ans;
}

int solveMx()
{
    bool num[N+5];  memset(num,0,sizeof(num));
    for(int i=1;i<=n;++i){
        if(cnt[i]==0)   continue;
        if(cnt[i]>=1 && !num[i-1])
            num[i-1]=true,--cnt[i];
        if(cnt[i]>=1 && !num[i])
            num[i]=true,--cnt[i];
        if(cnt[i]>=1 && !num[i+1])
            num[i+1]=true,--cnt[i];
    }
    int ans=0;
    for(int i=0;i<=n+1;++i)
        ans+=num[i];
    return ans;
}

int main()
{
    cin >> n;   memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;++i){
        cin >> x[i];
        ++cnt[x[i]];
    }
    solvemn();
    cout << " " << solveMx() << endl;

    return 0;
}

/*
 *
 */
