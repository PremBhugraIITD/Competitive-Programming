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
    ll n;
    cin >> n;
    vll fact(n + 1, 1), inv_fact(n + 1, 1);
    fr(i, 1, n + 1)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[n] = binpow(fact[n], mod - 2, mod);
    frr(i, n - 1, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    ll ans = 0;
    fr(i, 0, n + 1)
    {
        if (i & 1)
        {
            ans = (ans - (fact[n] * inv_fact[i]) % mod + mod) % mod;
        }
        else
        {
            ans = (ans + (fact[n] * inv_fact[i]) % mod) % mod;
        }
    }
    cout << ans % mod << endl;
}