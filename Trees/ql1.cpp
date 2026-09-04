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
#define printVector(v)    \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define printPairVector(v) \
    for (auto &x : v)      \
        cout << x.first << ' ' << x.second << endl;
#define mod 1000000007

class vvll : public vector<vector<ll>>
{
public:
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

void dfs(ll curr, ll parent, vector<vll> &adj, vll &res)
{
    res.pb(curr);
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, res);
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
        ll n;
        cin >> n;
        vector<vll> adj(n + 1);
        fr(i, 0, n - 2)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll root = 1;
        vll dfs_traversal;
        dfs(root, -1, adj, dfs_traversal);
        printVector(dfs_traversal);
    }
}

// Input:
// 12
// 1 2
// 1 7
// 1 8
// 2 3
// 2 6
// 8 9
// 8 12
// 3 4
// 3 5
// 9 10
// 9 11

// Output:
// 1 2 3 4 5 6 7 8 9 10 11 12