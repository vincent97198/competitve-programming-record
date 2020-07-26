#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int boss[30];

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
        bool is_DAG[1<<20];   memset(is_DAG,0,sizeof(is_DAG));
        int reach[N],ans=40,group=20; memset(reach,0,sizeof(reach));
        for(int i=0;i<30;++i)   boss[i]=i;
        for(int i=0;i<n;++i){
            int AA=A[i]-'a',BB=B[i]-'a';
            if(AA!=BB)  reach[AA]|=(1<<BB);
            AA=find(AA);    BB=find(BB);
            if(AA==BB)  continue;
            --group;
            boss[AA]=BB;
        }

        is_DAG[0]=true;
        int sumOfMaxDAG=0;
        for(int i=1;i<(1<<20);++i){
            for(int j=0;j<20;++j){
                if((1<<j)&i){
                    is_DAG[i]|=(is_DAG[i^(1<<j)] && ((i&reach[j])==0));
                    if(is_DAG[i])   break;
                }
            }
            if(is_DAG[i])   sumOfMaxDAG=max(__builtin_popcount(i),sumOfMaxDAG);
        }

        cout << ans-group-sumOfMaxDAG << endl;
    }

    return 0;
}

/*
 *
 */
