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
        ll n, m;
        cin >> n >> m;
        vvll A(n, m, 0);
        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                cin >> A[i][j];
            }
        }
        vvll dp(n, m, INT_MAX);
        dp[0][0] = A[0][0];
        map<pll, pll> parent;
        parent[{0, 0}] = {-1, -1};
        ll sum = A[0][0];
        fr(i, 1, n)
        {
            sum += A[i][0];
            dp[i][0] = sum;
            parent[{i, 0}] = {i - 1, 0};
        }
        sum = A[0][0];
        fr(j, 1, m)
        {
            sum += A[0][j];
            dp[0][j] = sum;
            parent[{0, j}] = {0, j - 1};
        }
        fr(i, 1, n)
        {
            fr(j, 1, m)
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = A[i][j] + dp[i][j - 1];
                    parent[{i, j}] = {i, j - 1};
                }
                else
                {
                    dp[i][j] = A[i][j] + dp[i - 1][j];
                    parent[{i, j}] = {i - 1, j};
                }
            }
        }
        cout << dp[n - 1][m - 1] << endl;
        vpll ans;
        pll curr = {n - 1, m - 1};
        ans.pb(curr);
        while (curr != make_pair((ll)0, (ll)0))
        {
            curr = parent[curr];
            ans.pb(curr);
        }
        reverse(ans);
        printPairVector(ans);
    }
}