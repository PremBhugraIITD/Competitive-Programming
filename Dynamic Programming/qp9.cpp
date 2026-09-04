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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vvll dp(n + 1, m + 1, 0);
        if (A[0] == 0)
        {
            fr(j, 1, m + 1)
            {
                dp[1][j] = 1;
            }
        }
        else
        {
            dp[1][A[0]] = 1;
        }
        fr(i, 2, n + 1)
        {
            if (A[i - 1] == 0)
            {
                fr(j, 1, m + 1)
                {
                    dp[i][j] = (dp[i][j] + (j - 1 >= 1 ? dp[i - 1][j - 1] : 0)) % mod;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                    dp[i][j] = (dp[i][j] + (j + 1 <= m ? dp[i - 1][j + 1] : 0)) % mod;
                }
            }
            else
            {
                dp[i][A[i - 1]] = (dp[i][A[i - 1]] + (A[i - 1] - 1 >= 1 ? dp[i - 1][A[i - 1] - 1] : 0)) % mod;
                dp[i][A[i - 1]] = (dp[i][A[i - 1]] + dp[i - 1][A[i - 1]]) % mod;
                dp[i][A[i - 1]] = (dp[i][A[i - 1]] + (A[i - 1] + 1 <= m ? dp[i - 1][A[i - 1] + 1] : 0)) % mod;
            }
        }
        ll ans = 0;
        fr(i, 1, m + 1)
        {
            ans = (ans + dp[n][i]) % mod;
        }
        cout << ans << endl;
    }
}