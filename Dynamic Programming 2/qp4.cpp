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
    ll x = 1e3;
    vll moves(x + 1, LONG_LONG_MAX);
    moves[1] = 0;
    fr(i, 1, x + 1)
    {
        frr(j, i, 1)
        {
            ll next = i + i / j;
            if (next <= x)
            {
                moves[next] = min(moves[next], 1 + moves[i]);
            }
            else
            {
                break;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll A(n), B(n);
        ll temp = 0;
        fr(i, 0, n)
        {
            cin >> A[i];
            temp += moves[A[i]];
        }
        fr(i, 0, n)
        {
            cin >> B[i];
        }
        k = min(k, temp);
        vll dp(k + 1, 0);
        fr(i, 0, n)
        {
            ll m = moves[A[i]];
            frr(j, k, m)
            {
                dp[j] = max(dp[j], dp[j - m] + B[i]);
            }
        }
        cout << dp[k] << endl;
    }
}