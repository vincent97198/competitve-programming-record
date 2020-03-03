#include <bits/stdc++.h>
#define ll long long
#define N 105
 
using namespace std;
 
int n;
vector<int> arr;
 
int main()
{
    cin >> n;
    arr.resize(n);
    char ch;
    for(int i=0; i<n; ++i) {
        cin >> ch;
        arr[i]=ch-'a'+1;
    }
    int ans=0,tmp;
    for(int letter=26; letter>1; --letter) {
        tmp=-1;
        while(tmp!=0) {
            tmp=0;
            for(int i=0; i<arr.size(); ++i) {
                if(arr[i]!=letter)  continue;
                if((i>0 && arr[i-1]+1==arr[i]) || (i<arr.size()-1 && arr[i+1]+1==arr[i])) {
                    ++tmp;
                    arr.erase(arr.begin()+i);
                }
            }
            ans+=tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}
