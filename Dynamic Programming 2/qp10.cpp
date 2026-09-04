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
        vll B(k);
        fr(i, 0, k)
        {
            cin >> B[i];
        }
        vll C(k);
        fr(i, 0, k)
        {
            cin >> C[i];
        }
        vvll dp(n + 1, k + 1, LONG_LONG_MAX);
        // dp[i][j] = Minimum time to run the first i programs when the 2nd CPU ran program j last
        dp[1][0] = B[A[0] - 1];
        fr(i, 1, n)
        {
            fr(j, 0, k + 1)
            {
                if (dp[i][j] == LONG_LONG_MAX)
                {
                    continue;
                }
                else
                {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (A[i] == A[i - 1] ? C[A[i] - 1] : B[A[i] - 1]));
                    dp[i + 1][A[i - 1]] = min(dp[i + 1][A[i - 1]], dp[i][j] + (A[i] == j ? C[A[i] - 1] : B[A[i] - 1]));
                }
            }
        }
        ll mini = LONG_LONG_MAX;
        fr(i, 0, k + 1)
        {
            mini = min(mini, dp[n][i]);
        }
        cout << mini << endl;
    }
}