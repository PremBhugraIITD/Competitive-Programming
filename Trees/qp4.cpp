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
            ll p;
            cin >> p;
            adj[i].pb(p);
            adj[p].pb(i);
        }
        ll root = 1;
        queue<ll> q;
        q.push(root);
        vector<bool> visited(n + 1, false);
        visited[root] = true;
        ll ans = 0;
        while (!q.empty())
        {
            ll size = q.size();
            if (size & 1)
            {
                ans++;
            }
            fr(i, 1, size)
            {
                ll curr = q.front();
                q.pop();
                for (auto &neighbor : adj[curr])
                {
                    if (!visited[neighbor])
                    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}