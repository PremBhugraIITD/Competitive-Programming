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

void dfs(ll curr, ll parent, vector<vll> &adj, vll &distance, ll &maxDistance, ll &ans)
{
    if (parent != -1)
    {
        distance[curr] = distance[parent] + 1;
        if (distance[curr] > maxDistance)
        {
            maxDistance = distance[curr];
            ans = curr;
        }
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, distance, maxDistance, ans);
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
        vll distance(n + 1, 0);
        ll maxDistance = 0;
        ll u = 1;
        dfs(1, -1, adj, distance, maxDistance, u);
        ll v = u;
        distance.assign(n + 1, 0);
        maxDistance = 0;
        dfs(u, -1, adj, distance, maxDistance, v);
        vll ans1(n + 1, 0), ans2(n + 1, 0);
        ll temp;
        dfs(u, -1, adj, ans1, maxDistance, temp);
        dfs(v, -1, adj, ans2, maxDistance, temp);
        fr(i, 1, n)
        {
            cout << max(ans1[i], ans2[i]) << " ";
        }
        cout << endl;
    }
}