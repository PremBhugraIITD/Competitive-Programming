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
    int t, k;
    cin >> t >> k;
    ll x = 2e5;
    vll dp(x + 1, 0);
    // dp[i] = Number of ways he cant eat i flowers in which white flowers are in groups of size k
    dp[0] = 1;
    fr(i, 1, x + 1)
    {
        dp[i] = dp[i - 1];
        if (i >= k)
        {
            dp[i] = (dp[i] + dp[i - k]) % mod;
        }
    }
    // fr(i, 0, 5)
    // {
    //     cout << dp[i] << endl;
    // }
    vll prefixSum(x + 1, 0);
    prefixSum[0] = dp[0];
    prefixSum[1] = dp[1] + dp[0];
    fr(i, 2, x + 1)
    {
        prefixSum[i] = (prefixSum[i - 1] + dp[i]) % mod;
    }
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (prefixSum[b] - prefixSum[a - 1] + mod) % mod << endl;
    }
}