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
        ll m, x;
        cin >> m >> x;
        vpll A(m);
        ll maxi_happiness = 0;
        fr(i, 0, m)
        {
            cin >> A[i].first >> A[i].second;
            maxi_happiness += A[i].second;
        }
        vll dp(maxi_happiness + 1, LONG_LONG_MAX);
        // dp[i] = Minimum cost to achieve j happiness
        dp[0] = 0;
        ll budget = 0;
        fr(i, 0, m)
        {
            ll c = A[i].first, h = A[i].second;
            frr(j, maxi_happiness, h)
            {
                if (dp[j - h] != LONG_LONG_MAX && c + dp[j - h] <= budget)
                {
                    dp[j] = min(dp[j], c + dp[j - h]);
                }
            }
            budget += x;
        }
        ll ans = 0;
        frr(i, maxi_happiness, 0)
        {
            if (dp[i] != LONG_LONG_MAX)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}