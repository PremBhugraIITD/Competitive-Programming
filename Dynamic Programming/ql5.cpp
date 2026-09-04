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
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vll dp(n + 1);
        dp[n] = 0;
        frr(i, n - 1, 0)
        {
            dp[i] = min(1 + dp[i + 1], (i + 1 + A[i] <= n ? dp[i + 1 + A[i]] : INT_MAX));
            // When choosing to keep the element, it is most optimal to keep the next A[i] consecutive elements also.
            // At every index, we have only two choices, either keep the element as a block length, or remove the element. This is because we are assuming at every index that the array starts at that index.
        }
        cout << dp[0] << endl;
    }
}