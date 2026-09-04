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
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vll> A(n, vll(n));
    fr(i, 0, n)
    {
        fr(j, 0, n)
        {
            cin >> A[i][j];
        }
    }
    vector<vll> dp(n, vll(n));
    dp[0][0] = A[0][0];
    fr(i, 0, n)
    {
        fr(j, 0, n)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                dp[i][j] = A[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
            else if (i - 1 < 0 && j - 1 < 0)
            {
                continue;
            }
            else if (i - 1 >= 0)
            {
                dp[i][j] = A[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = A[i][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}