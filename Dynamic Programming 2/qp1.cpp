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
#define mod 998244353

class vvll : public vector<vector<ll>>
{
public:
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n), B(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        fr(i, 0, n)
        {
            cin >> B[i];
        }
        ll x = 3000;
        vvll dp(n, x + 1, 0);
        // dp[i][j] = Number of non-decreasing sequences of length i whose last element is j.
        fr(i, A[0], B[0] + 1)
        {
            dp[0][i] = 1;
        }
        // ll temp = 0;
        // fr(i, 0, x + 1)
        // {
        //     temp = (temp + dp[0][i]) % mod;
        // }
        // cout << temp << endl;
        fr(i, 1, n)
        {
            ll sum = 0;
            fr(j, 0, B[i] + 1)
            {
                sum = (sum + dp[i - 1][j]) % mod;
                if (j >= A[i])
                {
                    dp[i][j] = (dp[i][j] + sum) % mod;
                }
            }
            // temp = 0;
            // fr(j, 0, x + 1)
            // {
            //     temp = (temp + dp[i][j]) % mod;
            // }
            // cout << temp << endl;
        }
        ll ans = 0;
        fr(i, 0, x + 1)
        {
            ans = (ans + dp[n - 1][i]) % mod;
        }
        cout << ans << endl;
    }
}