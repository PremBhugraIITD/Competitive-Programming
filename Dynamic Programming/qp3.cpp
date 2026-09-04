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
        ll n;
        cin >> n;
        vector<string> A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vector<vll> dp(n, vll(n, 0));
        dp[0][0] = 1;
        fr(i, 0, n)
        {
            fr(j, 0, n)
            {
                if (A[i][j] == '*')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i - 1 >= 0 && A[i - 1][j] == '.')
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                    }
                    if (j - 1 >= 0 && A[i][j - 1] == '.')
                    {
                        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                    }
                }
            }
        }
        cout << dp[n - 1][n - 1] << endl;
    }
}