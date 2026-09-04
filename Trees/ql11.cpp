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

bool dfs(ll curr, ll parent, vector<vll> &adj, ll target, ll &c, vll &subtree)
{
    bool found = false;
    if (curr == target)
    {
        found = true;
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            if (dfs(neighbor, curr, adj, target, c, subtree))
            {
                c = subtree[neighbor];
                found = true;
            }
            subtree[curr] += subtree[neighbor];
        }
    }
    subtree[curr]++;
    return found;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ll total = n * (n - 1);
        vll subtree(n + 1, 0);
        ll left = 0;
        dfs(x, -1, adj, y, left, subtree);
        // printVectorSet(subtree);
        // cout << left << endl;
        left = n - left;
        subtree.assign(n + 1, 0);
        ll right = 0;
        dfs(y, -1, adj, x, right, subtree);
        // printVectorSet(subtree);
        // cout << right << endl;
        right = n - right;
        ll discarded = left * right;
        cout << total - discarded << endl;
    }
}