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

void dfs(ll curr, vb &visited, vector<vpll> &adj, stack<ll> &st)
{
    visited[curr] = true;
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor.first])
        {
            dfs(neighbor.first, visited, adj, st);
        }
    }
    st.push(curr);
}

void reverse_dfs(ll curr, vll &scc, vector<vpll> &adj, ll count)
{
    scc[curr] = count;
    for (auto &neighbor : adj[curr])
    {
        if (!scc[neighbor.first])
        {
            reverse_dfs(neighbor.first, scc, adj, count);
        }
    }
}

ll value(ll x)
{
    ll l = 0, r = x;
    ll n = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (mid * (mid + 1) <= 2 * x)
        {
            n = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    // n is the highest n such that 2 * x >= n * (n + 1)
    return (x * (n + 1) - (n * (n + 1) * (n + 1)) / 2 + (n * (n + 1) * (2 * n + 1)) / 6);
}

void dfs3(ll curr, vb &visited, vvll &adj, vll &dp, vll &scc_value, map<pll, ll> &edges)
{
    visited[curr] = true;
    dp[curr] = scc_value[curr];
    ll maxi = 0;
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs3(neighbor, visited, adj, dp, scc_value, edges);
        }
        maxi = max(maxi, edges[{curr, neighbor}] + dp[neighbor]);
    }
    dp[curr] += maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x = 1e8;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vpll> adj(n + 1);
        vector<vpll> transpose_adj(n + 1);
        fr(i, 1, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            transpose_adj[v].pb({u, w});
        }
        ll s;
        cin >> s;
        vb visited(n + 1, false);
        stack<ll> st;
        fr(i, 1, n)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, st);
            }
        }
        ll count = 0;
        vll scc(n + 1, 0);
        while (!st.empty())
        {
            ll curr = st.top();
            st.pop();
            if (!scc[curr])
            {
                count++;
                reverse_dfs(curr, scc, transpose_adj, count);
            }
        }
        vector<set<ll>> scc_nodes(count + 1);
        vll scc_value(count + 1, 0); // Value of each scc
        fr(u, 1, n)
        {
            for (auto &neighbor : adj[u])
            {
                ll v = neighbor.first, w = neighbor.second;
                if (scc[u] == scc[v])
                { // If u and v both belong to the same scc then the edge u->v lies in that scc
                    scc_value[scc[u]] += value(w);
                    // cout << value(w) << endl;
                }
            }
        }
        vvll condensed_adj(count + 1);
        map<pll, ll> edges;
        fr(i, 1, n)
        {
            for (auto &neighbor : adj[i])
            {
                ll u = scc[i], v = scc[neighbor.first], w = neighbor.second; // weight of edge from i to neighbor
                if (u != v)                                                  // If i and neighbor belong to the same scc, do nothing
                {
                    if (!edges.count({u, v})) // If the nodes corresponding to that edge already exist within the condensed_adj, don't add them again
                    {
                        condensed_adj[u].pb(v);
                    }
                    edges[{u, v}] = max(edges[{u, v}], w);
                }
            }
        }
        vll dp(count + 1, 0);
        visited.assign(count + 1, false);
        fr(i, 1, count)
        {
            if (!visited[i])
            {
                dfs3(i, visited, condensed_adj, dp, scc_value, edges);
            }
        }
        cout << dp[scc[s]] << endl;
    }
}