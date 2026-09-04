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
        ll n;
        cin >> n;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        vector<vector<vector<ld>>> dp(n + 1, vector<vector<ld>>(n + 1, vector<ld>(n + 1, 0)));
        dp[0][0][0] = 0;
        fr(k, 0, n + 1)
        {
            fr(j, 0, n + 1)
            {
                fr(i, 0, n + 1)
                {
                    if (i == 0 && j == 0 && k == 0)
                    {
                        continue;
                    }
                    else if (i + j + k > n)
                    {
                        continue;
                    }
                    else
                    {
                        ld numerator = n;
                        if (i > 0)
                        {
                            numerator += i * dp[i - 1][j][k];
                        }
                        if (j > 0)
                        {
                            numerator += j * dp[i + 1][j - 1][k];
                        }
                        if (k > 0)
                        {
                            numerator += k * dp[i][j + 1][k - 1];
                        }
                        dp[i][j][k] = numerator / (i + j + k);
                    }
                }
            }
        }
        ll a = 0, b = 0, c = 0;
        fr(i, 0, n)
        {
            if (A[i] == 1)
            {
                a++;
            }
            else if (A[i] == 2)
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        cout << fixed << setprecision(10) << dp[a][b][c] << endl;
    }
}