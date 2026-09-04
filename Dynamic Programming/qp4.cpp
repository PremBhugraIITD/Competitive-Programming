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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        set<ll> A;
        fr(i, 0, n)
        {
            ll temp;
            cin >> temp;
            A.insert(temp);
        }
        vll dp(x + 1, INT_MAX);
        dp[0] = 0;
        fr(i, 1, x + 1)
        {
            for (auto &c : A)
            {
                if (i - c >= 0 && dp[i - c] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        if (dp[x] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[x] << endl;
        }
    }
}