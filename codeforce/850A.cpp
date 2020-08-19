#include <bits/stdc++.h>
#define ll long long
#define N 1005

using namespace std;

int arr[N][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n;  cin >> n;
    for(int i=0;i<n;++i){
        for(int j=0;j<5;++j)
            cin >> arr[i][j];
    }
    if(n>100){
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans;
    for(int i=0;i<n;++i){
        bool flag=true;
        for(int j=0;j<n;++j){
            if(i==j)    continue;
            for(int k=j+1;k<n;++k){
                if(i==k || j==k)    continue;
                int tmp1[5],tmp2[5];
                for(int t=0;t<5;++t)
                    tmp1[t]=arr[j][t]-arr[i][t];
                for(int t=0;t<5;++t)
                    tmp2[t]=arr[k][t]-arr[i][t];

                ll TOP=0,DOWN1=0,DOWN2=0;
                for(int t=0;t<5;++t)
                    TOP+=tmp1[t]*tmp2[t],DOWN1+=tmp1[t]*tmp1[t],DOWN2+=tmp2[t]*tmp2[t];
                double DOWN=sqrt(DOWN1*DOWN2);
                if(acos(TOP/DOWN)< 3.1415926535/2)    flag=false;
            }
        }
        if(flag)
            ans.push_back(i+1);
    }

    cout << ans.size() << '\n';
    for(int ANS:ans)
        cout << ANS << " ";
    cout << '\n';

    return 0;
}

/*
 * 1 1 4 2 2
 */
