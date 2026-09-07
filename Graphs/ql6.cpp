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
#define mod 998244353

class vvll : public vector<vector<ll>>
{
public:
    vvll() = default;
    vvll(ll rows) : vector<vector<ll>>(rows) {}
    vvll(ll rows, ll cols) : vector<vector<ll>>(rows, vector<ll>(cols, 0)) {}
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

ll binpow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

bool isBipartite(ll curr, vvll &adj, vll &visited, ll color, ll &c0, ll &c1)
{
    visited[curr] = color;
    bool found = true;
    for (auto &neighbor : adj[curr])
    {
        if (visited[neighbor] == 2)
        {
            if (!isBipartite(neighbor, adj, visited, color ^ 1, c0, c1))
            {
                found = false;
            }
        }
        else if (visited[neighbor] == color)
        {
            found = false;
        }
    }
    if (color == 0)
    {
        c0++;
    }
    else
    {
        c1++;
    }
    return found;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vvll adj(n + 1);
        fr(i, 1, m)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vll visited(n + 1, 2);
        bool found = false;
        ll ans = 1;
        fr(i, 1, n)
        {
            if (visited[i] == 2)
            {
                ll c0 = 0, c1 = 0;
                if (!isBipartite(i, adj, visited, 0, c0, c1))
                {
                    found = true;
                    cout << 0 << endl;
                    break;
                }
                else
                {
                    ll temp = (binpow(2, c1, mod) + binpow(2, c0, mod)) % mod;
                    ans = (ans * temp) % mod;
                }
            }
        }
        if (!found)
        {
            cout << ans << endl;
        }
    }
}