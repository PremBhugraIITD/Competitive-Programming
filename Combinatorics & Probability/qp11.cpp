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
#define mod 998244353

ll binpow(ll a, ll b, ll c)
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
    ll x = 2 * 1e5;
    vll fact(x + 1, 1);
    fr(i, 1, x + 1)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    vll inv_fact(x + 1, 1);
    inv_fact[x] = binpow(fact[x], mod - 2, mod);
    frr(i, x - 1, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        sort(A);
        if (A[n - 1] - A[n - 2] >= 2)
        {
            cout << 0 << endl;
        }
        else if (A[n - 1] == A[n - 2])
        {
            cout << fact[n] << endl;
        }
        else
        {
            ll count = 0;
            frr(i, n - 2, 0)
            {
                if (A[i] == A[n - 2])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            ll temp = 0;
            frr(i, n - 1, count)
            {
                ll left = i, right = n - 1 - i;
                ll a = 1;
                a = (a * fact[left]) % mod;
                a = (a * fact[right]) % mod;
                a = (a * fact[n - 1 - count]) % mod;
                a = (a * inv_fact[right]) % mod;
                a = (a * inv_fact[n - 1 - count - right]) % mod;
                temp = (temp + a) % mod;
            }
            cout << (fact[n] - temp + mod) % mod << endl;
        }
    }
}