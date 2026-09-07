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

bool isBipartite(ll curr, ll color, vvll &adj, vll &visited)
{
    visited[curr] = color;
    for (auto &neighbor : adj[curr])
    {
        if (visited[neighbor] == 2)
        {
            if (!isBipartite(neighbor, color ^ 1, adj, visited))
            {
                return false;
            }
        }
        else if (visited[neighbor] == color)
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
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
        // 2 means not visited
        bool found = false;
        fr(source, 1, n)
        {
            if (visited[source] == 2)
            {
                if (!isBipartite(source, 0, adj, visited))
                {
                    found = true;
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "YES" << endl;
        }
    }
}