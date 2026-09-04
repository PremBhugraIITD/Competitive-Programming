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

ll dfs(ll curr, ll parent, vector<vll> &adj, ll x, ll &components)
{
    ll size = 0;
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            size += dfs(neighbor, curr, adj, x, components);
        }
    }
    size++;
    if (size >= x)
    {
        components++;
        return 0;
    }
    else
    {
        return size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll l = 1, r = n;
        ll ans = 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll components = 0;
            dfs(1, -1, adj, mid, components);
            if (components >= k + 1)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}