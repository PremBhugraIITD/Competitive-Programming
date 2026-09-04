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
        vvll dp1(n, m, 0), dp2(n, m, 0), dp3(n, m, 0), dp4(n, m, 0);
        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                dp1[i][j] = A[i][j] + max(i - 1 >= 0 ? dp1[i - 1][j] : 0, j - 1 >= 0 ? dp1[i][j - 1] : 0);
            }
        }
        frr(i, n - 1, 0)
        {
            frr(j, m - 1, 0)
            {
                dp2[i][j] = A[i][j] + max(i + 1 <= n - 1 ? dp2[i + 1][j] : 0, j + 1 <= m - 1 ? dp2[i][j + 1] : 0);
            }
        }
        frr(i, n - 1, 0)
        {
            fr(j, 0, m)
            {
                dp3[i][j] = A[i][j] + max(i + 1 <= n - 1 ? dp3[i + 1][j] : 0, j - 1 >= 0 ? dp3[i][j - 1] : 0);
            }
        }
        fr(i, 0, n)
        {
            frr(j, m - 1, 0)
            {
                dp4[i][j] = A[i][j] + max(i - 1 >= 0 ? dp4[i - 1][j] : 0, j + 1 <= m - 1 ? dp4[i][j + 1] : 0);
            }
        }
        // cout << dp1[n - 1][m - 1] << " " << dp2[0][0] << " " << dp3[0][m - 1] << " " << dp4[n - 1][0] << endl;
        ll ans = INT_MIN;
        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                ll ans1 = i - 1 >= 0 && j - 1 >= 0 && i + 1 <= n - 1 && j + 1 <= m - 1 ? dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1] : 0;
                ll ans2 = i - 1 >= 0 && j - 1 >= 0 && i + 1 <= n - 1 && j + 1 <= m - 1 ? dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j] : 0;
                ans = max(ans, max(ans1, ans2));
                // cout << i << " " << j << ": " << ans << endl;
            }
        }
        cout << ans << endl;
    }
}