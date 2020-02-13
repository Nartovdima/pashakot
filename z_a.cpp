#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")*/


#define eb emplace_back
#define pb push_back
#define int long long
#define ld long double
#define f first
#define s second
#define dimas_pidoras false
#define buhlich_botaet false
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(10); \
    cerr << fixed << setprecision(10); \
}
const int INF = 1e18 + 7;
const ld EPS = 1e-8;
const int MAXI = 20000;
const int MOD = 16714589;
const int MAXST = 2000000;
const int P = 40;
const ld PI = 3.14159265358979323;
const int MAXN = 1e5;

int m, n;
string c;
vector <int> koof;

int cm(int n){
	int i;
	for(i = 1; trunc(log2(n + i + 1)) >= i; i++);
	return i;
}

void mask(signed u){
	int msk = (1 << u);
	for(int i = 0; i <= pow(2, m); i++){
		if (i & msk && i <= n + m && i != msk) 
			koof.eb(i);
	}
}

int sigmaxor(signed u){
	koof.clear();
	mask(u);
	int s = (c[koof[0]] - '0');
	for(int i = 1; i < koof.size(); i++){
		s ^= (c[koof[i]] - '0');
	}
	return s;
}

signed main()
{
    fast();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string a;
	cin >> a;
    n = a.size();
	m = cm(n);
	c.resize(m + n + 1, '5');
	int j = 0;
	for(int i = 1; i <= n + m; i++){
		if (trunc(log2(i)) == log2(i))
			c[i] = '#';
		else
			c[i] = a[j++];
	}
	int u = 0;
	for(int i = 1; i <= n + m; i++){
		if (log2(i) == trunc(log2(i))){
			c[i] = (char) sigmaxor(u) + '0';
			u++;
		}
	}
	for(int i = 1; i <= n + m; i++)
        cout << c[i];
    return 0;
}
