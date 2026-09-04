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
        vll B(n);
        fr(i, 0, n)
        {
            cin >> B[i];
        }
        vll dp(x + 1, 0);
        // dp[i] = Maximum number of pages we can buy under i budget
        dp[0] = 0;
        fr(i, 0, n)
        {
            ll price = A[i];
            ll pages = B[i];
            frr(j, x, price)
            {
                dp[j] = max(dp[j], pages + dp[j - price]);
            }
        }
        // fr(i, 1, x + 1)
        // {
        //     cout << dp[i] << endl;
        // }
        cout << dp[x] << endl;
    }
}