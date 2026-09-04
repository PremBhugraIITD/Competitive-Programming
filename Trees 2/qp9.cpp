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
    vvll() = default;
    vvll(ll rows) : vector<vector<ll>>(rows) {}
    vvll(ll rows, ll cols) : vector<vector<ll>>(rows, vector<ll>(cols, 0)) {}
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

void binary_lifting(ll curr, ll p, vector<vll> &adj, vector<vll> &parent, vll &depth, ll &diameter, vll &farthest_leaf)
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
            binary_lifting(neighbor, curr, adj, parent, depth, diameter, farthest_leaf);
            diameter = max(diameter, farthest_leaf[curr] + farthest_leaf[neighbor] + 1);
            farthest_leaf[curr] = max(farthest_leaf[curr], 1 + farthest_leaf[neighbor]);
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        vvll adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        if (db <= 2 * da)
        {
            cout << "Alice" << endl;
        }
        else
        {
            vll depth(n + 1, 0);
            vvll parent(n + 1, 18, 0);
            ll diameter = 0;
            vll farthest_leaf(n + 1, 0);
            binary_lifting(1, 0, adj, parent, depth, diameter, farthest_leaf);
            ll l = lca(a, b, depth, parent);
            ll dist = depth[a] + depth[b] - 2 * depth[l];
            if (diameter <= 2 * da)
            {
                cout << "Alice" << endl;
            }
            else if (dist <= da)
            {
                cout << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
    }
}