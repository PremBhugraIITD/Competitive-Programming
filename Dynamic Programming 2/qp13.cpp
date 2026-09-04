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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vvll dp(n, n, n);
        // dp[i][j] = Minimum number of moves to delete the substring from i to j
        fr(i, 0, n)
        {
            dp[i][i] = 1;
        }
        fr(len, 2, n + 1)
        {
            for (ll i = 0; i + len - 1 <= n - 1; i++)
            {
                ll j = i + len - 1;
                if (s[i] == s[i + 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                }
                else
                {
                    char curr = s[i];
                    dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);
                    fr(k, i + 1, j + 1)
                    {
                        if (s[k] == curr && k + 1 <= j)
                        {
                            dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
                        }
                    }
                }
                if (s[j] == s[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                }
                else
                {
                    char curr = s[j];
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                    fr(k, i, j)
                    {
                        if (s[k] == curr && k + 1 <= j - 1)
                        {
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
                        }
                    }
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }
}