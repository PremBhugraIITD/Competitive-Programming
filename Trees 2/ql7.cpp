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

void dfs(ll curr, ll parent, vector<vll> &adj, vll &A, vll &subtree, vll &res)
{
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, A, subtree, res);
            subtree[curr] += subtree[neighbor];
        }
    }
    subtree[curr]++;
    if (parent != 0)
    {
        res[curr] = subtree[curr] * (A[curr] ^ A[parent]);
    }
}

void dfs2(ll curr, ll parent, vector<vll> &adj, vll &A, vll &subtree, vll &ans, ll &n)
{
    if (parent != 0)
    {
        ans[curr] = ans[parent] + (n - 2 * subtree[curr]) * (A[curr] ^ A[parent]);
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs2(neighbor, curr, adj, A, subtree, ans, n);
        }
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
        vll subtree(n + 1, 0);
        vll res(n + 1, 0);
        dfs(1, 0, adj, A, subtree, res);
        vll ans(n + 1, 0);
        fr(i, 1, n)
        {
            ans[1] += res[i];
        }
        dfs2(1, 0, adj, A, subtree, ans, n);
        fr(i, 1, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}