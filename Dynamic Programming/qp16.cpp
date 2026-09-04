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
        string start, end;
        cin >> start >> end;
        ll k;
        cin >> k;
        ll n = start.length();
        string temp = start + start;
        ll count = 0;
        fr(i, 0, n)
        {
            if (end == temp.substr(i, n))
            {
                count++;
            }
        }
        if (count)
        {
            vvll dp(2, k + 1, 0);
            // dp[0][i] = Number of ways in which start can be converted to end in exactly i operations
            // dp[1][i] = Number of ways in which start cannot be converted to end in exactly i operations
            dp[0][0] = start == end;
            dp[1][0] = 1 - dp[0][0];
            ll count2 = n - count;
            fr(i, 1, k + 1)
            {
                ll temp1 = ((dp[1][i - 1] % mod) * (count % mod)) % mod;
                ll temp2 = ((dp[0][i - 1] % mod) * ((count - 1) % mod)) % mod;
                dp[0][i] = (temp1 + temp2) % mod;
                temp1 = ((dp[0][i - 1] % mod) * (count2 % mod)) % mod;
                temp2 = ((dp[1][i - 1] % mod) * ((count2 - 1) % mod)) % mod;
                dp[1][i] = (temp1 + temp2) % mod;
            }
            cout << dp[0][k] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}