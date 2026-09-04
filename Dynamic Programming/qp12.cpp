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
    ll x = 2e5;
    vvll ans(x + 1, 10, 0);
    fr(k, 0, 10)
    {
        vvll dp(x + 1, 10, 0);
        dp[0][k] = 1;
        fr(i, 1, x + 1)
        {
            fr(j, 1, 10)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            }
            dp[i][0] = (dp[i][0] + dp[i - 1][9]) % mod;
            dp[i][1] = (dp[i][1] + dp[i - 1][9]) % mod;
            fr(j, 0, 10)
            {
                ans[i][k] = (ans[i][k] + dp[i][j]) % mod;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        // dp[i][j] = Number of digits which are j after i operations
        ll res = 0;
        while (n)
        {
            ll digit = n % 10;
            res = (res + ans[m][digit]) % mod;
            n /= 10;
        }
        cout << res << endl;
    }
}