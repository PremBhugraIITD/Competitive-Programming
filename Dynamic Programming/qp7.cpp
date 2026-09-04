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
        vvll dp(n + 1, k + 1, 0);
        // dp[i][j] is the number of valid sequences with the last number as i with length j
        fr(i, 1, n + 1)
        {
            dp[i][1] = 1;
        }
        fr(l, 1, k)
        {
            fr(i, 1, n + 1)
            {
                for (ll j = i; j <= n; j += i)
                {
                    dp[j][l + 1] = (dp[j][l + 1] + dp[i][l]) % mod;
                }
            }
        }
        ll ans = 0;
        fr(i, 0, n + 1)
        {
            ans = (ans + dp[i][k]) % mod;
        }
        cout << ans << endl;
    }
}