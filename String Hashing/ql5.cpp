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
    ll m1 = INT_MAX, m2 = 1000000009;
    ll p1 = 131, p2 = 137;
    vll pow1, pow2;
    vll inv_pow1, inv_pow2;
    vll prefixHash1, prefixHash2;
    Hash(string s)
    {
        this->s = s;
        n = s.length();
        pow1.assign(n, 1);
        pow2.assign(n, 1);
        inv_pow1.assign(n, 1);
        inv_pow2.assign(n, 1);
        prefixHash1.assign(n, s[0] - 'a' + 1);
        prefixHash2.assign(n, s[0] - 'a' + 1);
        ll inv_p1 = binpow(p1, m1 - 2, m1), inv_p2 = binpow(p2, m2 - 2, m2);
        fr(i, 1, n)
        {
            pow1[i] = (pow1[i - 1] * p1) % m1;
            pow2[i] = (pow2[i - 1] * p2) % m2;
            int val = s[i] - 'a' + 1;
            inv_pow1[i] = (inv_pow1[i - 1] * inv_p1) % m1;
            inv_pow2[i] = (inv_pow2[i - 1] * inv_p2) % m2;
            prefixHash1[i] = ((prefixHash1[i - 1] + (val * pow1[i]) % m1) % m1);
            prefixHash2[i] = ((prefixHash2[i - 1] + (val * pow2[i]) % m2) % m2);
        }
    }

    pll getHash(ll l, ll r)
    {
        ll ans1 = (((prefixHash1[r] - (l > 0 ? prefixHash1[l - 1] : 0) + m1) % m1) * inv_pow1[l]) % m1;
        ll ans2 = (((prefixHash2[r] - (l > 0 ? prefixHash2[l - 1] : 0) + m2) % m2) * inv_pow2[l]) % m2;
        return {ans1, ans2};
    }
};

int main()
{
    string t;
    cin >> t;
    ll n = t.length();
    Hash H(t);
    string ans;
    frr(size, n - 1, 1)
    {
        // cout << t.substr(0, size) << endl;
        if (H.getHash(0, size - 1) == H.getHash(n - size, n - 1) && 2 * size > n)
        {
            // cout << t.substr(0, size) << " " << H.getHash(0, size - 1).first << " " << H.getHash(0, size - 1).second << endl;
            // cout << t.substr(n - size, size) << " " << H.getHash(n - size, n - 1).first << " " << H.getHash(n - size, n - 1).second << endl;
            ans = t.substr(0, size);
            break;
        }
    }
    if (ans == "")
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl
             << ans << endl;
    }
}