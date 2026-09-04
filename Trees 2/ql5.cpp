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

void dfs(ll curr, ll parent, vector<vll> &adj, vector<vll> &ans, vll &A)
{
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, ans, A);
            ans[curr][1] += ans[neighbor][0];
            ans[curr][0] += max(ans[neighbor][0], ans[neighbor][1]);
        }
    }
    ans[curr][1] += A[curr];
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
        vvll ans(n + 1, 2, 0);
        dfs(1, 0, adj, ans, A);
        cout << max(ans[1][0], ans[1][1]) << endl;
    }
}