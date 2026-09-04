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
    ll number = 1, sum = 1, product = 1, modNumber = 1, halfNumber = 1;
    vpll pf;
    bool found = false;
    while (n--)
    {
        ll x, k;
        cin >> x >> k;
        number = ((number % mod) * ((k + 1) % mod)) % mod;
        modNumber = ((modNumber % (mod - 1)) * ((k + 1) % (mod - 1))) % (mod - 1);
        sum = ((sum % mod) * ((((binpow(x, k + 1, mod) - 1) % mod) * binpow(x - 1, mod - 2, mod)) % mod)) % mod;
        pf.pb({x, k});
        if (!((k + 1) & 1) && !found)
        {
            halfNumber = ((halfNumber % (mod - 1)) * (((k + 1) / 2) % (mod - 1))) % (mod - 1);
        }
        else
        {
            halfNumber = ((halfNumber % (mod - 1)) * ((k + 1) % (mod - 1))) % (mod - 1);
        }
        if (k & 1)
        {
            found = true;
        }
    }
    if (found)
    {
        fr(i, 0, pf.size())
        {
            ll p = pf[i].first, k = pf[i].second;
            product = ((product % mod) * binpow(p, ((k % (mod - 1)) * halfNumber) % (mod - 1), mod)) % mod;
        }
    }
    else
    {
        fr(i, 0, pf.size())
        {
            ll p = pf[i].first, k = pf[i].second;
            product = ((product % mod) * binpow(p, (((k / 2) % (mod - 1)) * (modNumber)) % (mod - 1), mod)) % mod;
        }
    }
    cout << number << " " << sum << " " << product << endl;
}