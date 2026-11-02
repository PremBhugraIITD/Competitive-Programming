#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
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
    vvll() = default;
    vvll(ll rows) : vector<vector<ll>>(rows) {}
    vvll(ll rows, ll cols) : vector<vector<ll>>(rows, vector<ll>(cols, 0)) {}
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

class vvb : public vector<vector<bool>>
{
public:
    vvb() = default;
    vvb(ll rows) : vector<vector<bool>>(rows) {}
    vvb(ll rows, ll cols) : vector<vector<bool>>(rows, vector<bool>(cols, false)) {}
    vvb(ll rows, ll cols, bool val) : vector<vector<bool>>(rows, vector<bool>(cols, val)) {}
};

class vvc : public vector<vector<char>>
{
public:
    vvc() = default;
    vvc(ll rows) : vector<vector<char>>(rows) {}
    vvc(ll rows, ll cols) : vector<vector<char>>(rows, vector<char>(cols, 'a')) {}
    vvc(ll rows, ll cols, char val) : vector<vector<char>>(rows, vector<char>(cols, val)) {}
};

class vvs : public vector<vector<string>>
{
public:
    vvs() = default;
    vvs(ll rows) : vector<vector<string>>(rows) {}
    vvs(ll rows, ll cols) : vector<vector<string>>(rows, vector<string>(cols, "a")) {}
    vvs(ll rows, ll cols, string val) : vector<vector<string>>(rows, vector<string>(cols, val)) {}
};

class DSU
{
public:
    vll parent, rank;
    DSU(ll n)
    {
        rank.assign(n + 1, 0);
        fr(i, 0, n)
        {
            parent.pb(i);
        }
    }
    ll find_set(ll x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
    void union_sets(ll x, ll y)
    {
        x = find_set(x);
        y = find_set(y);
        if (x != y)
        {
            if (rank[x] > rank[y])
            {

                parent[y] = x;
            }
            else if (rank[x] < rank[y])
            {
                parent[x] = y;
            }
            else
            {
                parent[y] = x;
                rank[x]++;
            }
        }
    }
};

void binary_lifting(ll curr, ll p, ll w, vb &visited, vector<vpll> &adj, vvll &parent, vvll &max_edge_weight, vll &depth)
{
    visited[curr] = true;
    if (p)
    {
        depth[curr] = depth[p] + 1;
    }
    parent[curr][0] = p;
    fr(i, 1, 17)
    {
        parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
    }
    max_edge_weight[curr][0] = w;
    fr(i, 1, 17)
    {
        max_edge_weight[curr][i] = max(max_edge_weight[curr][i - 1], max_edge_weight[parent[curr][i - 1]][i - 1]);
    }
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor.first])
        {
            binary_lifting(neighbor.first, curr, neighbor.second, visited, adj, parent, max_edge_weight, depth);
        }
    }
}

ll max_weight_edge(ll a, ll b, vvll &parent, vll &depth, vvll &max_edge_weight)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    ll diff = depth[a] - depth[b];
    ll ans = 0;
    fr(i, 0, 17)
    {
        if (diff & (1 << i))
        {
            ans = max(ans, max_edge_weight[a][i]);
            a = parent[a][i];
        }
    }
    if (a == b)
    {
        return ans;
    }
    else
    {
        frr(i, 17, 0)
        {
            if (parent[a][i] != parent[b][i])
            {
                ans = max(ans, max_edge_weight[a][i]);
                ans = max(ans, max_edge_weight[b][i]);
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        return max({ans, max_edge_weight[a][0], max_edge_weight[b][0]});
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
        vector<vpll> adj(n + 1);
        vvll edges;
        fr(i, 1, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
            edges.pb({w, u, v});
        }
        sort(edges);
        ll mini = 0;
        set<vll> excluded;
        vector<vpll> mst_adj(n + 1);
        DSU dsu(n);
        fr(i, 0, m - 1)
        {
            ll u = edges[i][1], v = edges[i][2], w = edges[i][0];
            if (dsu.find_set(u) != dsu.find_set(v))
            {
                mini += w;
                mst_adj[u].pb({v, w});
                mst_adj[v].pb({u, w});
                dsu.union_sets(u, v);
            }
            else
            {
                excluded.insert({u, v, w});
            }
        }
        vb visited(n + 1, false);
        vll depth(n + 1, 0);
        vvll parent(n + 1, 18, 0);
        vvll max_edge_weight(n + 1, 18, 0);
        binary_lifting(1, 0, 0, visited, mst_adj, parent, max_edge_weight, depth);
        ll mini2 = LLONG_MAX;
        for (auto &edge : excluded)
        {
            ll u = edge[0], v = edge[1], w = edge[2];
            mini2 = min(mini2, mini + w - max_weight_edge(u, v, parent, depth, max_edge_weight));
        }
        cout << mini2 << endl;
    }
}