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

void binary_lifting(ll curr, ll p, vector<vll> &adj, vector<vll> &parent, vector<vll> &minimum, vll &depth)
{
    if (p != 0)
    {
        depth[curr] = depth[p] + 1;
    }
    parent[curr][0] = p;
    fr(i, 1, 17)
    {
        parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
    }
    if (p != 0)
    {
        minimum[curr][0] = min(curr, p);
    }
    else
    {
        minimum[curr][0] = curr;
    }
    fr(i, 1, 17)
    {
        minimum[curr][i] = min(minimum[curr][i - 1], minimum[parent[curr][i - 1]][i - 1]);
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != p)
        {
            binary_lifting(neighbor, curr, adj, parent, minimum, depth);
        }
    }
}

ll minValue(ll a, ll b, vll &depth, vector<vll> &parent, vector<vll> &minimum)
{
    ll ans = min(a, b);
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    ll diff = depth[a] - depth[b];
    fr(i, 0, 17)
    {
        if (diff & (1 << i))
        {
            ans = min(ans, minimum[a][i]);
            a = parent[a][i];
        }
    }
    if (a != b)
    {
        frr(i, 17, 0)
        {
            if (parent[a][i] != parent[b][i])
            {
                ans = min({ans, minimum[a][i], minimum[b][i]});
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        ans = min({ans, minimum[a][0], minimum[b][0]});
    }
    return ans;
}

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
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vvll parent(n + 1, 18, 0);
        vvll minimum(n + 1, 18, INT_MAX);
        vll depth(n + 1, 0);
        binary_lifting(1, 0, adj, parent, minimum, depth);
        fr(i, 1, q)
        {
            ll a, b;
            cin >> a >> b;
            cout << minValue(a, b, depth, parent, minimum) << "\n";
        }
    }
}