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
        ll n, k;
        cin >> n >> k;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vvll dp(n, k + 1, 0);
        // dp[i][j] = Number of valid ways of distributing j candies among the first i students
        fr(i, 0, n)
        {
            dp[i][0] = 1;
        }
        fr(i, 1, A[0] + 1)
        {
            dp[0][i] = 1;
        }
        fr(i, 1, n)
        {
            vll prefixSum;
            prefixSum.pb(dp[i - 1][0]);
            fr(j, 1, k + 1)
            {
                prefixSum.pb((prefixSum.back() + dp[i - 1][j]) % mod);
            }
            fr(j, 1, k + 1)
            {
                dp[i][j] = (prefixSum[j] - (j - A[i] - 1 >= 0 ? prefixSum[j - A[i] - 1] : 0) + mod) % mod;
            }
        }
        cout << dp[n - 1][k] << endl;
    }
}