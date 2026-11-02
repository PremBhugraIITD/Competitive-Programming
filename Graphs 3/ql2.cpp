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

class vvb : public vector<vector<bool>>
{
public:
    vvb() = default;
    vvb(ll rows) : vector<vector<bool>>(rows) {}
    vvb(ll rows, ll cols) : vector<vector<bool>>(rows, vector<bool>(cols, false)) {}
    vvb(ll rows, ll cols, bool val) : vector<vector<bool>>(rows, vector<bool>(cols, val)) {}
};

class vvc : public vector<vector<char>>
{
public:
    vvc() = default;
    vvc(ll rows) : vector<vector<char>>(rows) {}
    vvc(ll rows, ll cols) : vector<vector<char>>(rows, vector<char>(cols, 'a')) {}
    vvc(ll rows, ll cols, char val) : vector<vector<char>>(rows, vector<char>(cols, val)) {}
};

class vvs : public vector<vector<string>>
{
public:
    vvs() = default;
    vvs(ll rows) : vector<vector<string>>(rows) {}
    vvs(ll rows, ll cols) : vector<vector<string>>(rows, vector<string>(cols, "a")) {}
    vvs(ll rows, ll cols, string val) : vector<vector<string>>(rows, vector<string>(cols, val)) {}
};

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
        vector<vpll> adj(n + 1);
        fr(i, 1, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        ll min_weight = 0;
        vvll spanning_tree;
        vb visited(n + 1, false);
        priority_queue<vll, vvll, greater<vll>> pq;
        pq.push({0, -1, 1});
        while (!pq.empty())
        {
            vll curr = pq.top();
            pq.pop();
            ll curr_node = curr[2];
            if (!visited[curr_node])
            {
                visited[curr_node] = true;
                if (curr[1] != -1)
                {
                    spanning_tree.pb({curr[1], curr[2], curr[0]});
                    min_weight += curr[0];
                }
                for (auto &neighbor : adj[curr_node])
                {
                    ll neighbor_node = neighbor.first, w = neighbor.second;
                    if (!visited[neighbor_node])
                    {
                        pq.push({w, curr_node, neighbor_node});
                    }
                }
            }
        }
        cout << min_weight << endl;
        fr(i, 0, n - 2)
        {
            cout << spanning_tree[i][0] << " " << spanning_tree[i][1] << " " << spanning_tree[i][2] << endl;
        }
    }
}