#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

int n,arr[N];
bool p[4000];
vector<int> prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i];

    for(int i=2;i<=sqrt(1e7);++i){
        if(!p[i]){
            prime.push_back(i);
            for(int j=i*i;j<=sqrt(1e7);j+=i)
                p[j]=true;
        }
    }

    int ans[N][2];
    for(int i=0;i<n;++i){
        int tmp=arr[i];
        vector<int> d;
        for(int P:prime){
            if(tmp%P==0)
                d.push_back(P);
            while(tmp%P==0){
                tmp/=P;
            }
        }
        if(tmp!=1)
            d.push_back(tmp);

        ans[i][0]=d[0],ans[i][1]=1;
        for(int j=1;j<d.size();++j)
            ans[i][1]*=d[j];
    }

    for(int i=0;i<n;++i){
        if(ans[i][0]==1 || ans[i][1]==1)
            ans[i][0]=ans[i][1]=-1;
    }

    for(int i=0;i<2;++i){
        for(int j=0;j<n;++j)
            cout << ans[j][i] << " ";
        cout << endl;
    }

    return 0;
}
/*
 * a=x^p*y^q*z
 * x+y,x^p*y^q*z
 * gcd(x+y,z)=1
 *
 */
