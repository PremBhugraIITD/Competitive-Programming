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

void dfs(ll curr, ll parent, vector<vll> &adj, vpll &range, vll &operations, vll &value)
{
    ll obtainable_r = 0;
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, range, operations, value);
            operations[curr] += operations[neighbor];
            ll obtainable_l = 0;
            obtainable_r += value[neighbor];
            ll curr_l = range[curr].first, curr_r = range[curr].second;
            ll l = max(curr_l, obtainable_l), r = min(curr_r, obtainable_r);
            if (l <= r)
            {
                value[curr] = r;
            }
        }
    }
    if (!value[curr])
    {
        value[curr] = range[curr].second;
        operations[curr]++;
    }
    // cout << curr << " " << value[curr] << " " << operations[curr] << endl;
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
        fr(i, 2, n)
        {
            ll p;
            cin >> p;
            adj[p].pb(i);
            adj[i].pb(p);
        }
        vpll range(n + 1);
        fr(i, 1, n)
        {
            ll l, r;
            cin >> range[i].first >> range[i].second;
        }
        vll operations(n + 1, 0);
        vll value(n + 1, 0);
        dfs(1, -1, adj, range, operations, value);
        cout << operations[1] << endl;
    }
}