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
#define N 1000000000
typedef pair<int, int>  pii;  
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;

int phi[maxN+1];

void init(int N)
{
	for(int i = 1; i <= N; ++i)
		phi[i] = i;

	for(int i = 2; i <= N ; ++i)
	{
		if(phi[i] == i)
		{
		    for(int j = i ; j <= N ; j+=i)
	        {
		       phi[j] /= i;
		       phi[j] *= (i - 1);
	        }
		}
	}
}

int getCount(int d, int n)
{
	init(maxN);
	return phi[n/d];
}

int main()
{
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int res = 0;

		for(int i = 1; i*i <= n; ++i)
		{
			if(n%i == 0)
			{
				int d1 = i;
				int d2 = n/i;

				res += d1 * getCount(d1, n);

				if(d1 != d2)
					res += d2 * getCount(d2, n);
			}
		}

		cout << res << endl;
	}
}