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
        ll n, x;
        cin >> n >> x;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        vll dp(n, 0);
        dp[0] = 0;
        dp[1] = 2 * n - 3;
        fr(i, 2, x)
        {
            dp[i] = 2 * dp[i - 1] - dp[i - 2] - 2;
        }
        cout << dp[x - 1] << endl;
    }
}