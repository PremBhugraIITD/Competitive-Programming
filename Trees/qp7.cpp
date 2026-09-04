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

// Checks whether the subtree starting from curr has a problem path or not
bool dfs(ll curr, ll parent, vector<vll> &adj, set<pll> &problemRoad, set<ll> &ans)
{
    bool found = false;
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            if (problemRoad.count({curr, neighbor}) || problemRoad.count({neighbor, curr}))
            {
                found = true;
                ans.insert(neighbor);
                if (dfs(neighbor, curr, adj, problemRoad, ans))
                {
                    ans.erase(neighbor);
                }
            }
            else if (dfs(neighbor, curr, adj, problemRoad, ans))
            {
                found = true;
            }
        }
    }
    return found;
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
        set<pll> problemRoad;
        fr(i, 1, n - 1)
        {
            ll x, y, q;
            cin >> x >> y >> q;
            adj[x].pb(y);
            adj[y].pb(x);
            if (q == 2)
            {
                problemRoad.insert({x, y});
            }
        }
        set<ll> ans;
        dfs(1, -1, adj, problemRoad, ans);
        cout << ans.size() << endl;
        printVector(ans);
    }
}