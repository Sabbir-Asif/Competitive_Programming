#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define repf(i,x,n) for(int i=x,i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define maxN 1000000
typedef pair<int, int>  pii;  
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;

ll mulmod(ll a, ll b, ll c)
{
	ll x = 0, y = a%c;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x = (x + y) % c;
		}
		 y = (y*2ll) % c;
		 b /= 2;
	}

	return x%c;
}

ll binPower(ll a, ll n, ll mod)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		{
			res = mulmod(res, a, mod);
		}

		n >>= 1;
		a = mulmod(a, a, mod);
	}

	return res % mod;
}

bool isPrime(ll n)
{
	int iterations = 5;
	if(n <= 4)
		return n== 2 || n == 3;

	for(int i = 1; i <= iterations; i++)
	{
		ll a = 2 + rand() % (n - 3);
		ll res = binPower(a, n - 1, n);

		if(res != 1)  return false;
	}

	return true;
}

int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(isPrime(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}