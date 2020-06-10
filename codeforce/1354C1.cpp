#include <bits/stdc++.h>
#define N 100005

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << fixed << setprecision(10);
	for(int i=0;i<n;++i){
	    double a;  cin >> a;
	    cout << tan((180-180/a)/2*acos(-1)/180) << endl;
	}

	return 0;
}

