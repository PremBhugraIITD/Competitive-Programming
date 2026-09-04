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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = LONG_LONG_MAX;
        fr(second, 0, 2)
        {
            fr(first, 0, 2)
            {
                vector<vector<vll>> dp(n, vector<vll>(2, vll(2, LONG_LONG_MAX)));
                // dp[i][j][k] = Mininum number of people he should talk to till the ith index when the character at the current index is j and that at the previous index is k
                ll cost_first = (s[0] == (first ? 'R' : 'L')) ? 0 : 1;
                ll cost_second = (s[1] == (second ? 'R' : 'L')) ? 0 : 1;
                dp[1][second][first] = cost_first + cost_second;
                fr(i, 2, n)
                {
                    fr(curr, 0, 2)
                    {
                        fr(prev1, 0, 2)
                        {
                            fr(prev2, 0, 2)
                            {
                                if (curr == prev1 && prev1 == prev2)
                                {
                                    continue;
                                }
                                else
                                {
                                    if (dp[i - 1][prev1][prev2] != LONG_LONG_MAX)
                                    {
                                        ll cost = (s[i] == (curr ? 'R' : 'L')) ? 0 : 1;
                                        dp[i][curr][prev1] = min(dp[i][curr][prev1], cost + dp[i - 1][prev1][prev2]);
                                    }
                                }
                            }
                        }
                    }
                }
                fr(last1, 0, 2)
                {
                    fr(last2, 0, 2)
                    {
                        if (last2 == last1 && last1 == first)
                        {
                            continue;
                        }
                        else if (last1 == first && first == second)
                        {
                            continue;
                        }
                        else
                        {
                            ans = min(ans, dp[n - 1][last1][last2]);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}