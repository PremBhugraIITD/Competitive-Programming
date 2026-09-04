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

void binary_lifting(ll curr, ll p, vector<vll> &adj, vector<vll> &parent, vll &depth)
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
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != p)
        {
            binary_lifting(neighbor, curr, adj, parent, depth);
        }
    }
}

ll kthAncestor(ll x, ll k, vector<vll> &parent)
{
    ll curr = x;
    fr(i, 0, 17)
    {
        if (k & (1 << i))
        {
            curr = parent[curr][i];
        }
    }
    if (curr == 0)
    {
        return -1;
    }
    else
    {
        return curr;
    }
}

ll lca(ll a, ll b, vll &depth, vector<vll> &parent)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    ll diff = depth[a] - depth[b];
    a = kthAncestor(a, diff, parent);
    if (a == b)
    {
        return a;
    }
    else
    {
        frr(i, 17, 0)
        {
            if (parent[a][i] == parent[b][i])
            {
                continue;
            }
            else
            {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        return parent[a][0];
    }
}

void dfs(ll curr, ll parent, vector<vll> &adj, vll &ans)
{
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, ans);
            ans[curr] += ans[neighbor];
        }
    }
}

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
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vvll parent(n + 1, (ll)18, (ll)0);
        vll depth(n + 1, 0);
        binary_lifting(1, 0, adj, parent, depth);
        vll ans(n + 1, 0);
        fr(i, 1, m)
        {
            ll a, b;
            cin >> a >> b;
            ans[a]++;
            ans[b]++;
            ll l = lca(a, b, depth, parent);
            ans[l]--;
            ans[parent[l][0]] -= parent[l][0] != 0;
        }
        dfs(1, 0, adj, ans);
        fr(i, 1, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}