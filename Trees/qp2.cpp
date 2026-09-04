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
#define printVector(v)    \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define printPairVector(v) \
    for (auto &x : v)      \
        cout << x.first << ' ' << x.second << endl;
#define mod 1000000007

class vvll : public vector<vector<ll>>
{
public:
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

void dfs(ll curr, ll parent, vector<vll> &adj, vll &A, ll &ans, ll m, bool found)
{
    if (parent != -1)
    {
        if (A[curr] != 0)
        {
            A[curr] += A[parent];
        }
    }
    if (found || A[curr] > m)
    {
        found = true;
    }
    if (adj[curr].size() == 1 && adj[curr][0] == parent)
    {
        if (!found)
        {
            ans++;
        }
        // cout << curr << " " << A[curr] << " " << ans << endl;
    }
    else
    {
        // cout << curr << " " << A[curr] << " " << ans << endl;
        for (auto &neighbor : adj[curr])
        {
            if (neighbor != parent)
            {
                dfs(neighbor, curr, adj, A, ans, m, found);
            }
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
        ll n, m;
        cin >> n >> m;
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll ans = 0;
        dfs(1, -1, adj, A, ans, m, false);
        cout << ans << endl;
    }
}