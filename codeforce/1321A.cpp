#include <bits/stdc++.h>
#define ll long long
#define N 105

using namespace std;

int n;
bool R[N],B[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    cin >> n;
    int tmp;
    for(int i=0;i<n;++i){
        cin >> tmp;
        if(tmp)
            R[i]=true;
        else
            R[i]=false;
    }
    for(int i=0;i<n;++i){
        cin >> tmp;
        if(tmp)
            B[i]=true;
        else
            B[i]=false;
    }

    int A=0,AA=0;
    for(int i=0;i<n;++i){
        if(R[i] && !B[i])
            ++A;
        if(B[i] && !R[i])
            ++AA;
    }

    if(AA!=0 && A!=0)
        cout << AA/A+1;
    else if(A!=0)
        cout << 1;
    else
        cout << -1;

    cout << endl;

    return 0;
}

