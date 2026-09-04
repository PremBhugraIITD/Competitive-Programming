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
        ll n, h, l, r;
        cin >> n >> h >> l >> r;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vvll dp(n, h, -1);
        // dp[i][j] = Maximum number of good sleeping times till the ith turn when the sleeping time on the ith turn is the jth hour
        dp[0][A[0] - 1] = A[0] - 1 >= l && A[0] - 1 <= r;
        dp[0][A[0]] = A[0] >= l && A[0] <= r;
        fr(i, 1, n)
        {
            fr(j, 0, h)
            {
                if (dp[i - 1][(j - A[i] + h) % h] != -1)
                {
                    dp[i][j] = max(dp[i][j], (j >= l && j <= r ? 1 : 0) + dp[i - 1][(j - A[i] + h) % h]);
                }
                if (dp[i - 1][(j - (A[i] - 1) + h) % h] != -1)
                {
                    dp[i][j] = max(dp[i][j], (j >= l && j <= r ? 1 : 0) + dp[i - 1][(j - (A[i] - 1) + h) % h]);
                }
            }
        }
        ll maxi = -1;
        fr(i, 0, h)
        {
            maxi = max(maxi, dp[n - 1][i]);
        }
        cout << maxi << endl;
    }
}