#include <bits/stdc++.h>

using namespace std;

unsigned int randfun()
{
    return (rand() << 16) ^ (rand() << 5) ^ rand();
}

int main()
{
    int n=16;   cout << n << endl;
    srand(time(NULL));
    
    int ans[n+1];
    set<int> s;
    for(int i=1;i<=n;++i){
        do {
            ans[i]=randfun()%n;
        }while(s.find(ans[i])!=s.end());
        
        cout << ans[i] << " ";
    }
    cout << endl; 
    
    for(int i=2;i<=n;++i)
        cout << (ans[1]^ans[i]) << " ";
    cout << endl;
    
    while(true){
        int type;   cin >> type;
        int a,b;    cin >> a >> b;
        if(type==1)
            cout << (ans[a]^ans[b]) << endl;
        else
            cout << (ans[a]&ans[b]) << endl;
    }    
}