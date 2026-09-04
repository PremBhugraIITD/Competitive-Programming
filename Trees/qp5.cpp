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

void dfs(ll curr, ll p, vector<vll> &adj, vll &subordinates)
{
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != p)
        {
            dfs(neighbor, curr, adj, subordinates);
            subordinates[curr] += 1 + subordinates[neighbor];
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
        fr(i, 2, n)
        {
            ll b;
            cin >> b;
            adj[b].pb(i);
            adj[i].pb(b);
        }
        vll subordinates(n + 1, 0);
        dfs(1, -1, adj, subordinates);
        fr(i, 1, n)
        {
            cout << subordinates[i] << " ";
        }
        cout << endl;
    }
}