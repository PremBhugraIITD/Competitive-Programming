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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll x = 2 * 1e5;
    vll isPrime(x + 1, 1);
    vll spf(x + 1, INT_MAX);
    isPrime[0] = isPrime[1] = 0;
    fr(i, 2, x + 1)
    {
        if (isPrime[i])
        {
            spf[i] = i;
            for (ll j = i * i; j <= x; j += i)
            {
                isPrime[j] = 0;
                spf[j] = min(i, spf[j]);
            }
        }
    }
    ll n;
    cin >> n;
    vll A(n);
    map<ll, vll> primes;
    fr(i, 0, n)
    {
        cin >> A[i];
        ll temp = A[i];
        while (temp > 1)
        {
            ll p = spf[temp];
            ll k = 0;
            while (temp % p == 0)
            {
                k++;
                temp /= p;
            }
            primes[p].pb(k);
        }
    }
    ll ans = 1;
    for (auto i : primes)
    {
        sort(i.second);
        ll zeroes = n - i.second.size(), pow;
        if (zeroes == 0)
        {
            pow = i.second[1];
        }
        else if (zeroes == 1)
        {
            pow = i.second[0];
        }
        else
        {
            pow = 0;
        }
        ans *= binpow(i.first, pow);
    }
    cout << ans << endl;
}