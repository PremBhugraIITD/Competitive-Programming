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
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            vvll dp(a + 1, b + 1, INT_MAX);
            // dp[i][j] = Minimum number of cuts required to convert an i x j rectangle into squares
            fr(i, 1, b + 1)
            {
                dp[1][i] = i - 1;
            }
            fr(i, 1, a + 1)
            {
                dp[i][1] = i - 1;
            }
            fr(i, 2, a + 1)
            {
                fr(j, 2, b + 1)
                {
                    if (i == j)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        fr(k, 1, j)
                        {
                            dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                        }
                        fr(k, 1, i)
                        {
                            dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                        }
                        // cout << i << " " << j << ": " << dp[i][j] << endl;
                    }
                }
            }
            cout << dp[a][b] << endl;
        }
    }
}