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

void binary_lifting(ll curr, ll p, vector<vll> &adj, vector<vll> &parent)
{
    parent[curr][0] = p;
    fr(i, 1, 17)
    {
        parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != p)
        {
            binary_lifting(neighbor, curr, adj, parent);
        }
    }
}

ll kthAncestor(ll x, ll k, vector<vll> &parent)
{
    ll curr = x;
    fr(i, 0, 17)
    {
        if (k & (1 << i))
        {
            curr = parent[curr][i];
        }
    }
    if (curr == 0)
    {
        return -1;
    }
    else
    {
        return curr;
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
        ll n, q;
        cin >> n >> q;
        vector<vll> adj(n + 1);
        fr(i, 2, n)
        {
            ll p;
            cin >> p;
            adj[p].pb(i);
            adj[i].pb(p);
        }
        vvll parent(n + 1, (ll)18, (ll)0);
        binary_lifting(1, 0, adj, parent);
        fr(i, 1, q)
        {
            ll x, k;
            cin >> x >> k;
            cout << kthAncestor(x, k, parent) << endl;
        }
    }
}