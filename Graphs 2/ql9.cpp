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

void dfs(ll source, vvll &adj, vb &visited, vll &component)
{
    visited[source] = true;
    component.pb(source);
    for (auto &neighbor : adj[source])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, component);
        }
    }
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vvll adj(n + 1);
        fr(i, 1, m)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vb ans(n + 1, true);
        DSU dsu(n);
        ll components = 0;
        vb isPresent(n + 1, false);
        frr(i, n, 1)
        {
            ll curr = A[i];
            isPresent[curr] = true;
            ll final_components = components;
            components++;
            for (auto &j : adj[curr])
            {
                if (isPresent[j])
                {
                    if (dsu.find_set(curr) != dsu.find_set(j))
                    {
                        components--;
                    }
                    dsu.union_sets(curr, j);
                }
            }
            if (final_components >= 2)
            {
                ans[i] = false;
            }
        }
        if (components >= 2)
        {
            ans[0] = false;
        }
        fr(i, 0, n - 1)
        {
            if (ans[i])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}