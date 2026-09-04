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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

ll modpow(ll a, ll e)
{
    ll res = 1;
    a %= mod;
    while (e)
    {
        if (e & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

ll modinv(ll x)
{
    return modpow(x % mod, mod - 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        mll count;
        fr(i, 0, n)
        {
            count[A[i]]++;
        }
        ll ans = 0, product = 1;
        vpll temp;
        for (auto i : count)
        {
            temp.pb({i.first, i.second});
        }
        n = temp.size();
        ll i = 0, j = 0;
        while (j < n)
        {
            product *= temp[j].second % mod;
            product %= mod;
            if (j - i + 1 >= m)
            {
                ll a = (j - m >= i ? temp[j - m].second : 1) % mod;
                product = (product * modinv(a)) % mod;
                product = product % mod;
                ans += product % mod;
                ans %= mod;
            }
            if (j + 1 < n && temp[j + 1].first - temp[j].first > 1)
            {
                product = 1;
                i = j + 1;
            }
            j++;
        }
        cout << ans << endl;
    }
}