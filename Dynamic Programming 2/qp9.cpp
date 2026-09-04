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
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        sort(A);
        vvll dp(n, n, LONG_LONG_MAX);
        // dp[i][j] = Minimum total discrepancy for the subarray from i to j
        fr(i, 0, n)
        {
            dp[i][i] = 0;
        }
        fr(len, 2, n + 1)
        {
            for (ll i = 0; i + len - 1 <= n - 1; i++)
            {
                dp[i][i] = 0;
                ll j = i + len - 1;
                dp[i][j] = A[j] - A[i] + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[0][n - 1] << endl;
    }
}