#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define X first
#define Y second

using namespace std;

/*
 * (1+k)*k/2 mod N=0
 * N=p	k=p-1;
 * N=x*y
 * k(1+k)/2 mod x = 0
 * k(1+k)/2 mod y = 0
 * k(k+1) mod x = 0
 * k(k+1) mod y = 0
 * if we guess 2N=x*y
 * obvious x<k and y<k
 * set k mod x = 0
 * then k+1 mod y = 0
 * k mod y = -1
 * k mod x = 0
 * for every x we have y=2*N/x
 * so that we can use CRT to solve k
 * find the minimun k from all x
 */

void init()
{

}

void solve()
{

}

signed main()
{
	init();
	solve();
}

