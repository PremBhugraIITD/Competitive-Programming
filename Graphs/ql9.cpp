#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
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

void bfs(ll source, vvll &adj, vb &visited, vll &distance, vll &parent)
{
    queue<ll> q;
    q.push(source);
    visited[source] = true;
    ll dist = 1;
    while (!q.empty())
    {
        ll size = q.size();
        while (size--)
        {
            ll curr = q.front();
            q.pop();
            distance[curr] = dist;
            for (auto &neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = curr;
                }
            }
        }
        dist++;
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
        vvll adj(n + 1);
        fr(i, 1, m)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vll distance(n + 1, 0);
        vb visited(n + 1, false);
        vll parent(n + 1, 0);
        bfs(1, adj, visited, distance, parent);
        if (distance[n])
        {
            cout << distance[n] << endl;
            ll dist = distance[n];
            vll ans;
            ans.pb(n);
            dist--;
            ll curr = parent[n];
            while (dist--)
            {
                ans.pb(curr);
                curr = parent[curr];
            }
            reverse(ans);
            printVectorSet(ans);
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}