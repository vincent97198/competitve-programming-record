#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[26],arr2[26][26];

int main()
{
    string s;
    cin >> s;
    ll MAX=0;
    for(int i=0;i<s.size();++i){
        for(int j=0;j<26;++j){
            arr2[j][s[i]-'a']+=arr[j];
            MAX=max(MAX,arr2[j][s[i]-'a']);
        }
        ++arr[s[i]-'a'];
        MAX=max(arr[s[i]-'a'],MAX);
    }
    cout << MAX << endl;

    return 0;
}
