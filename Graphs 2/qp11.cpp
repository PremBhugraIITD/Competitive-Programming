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

void dfs(ll source, vector<set<ll>> &adj, vb &visited)
{
    visited[source] = true;
    for (auto &neighbor : adj[source])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

pair<bool, pll> isCycle(ll source, ll parent, vector<set<ll>> &adj, vb &visited)
{
    visited[source] = true;
    for (auto &neighbor : adj[source])
    {
        if (!visited[neighbor])
        {
            pair<bool, pll> temp = isCycle(neighbor, source, adj, visited);
            if (temp.first)
            {
                return temp;
            }
        }
        else if (neighbor != parent)
        {
            return {true, {source, neighbor}};
        }
    }
    return {false, {0, 0}};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<set<ll>> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        vll components;
        vb visited(n + 1, false);
        fr(source, 1, n)
        {
            if (!visited[source])
            {
                dfs(source, adj, visited);
                components.pb(source);
            }
        }
        if (components.size() > 1)
        {
            vpll removed, added;
            for (auto &i : components)
            {
                vb visited2(n + 1, false);
                pair<bool, pll> temp = isCycle(i, 0, adj, visited2);
                while (temp.first)
                {
                    ll u = temp.second.first, v = temp.second.second;
                    adj[u].erase(v);
                    adj[v].erase(u);
                    removed.pb({u, v});
                    visited2.assign(n + 1, false);
                    temp = isCycle(i, 0, adj, visited2);
                }
                if (i != 1)
                {
                    added.pb({1, i});
                }
            }
            cout << removed.size() << endl;
            fr(i, 0, removed.size() - 1)
            {
                cout << removed[i].first << " " << removed[i].second << " " << added[i].first << " " << added[i].second << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
