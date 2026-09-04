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
#define mod 1000000007
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);

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

class Hash
{
public:
    string s;
    ll n;
    ll p1 = 131, p2 = 137;
    ll m1 = 1000000007, m2 = 1000000009;
    vll prefixHash1;
    vll pow1;
    vll inv_pow1;
    Hash(string s)
    {
        this->s = s;
        n = s.length();
        pow1.assign(n, 1);
        // pow2.assign(n, 1);
        inv_pow1.assign(n, 1);
        // inv_pow2.assign(n, 1);
        prefixHash1.assign(n, s[0] - 'a' + 1);
        // prefixHash2.assign(n, s[0] - 'a' + 1);
        ll inv_p1 = binpow(p1, m1 - 2, m1);
        fr(i, 1, n)
        {
            ll val = s[i] - 'a' + 1;
            pow1[i] = (pow1[i - 1] * p1) % m1;
            // pow2[i] = (pow2[i - 1] * p2) % m2;
            inv_pow1[i] = (inv_pow1[i - 1] * inv_p1) % m1;
            // inv_pow2[i] = (inv_pow2[i - 1] * inv_p2) % m2;
            prefixHash1[i] = (prefixHash1[i - 1] + (val * pow1[i]) % m1) % m1;
            // prefixHash2[i] = (prefixHash2[i - 1] + (val * pow2[i]) % m2) % m2;
        }
    }

    ll getHash(ll l, ll r)
    {
        ll ans1 = (((prefixHash1[r] - (l - 1 >= 0 ? prefixHash1[l - 1] : 0) + m1) % m1) * inv_pow1[l]) % m1;
        // ll ans2 = (((prefixHash2[r] - (l - 1 >= 0 ? prefixHash2[l - 1] : 0) + m2) % m2) * inv_pow2[l]) % m2;
        return ans1;
    }
};

int main()
{
    fast;
    string s;
    cin >> s;
    ll n = s.length();
    bool obtained = false;
    vll count(26, 0);
    fr(i, 0, n)
    {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] == n)
        {
            obtained = true;
            break;
        }
    }
    if (obtained)
    {
        fr(i, 1, n + 1)
        {
            cout << i << " ";
        }
        cout << '\n';
    }
    else
    {
        Hash H(s);
        fr(k, 1, n + 1)
        {
            ll original = H.getHash(0, k - 1);
            bool found = false;
            ll i = k;
            for (; i + k - 1 <= n - 1; i += k)
            {
                ll curr = H.getHash(i, i + k - 1);
                if (curr == original)
                {
                    continue;
                }
                else
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                continue;
            }
            else
            {
                if (n % k != 0)
                {
                    ll size = n % k;
                    if (H.getHash(0, size - 1) == H.getHash(n - size, n - 1))
                    {
                        cout << k << " ";
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    cout << k << " ";
                }
            }
        }
        cout << '\n';
    }
}