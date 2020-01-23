#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n;
	long double ans=0;
	cin >> n;

	while(n--){
		ans+=(long double)1/(n+1);
	}
	cout << fixed << setprecision(15) << ans << endl;

	return 0;
}
