#include <bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;

bool p[100000];
vector<int> Prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    string Fst="Ashishgup",Snd="FastestFinger";
    for(ll i=2;i<100000;++i){
        if(!p[i]){
            Prime.emplace_back(i);
            for(ll j=i*i;j<100000;j+=i)
                p[i]=true;
        }
    }
    while(t--){
        int n;  cin >> n;
        if(n==1){
            cout << Snd << endl;
            continue;
        }
        if(n&1 || n==2)
            cout << Fst << endl;
        else{
            int tmp=n,cnt=0;
            while(tmp%2==0){
                tmp/=2;
                ++cnt;
            }
            if(cnt>=2 && tmp!=1)
                cout << Fst << endl;
            else{
                bool flag=true;
                for(int P:Prime){
                    if(tmp%P==0 && P!=2 && tmp/2>P){
                        cout << Fst << endl;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                    cout << Snd << endl;
            }
        }

    }

    return 0;
}
