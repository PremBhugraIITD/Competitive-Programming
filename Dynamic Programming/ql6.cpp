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
        cout << x.first << " " << x.second << endl;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        string t;
        cin >> t;
        ll n;
        cin >> n;
        set<pair<string, ll>> A;
        fr(i, 0, n)
        {
            string temp;
            cin >> temp;
            A.insert({temp, i});
        }
        ll m = t.size();
        vll dp(m + 1, INT_MAX);
        vector<pair<ll, pll>> parent(m + 1);
        dp[0] = 0;
        fr(i, 0, m + 1)
        {
            if (dp[i] == INT_MAX)
            {
                continue;
            }
            else
            {
                for (auto &s : A)
                {
                    ll len = s.first.length();
                    for (ll start = i; (start + len - 1 >= i) && (start >= 0); start--)
                    {
                        if ((start + len - 1 <= m - 1) && (t.substr(start, len) == s.first))
                        {
                            if (dp[start + len] >= dp[i] + 1)
                            {
                                dp[start + len] = dp[i] + 1;
                                parent[start + len] = {i, {s.second + 1, start + 1}};
                            }
                        }
                    }
                }
            }
        }
        if (dp[m] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[m] << endl;
            vpll ans;
            ll curr = m;
            while (curr)
            {
                ans.pb(parent[curr].second);
                curr = parent[curr].first;
            }
            fr(i, 0, ans.size())
            {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }
}