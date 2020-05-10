#include <bits/stdc++.h>
#define ll long long
#define N 2000005

using namespace std;

struct item{
  int val,pos;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

    int n,h;
	cin >> n;
	stack<item> st;
	ll ans=0;
	for(int i=0;i<n;++i){
	    cin >> h;

        while(!st.empty() && st.top().val<h)
            st.pop();
	    if(!st.empty())
            ans+=(i-st.top().pos+st.size()-1);
	    else
	        ans+=i;

	    st.push(item{h,i});
	}

	cout << ans << endl;

	return 0;
}
// HSLR https://zsinf.org/HSLR/#/
