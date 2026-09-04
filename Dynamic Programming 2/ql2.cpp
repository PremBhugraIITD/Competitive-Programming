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
        ll n, k1, k2;
        cin >> n >> k1 >> k2;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vll X(n), Y(n);
        fr(i, 0, n)
        {
            cin >> X[i];
        }
        fr(i, 0, n)
        {
            cin >> Y[i];
        }
        vvll dp(n + 1, k1 + 1, LONG_LONG_MIN);
        // dp[i][j] = Maximum scores using the first i elements if we use exactly j 3s.
        dp[0][0] = 0;
        fr(i, 1, n + 1)
        {
            fr(j, 0, min(i, k1) + 1)
            {
                ll threes = j, fives = i - j;
                if (fives > k2 || fives < 0)
                {
                    continue;
                }
                else
                {
                    if (A[i - 1] == 3)
                    {
                        if (j - 1 >= 0 && dp[i - 1][j - 1] != LONG_LONG_MIN)
                        {
                            dp[i][j] = max(dp[i][j], (j - 1 >= 0 ? dp[i - 1][j - 1] : 0) + X[i - 1]);
                        }
                    }
                    else if (A[i - 1] == 5)
                    {
                        if (dp[i - 1][j] != LONG_LONG_MIN)
                        {
                            dp[i][j] = max(dp[i][j], dp[i - 1][j] + Y[i - 1]);
                        }
                    }
                    else
                    {
                        if (j - 1 >= 0 && dp[i - 1][j - 1] != LONG_LONG_MIN)
                        {
                            dp[i][j] = max(dp[i][j], (j - 1 >= 0 ? dp[i - 1][j - 1] : 0) + X[i - 1]);
                        }
                        if (dp[i - 1][j] != LONG_LONG_MIN)
                        {
                            dp[i][j] = max(dp[i][j], dp[i - 1][j] + Y[i - 1]);
                        }
                    }
                }
            }
        }
        ll ans = LONG_LONG_MIN;
        fr(i, 0, k1 + 1)
        {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
}