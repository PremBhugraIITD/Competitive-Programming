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

void dfs(ll curr, ll parent, vector<vll> &adj, vll &subtree, vll &depth)
{
    if (parent != 0)
    {
        depth[curr] = depth[parent] + 1;
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, subtree, depth);
            subtree[curr] += subtree[neighbor];
        }
    }
    subtree[curr]++;
}

void dfs2(ll curr, ll parent, vector<vll> &adj, vll &subtree, ll &n, vll &ans)
{
    if (parent != 0)
    {
        ans[curr] = ans[parent] - subtree[curr] + n - subtree[curr];
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs2(neighbor, curr, adj, subtree, n, ans);
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
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vll depth(n + 1, 0);
        vll subtree(n + 1, 0);
        dfs(1, 0, adj, subtree, depth);
        vll ans(n + 1, 0);
        fr(i, 2, n)
        {
            ans[1] += depth[i];
        }
        dfs2(1, 0, adj, subtree, n, ans);
        fr(i, 1, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}