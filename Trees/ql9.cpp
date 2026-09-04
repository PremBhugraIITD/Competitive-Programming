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

void dfs(ll curr, ll parent, vector<vll> &adj, ll &time, vll &intime, vll &outtime)
{
    time++;
    intime[curr] = time;
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, time, intime, outtime);
        }
    }
    time++;
    outtime[curr] = time;
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
        vector<vll> adj(n);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vll intime(n, 0), outtime(n, 0);
        ll time = 0;
        dfs(0, -1, adj, time, intime, outtime);
        printVector(intime);
        printVector(outtime);
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            if (intime[x] < intime[y] && intime[y] < outtime[y] && outtime[y] < outtime[x])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}