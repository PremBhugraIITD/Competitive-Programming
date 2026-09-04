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
        string s, t;
        cin >> s >> t;
        ll n = s.length(), m = t.length();
        vvll dp(n + 1, m + 1, 0);
        // dp[i][j] = Length of the LCS made using the first i characters of the s string and the first j characters of the t string
        vector<vector<pll>> parent(n + 1, vector<pll>(m + 1, {-1, -1}));
        fr(i, 1, n + 1)
        {
            fr(j, 1, m + 1)
            {
                dp[i][j] = dp[i][j - 1];
                parent[i][j] = {i, j - 1};
                if (dp[i - 1][j] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j];
                    parent[i][j] = {i - 1, j};
                }
                if (dp[i - 1][j - 1] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    parent[i][j] = {i - 1, j - 1};
                }
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    parent[i][j] = {i - 1, j - 1};
                }
            }
        }
        // cout << dp[n][m] << endl;
        string ans;
        pll curr = {n, m};
        while (curr != make_pair((ll)-1, (ll)-1))
        {
            ll a = curr.first - 1, b = curr.second - 1;
            if ((a >= 0 && a <= n - 1) && (b >= 0 && b <= m - 1))
            {
                if (s[curr.first - 1] == t[curr.second - 1])
                {
                    ans.pb(s[curr.first - 1]);
                }
            }
            else
            {
                break;
            }
            // cout << curr.first << " " << curr.second << endl;
            curr = parent[curr.first][curr.second];
        }
        reverse(ans);
        cout << ans << endl;
    }
}