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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        if (n == 1)
        {
            cout << A[0] << endl;
            continue;
        }
        vvll dp(n + 1, k + 1, LONG_LONG_MAX);
        // dp[i][j] = Minimum sum possible till first i elements if the operation is done k times
        fr(i, 0, k + 1)
        {
            dp[0][i] = 0;
        }
        fr(i, 0, n)
        {
            fr(j, 0, k + 1)
            {
                if (dp[i][j] == LONG_LONG_MAX)
                {
                    continue;
                }
                ll mini = LONG_LONG_MAX;
                for (ll m = 0; j + m <= k && i + m <= n - 1; m++)
                {
                    mini = min(mini, A[i - 1 + m + 1]);
                    dp[i - 1 + m + 1 + 1][j + m] = min(dp[i + m + 1][j + m], dp[i][j] + (m + 1) * mini);
                }
            }
        }
        ll ans = LONG_LONG_MAX;
        fr(i, 0, k + 1)
        {
            ans = min(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
}