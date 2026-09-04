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
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    vector<vll> dp(n, vll(n));
    fr(i, 0, n)
    {
        dp[i][i] = A[i];
    }
    fr(i, 0, n - 1)
    {
        dp[i][i + 1] = max(A[i], A[i + 1]);
    }
    fr(length, 3, n + 1)
    {
        for (ll i = 0; i + length - 1 <= n - 1; i++)
        {
            ll j = i + length - 1;
            dp[i][j] = max(A[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), A[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    cout << dp[0][n - 1] << endl;
}