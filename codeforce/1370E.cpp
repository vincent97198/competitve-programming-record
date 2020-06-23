#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n,arr[N];
    string s,t;
    cin >> n >> s >> t;
    for(int i=0;i<n;++i){
        if(s[i]==t[i])
            arr[i]=0;
        else if(s[i]=='1')
            arr[i]=1;
        else
            arr[i]=-1;
    }
    int sum=0,MAX=0,cnt_positive=0,cnt_negative=0;
    for(int i=0;i<n;++i){
        sum+=arr[i],cnt_positive+=arr[i],cnt_negative+=arr[i];
        cnt_positive=max(0,cnt_positive);
        cnt_negative=min(0,cnt_negative);
        MAX=max(MAX,max(abs(cnt_negative),abs(cnt_positive)));
    }
    if(sum!=0)
        cout << -1 << endl;
    else
        cout << MAX << endl;

    return 0;
}
