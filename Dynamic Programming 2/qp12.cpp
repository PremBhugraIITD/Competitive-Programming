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
        string s;
        cin >> s;
        if (s.length() <= 6)
        {
            cout << 0 << endl;
            continue;
        }
        s = s.substr(5, s.length() - 5);
        ll n = s.length();
        // cout << s << endl;
        set<string> ans;
        vector<vector<bool>> dp(n, vector<bool>(2, false));
        // dp[i][j] = If we can make a valid split from index i to end with the first string of length j + 2;
        dp[n - 2][0] = true;
        ans.insert(s.substr(n - 2, 2));
        if (n - 3 >= 0)
        {
            dp[n - 3][1] = true;
            ans.insert(s.substr(n - 3, 3));
        }
        frr(i, n - 4, 0)
        {
            if (dp[i + 2][0] || dp[i + 2][1])
            {
                string curr = s.substr(i, 2);
                if (dp[i + 2][1])
                {
                    ans.insert(curr);
                    dp[i][0] = true;
                }
                else
                {
                    string next = s.substr(i + 2, 2);
                    if (next != curr)
                    {
                        ans.insert(curr);
                        dp[i][0] = true;
                    }
                }
            }
            if (dp[i + 3][0] || dp[i + 3][1])
            {
                string curr = s.substr(i, 3);
                if (dp[i + 3][0])
                {
                    ans.insert(curr);
                    dp[i][1] = true;
                }
                else
                {
                    string next = s.substr(i + 3, 3);
                    if (next != curr)
                    {
                        ans.insert(curr);
                        dp[i][1] = true;
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for (auto &i : ans)
        {
            cout << i << endl;
        }
    }
}