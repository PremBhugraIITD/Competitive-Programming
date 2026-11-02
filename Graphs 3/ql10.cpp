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

void dfs(ll curr, vvll &adj, vb &visited, stack<ll> &st)
{
    visited[curr] = true;
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(curr);
}

void reverse_dfs(ll curr, vvll &adj, vll &scc, ll &count)
{
    scc[curr] = count;
    for (auto &neighbor : adj[curr])
    {
        if (!scc[neighbor])
        {
            reverse_dfs(neighbor, adj, scc, count);
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
        vvll adj(n + 1);
        fr(i, 1, m)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
        }
        stack<ll> st;
        vb visited(n + 1, false);
        // First obtain the order of nodes according to dfs out-times (reverse of the topological sort)
        fr(i, 1, n)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }
        vvll transpose_adj(n + 1);
        fr(i, 1, n)
        {
            for (auto &v : adj[i])
            {
                transpose_adj[v].pb(i);
            }
        }
        // Now, reverse the edges, the scc remain unaffected
        ll count = 0;      // Number of scc
        vll scc(n + 1, 0); // ID of each scc
        // Process each scc in the order of the stack, each reverse_dfs call remains restricted to one scc and covers the whole scc
        while (!st.empty())
        {
            ll top = st.top();
            st.pop();
            if (!scc[top])
            {
                count++;
                reverse_dfs(top, transpose_adj, scc, count);
            }
        }
        // Print scc ids of all nodes
        fr(i, 1, n)
        {
            cout << i << " " << scc[i] << endl;
        }
        vvll condensed_adj(count + 1);
        set<pair<ll, ll>> edges; // Set used to prevent storing duplicate edges (because of multiple nodes in one scc having edges to multiple nodes in another scc)
        fr(curr, 1, n)
        {
            ll u = scc[curr];
            for (auto &neighbor : adj[curr])
            {
                ll v = scc[neighbor];
                if ((u != v) && !edges.count({u, v}))
                {
                    edges.insert({u, v});
                    condensed_adj[u].pb(v);
                }
            }
        }
        // Print the condensed graph
        fr(curr, 1, count)
        {
            cout << curr << ": ";
            for (auto &neighbor : condensed_adj[curr])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}