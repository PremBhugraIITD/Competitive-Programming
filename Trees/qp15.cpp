#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) <= (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define printVectorSet(v) \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define printPairVectorMap(v) \
    for (auto &x : v)         \
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
        ll n, q;
        cin >> n >> q;
        ll root = (n + 1) / 2;
        fr(i, 1, q)
        {
            ll u;
            cin >> u;
            mll parent;
            map<ll, pll> left_right;
            ll curr = root;
            ll l = 1, r = n;
            left_right[root] = {1, n};
            while (curr != u)
            {
                if (curr < u)
                {
                    ll right = curr + (r - curr - 1) / 2 + 1;
                    l = curr + 1;
                    parent[right] = curr;
                    curr = right;
                    left_right[curr] = {l, r};
                }
                else
                {
                    ll left = curr - (curr - l - 1) / 2 - 1;
                    r = curr - 1;
                    parent[left] = curr;
                    curr = left;
                    left_right[curr] = {l, r};
                }
            }
            // cout << curr << " " << l << " " << r << endl;
            string s;
            cin >> s;
            ll ans = u;
            fr(i, 0, s.size() - 1)
            {
                char c = s[i];
                if (c == 'U')
                {
                    if (ans != root)
                    {
                        ans = parent[ans];
                        l = left_right[ans].first;
                        r = left_right[ans].second;
                    }
                }
                else if (c == 'R')
                {
                    if (l != r)
                    {
                        ll right = ans + (r - ans - 1) / 2 + 1;
                        l = ans + 1;
                        parent[right] = ans;
                        ans = right;
                        left_right[ans] = {l, r};
                    }
                }
                else
                {
                    if (l != r)
                    {
                        ll left = ans - (ans - l - 1) / 2 - 1;
                        r = ans - 1;
                        parent[left] = ans;
                        ans = left;
                        left_right[ans] = {l, r};
                    }
                }
                // cout << c << " " << ans << " " << l << " " << r << endl;
            }
            cout << ans << endl;
        }
    }
}