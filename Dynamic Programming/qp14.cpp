#include <bits/stdc++.h>
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
#define printVector(v)    \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define printPairVector(v) \
    for (auto &x : v)      \
        cout << x.first << ' ' << x.second << endl;
#define mod 1000000007

class vvll : public vector<vector<ll>>
{
public:
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x = 1e5;
    vector<bool> isPrime(x + 1, true);
    vll spf(x + 1, INT_MAX);
    isPrime[0] = isPrime[1] = false;
    fr(i, 2, x + 1)
    {
        if (isPrime[i])
        {
            spf[i] = i;
            for (ll j = i * i; j <= x; j += i)
            {
                isPrime[j] = false;
                spf[j] = min(spf[j], i);
            }
        }
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vll dp(n, 1);
        // dp[i] = Longest good sequence if element at the ith index is definitely included
        mll last;
        ll curr = A[0];
        while (curr > 1)
        {
            ll p = spf[curr];
            while (curr % p == 0)
            {
                curr /= p;
            }
            last[p] = 0;
        }
        fr(i, 1, n)
        {
            ll curr = A[i];
            while (curr > 1)
            {
                ll p = spf[curr];
                while (curr % p == 0)
                {
                    curr /= p;
                }
                if (last.count(p))
                {
                    dp[i] = max(dp[i], 1 + dp[last[p]]);
                }
                last[p] = i;
            }
        }
        ll ans = 0;
        fr(i, 0, n)
        {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}