#include <bits/stdc++.h>
#define N 10000
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		if(x>=4)
			cout << "YES";
		else if(x>1 && y<=3)
			cout << "YES";
		else if(x==1 && y==1)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
