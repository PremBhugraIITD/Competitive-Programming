#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

ll factorial(ll n)
{
    ll ans = 1;
    fr(i, 1, n + 1)
    {
        ans = (ans * i) % mod;
    }
    return ans;
}

ll binpow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    ll n = s.length();
    vll count(26, 0);
    fr(i, 0, n)
    {
        count[s[i] - 'a']++;
    }
    ll ans = factorial(n);
    fr(i, 0, 26)
    {
        ll c = count[i];
        if (c > 1)
        {
            ans = ((ans % mod) * binpow(factorial(c), mod - 2, mod)) % mod;
        }
    }
    cout << ans << endl;
}