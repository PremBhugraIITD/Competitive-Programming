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

void dfs(ll curr, ll parent, vector<vll> &adj, map<pll, pll> &weights, vll &prefixSum_a, vll &prefixSum_b, vll &path)
{
    if (parent != -1)
    {
        prefixSum_a.pb((prefixSum_a.empty() ? 0 : prefixSum_a.back()) + weights[{parent, curr}].first);
        prefixSum_b.pb((prefixSum_b.empty() ? 0 : prefixSum_b.back()) + weights[{parent, curr}].second);
        ll index = upper_bound(prefixSum_b.begin(), prefixSum_b.end(), prefixSum_a.back()) - prefixSum_b.begin();
        index--;
        path[curr] = index + 1;
        // cout << curr << " " << path[curr] << endl;
        // printVectorSet(prefixSum_a);
        // printVectorSet(prefixSum_b);
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, weights, prefixSum_a, prefixSum_b, path);
        }
    }
    if (!prefixSum_a.empty() && !prefixSum_b.empty())
    {
        prefixSum_a.pop_back();
        prefixSum_b.pop_back();
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
        vector<vll> adj(n + 1);
        map<pll, pll> weights;
        fr(i, 2, n)
        {
            ll p, a, b;
            cin >> p >> a >> b;
            adj[p].pb(i);
            adj[i].pb(p);
            weights[{p, i}] = {a, b};
        }
        vll path(n + 1, 0);
        vll prefixSum_a, prefixSum_b;
        dfs(1, -1, adj, weights, prefixSum_a, prefixSum_b, path);
        fr(i, 2, n)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        // cout << weights[{1, 2}].first << " " << weights[{1, 2}].second << endl;
    }
}