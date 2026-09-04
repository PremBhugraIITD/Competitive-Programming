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
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 998244353

ll binpow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll x = 3 * 1e5;
    vll fact(x + 1, 1), inv_fact(x + 1, 1);
    fr(i, 1, x + 1)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[x] = binpow(fact[x], mod - 2, mod);
    frr(i, x - 1, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    ll n;
    cin >> n;
    vll W(n);
    fr(i, 0, n)
    {
        cin >> W[i];
    }
    ll ans = 1, m = n / 3;
    ans = (fact[m] * inv_fact[m / 2]) % mod;
    ans = (ans * inv_fact[m / 2]) % mod;
    for (ll i = 0; i < n; i += 3)
    {
        ll a = W[i], b = W[i + 1], c = W[i + 2];
        if (a == b && b == c)
        {
            ans = (3 * ans) % mod;
        }
        else if (a != b && b != c && c != a)
        {
            continue;
        }
        else
        {
            vll temp = {a, b, c};
            sort(temp);
            if (temp[1] == temp[2])
            {
                continue;
            }
            else
            {
                ans = (2 * ans) % mod;
            }
        }
    }
    cout << ans << endl;
}