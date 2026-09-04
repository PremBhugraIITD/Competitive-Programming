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
        ll n, m, k;
        cin >> n >> m >> k;
        vvll A(n, m - 1, 0);
        fr(i, 0, n)
        {
            fr(j, 0, m - 1)
            {
                cin >> A[i][j];
            }
        }
        vvll B(n - 1, m, 0);
        fr(i, 0, n - 1)
        {
            fr(j, 0, m)
            {
                cin >> B[i][j];
            }
        }
        if (k & 1)
        {
            fr(i, 0, n)
            {
                fr(j, 0, m)
                {
                    cout << -1 << " ";
                }
                cout << endl;
            }
            continue;
        }
        k /= 2;
        vector<vector<vll>> dp(n, vector<vll>(m, vll(k + 1, LONG_LONG_MAX)));
        // dp[i][j][x] = Minimum cost to move outwards from cell (i,j) in exactly x steps
        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                dp[i][j][0] = 0;
            }
        }
        fr(x, 1, k + 1)
        {
            fr(i, 0, n)
            {
                fr(j, 0, m)
                {
                    if (i - 1 >= 0)
                    {
                        dp[i][j][x] = min(dp[i][j][x], B[i - 1][j] + dp[i - 1][j][x - 1]);
                    }
                    if (i + 1 <= n - 1)
                    {
                        dp[i][j][x] = min(dp[i][j][x], B[i][j] + dp[i + 1][j][x - 1]);
                    }
                    if (j - 1 >= 0)
                    {
                        dp[i][j][x] = min(dp[i][j][x], A[i][j - 1] + dp[i][j - 1][x - 1]);
                    }
                    if (j + 1 <= m - 1)
                    {
                        dp[i][j][x] = min(dp[i][j][x], A[i][j] + dp[i][j + 1][x - 1]);
                    }
                }
            }
        }
        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                cout << 2 * dp[i][j][k] << " ";
            }
            cout << endl;
        }
    }
}