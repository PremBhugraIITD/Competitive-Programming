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

vvll dijkstra(ll source, vector<vpll> &adj, vb &isHorse)
{
    ll n = isHorse.size() - 1;
    vvll distance(n + 1, 2, LLONG_MAX);
    distance[source][isHorse[source]] = 0;
    priority_queue<vll, vvll, greater<vll>> pq;
    pq.push({0, source, isHorse[source]});
    while (!pq.empty())
    {
        vll curr = pq.top();
        pq.pop();
        ll curr_val = curr[1];
        ll curr_dist = curr[0];
        ll found = curr[2];
        if (curr_dist == distance[curr_val][found])
        {
            bool new_found = found || isHorse[curr_val];
            for (auto &neighbor : adj[curr_val])
            {
                ll neighbor_val = neighbor.first, w = neighbor.second;
                if (new_found)
                {
                    w /= 2;
                }
                if (distance[neighbor_val][new_found] > distance[curr_val][found] + w)
                {
                    distance[neighbor_val][new_found] = distance[curr_val][found] + w;
                    pq.push({distance[neighbor_val][new_found], neighbor_val, new_found});
                }
            }
        }
    }
    return distance;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, h;
        cin >> n >> m >> h;
        vb A(n + 1, false);
        fr(i, 0, h - 1)
        {
            ll temp;
            cin >> temp;
            A[temp] = true;
        }
        vector<vpll> adj(n + 1);
        fr(i, 1, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        vvll distance_source = dijkstra(1, adj, A);
        if ((distance_source[n][0] == LLONG_MAX) && (distance_source[n][1] == LLONG_MAX))
        {
            cout << -1 << endl;
        }
        else
        {
            vvll distance_dest = dijkstra(n, adj, A);
            ll mini = LLONG_MAX;
            fr(i, 1, n)
            {
                mini = min(mini, max(min(distance_source[i][0], distance_source[i][1]), min(distance_dest[i][0], distance_dest[i][1])));
            }
            cout << mini << endl;
        }
    }
}