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

bool isLucky(ll n)
{
    while (n)
    {
        ll digit = n % 10;
        if (digit != 4 && digit != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

void dfs(ll curr, ll parent, vvll &adj, set<pll> &lucky, vll &subtree, vll &subtree_lucky_count)
{
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, lucky, subtree, subtree_lucky_count);
            subtree[curr] += subtree[neighbor];
            if (lucky.count({curr, neighbor}))
            {
                subtree_lucky_count[curr] += subtree[neighbor];
            }
            else
            {
                subtree_lucky_count[curr] += subtree_lucky_count[neighbor];
            }
        }
    }
    subtree[curr]++;
}

void dfs2(ll curr, ll parent, vvll &adj, set<pll> &lucky, vll &subtree, vll &subtree_lucky_count, vll &ans, ll &n)
{
    if (parent != 0)
    {
        ans[curr] = subtree_lucky_count[curr];
        if (lucky.count({curr, parent}))
        {
            ans[curr] += n - subtree[curr];
        }
        else
        {
            ans[curr] += ans[parent] - subtree_lucky_count[curr];
        }
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs2(neighbor, curr, adj, lucky, subtree, subtree_lucky_count, ans, n);
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
        vvll adj(n + 1);
        set<pll> lucky;
        fr(i, 1, n - 1)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            adj[x].pb(y);
            adj[y].pb(x);
            if (isLucky(w))
            {
                lucky.insert({x, y});
                lucky.insert({y, x});
            }
        }
        vll subtree(n + 1, 0);
        vll subtree_lucky_count(n + 1, 0);
        dfs(1, 0, adj, lucky, subtree, subtree_lucky_count);
        vll ans(n + 1);
        ans[1] = subtree_lucky_count[1];
        dfs2(1, 0, adj, lucky, subtree, subtree_lucky_count, ans, n);
        ll res = 0;
        fr(i, 1, n)
        {
            res += ans[i] * (ans[i] - 1);
        }
        cout << res << endl;
    }
}