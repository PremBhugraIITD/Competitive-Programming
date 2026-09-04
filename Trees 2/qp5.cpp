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

void dfs(ll curr, ll parent, vector<vll> &adj, vll &depth, vll &A, vll &subtree_sum)
{
    if (parent != 0)
    {
        depth[curr] = depth[parent] + 1;
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, depth, A, subtree_sum);
            subtree_sum[curr] += subtree_sum[neighbor];
        }
    }
    subtree_sum[curr] += A[curr];
}

void dfs2(ll curr, ll parent, vector<vll> &adj, vll &depth, vll &ans, vll &subtree_sum, ll &total)
{
    if (parent != 0)
    {
        ans[curr] = ans[parent] + total - 2 * subtree_sum[curr];
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs2(neighbor, curr, adj, depth, ans, subtree_sum, total);
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
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vll depth(n + 1, 0);
        vll subtree_sum(n + 1, 0);
        dfs(1, 0, adj, depth, A, subtree_sum);
        vll ans(n + 1, 0);
        fr(i, 1, n)
        {
            ans[1] += depth[i] * A[i];
        }
        ll total = subtree_sum[1];
        dfs2(1, 0, adj, depth, ans, subtree_sum, total);
        ll maxi = 0;
        fr(i, 1, n)
        {
            maxi = max(maxi, ans[i]);
        }
        cout << maxi << endl;
        // printVectorSet(ans);
    }
}