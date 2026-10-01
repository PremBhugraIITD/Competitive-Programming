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

vll djisktra(ll source, vector<vpll> &adj)
{
    ll n = adj.size();
    vll distance(n + 1, LLONG_MAX);
    distance[source] = 0;
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0LL, source});
    while (!pq.empty())
    {
        pll curr = pq.top();
        pq.pop();
        ll curr_distance = curr.first;
        ll curr_value = curr.second;
        if (curr_distance == distance[curr_value])
        {
            for (auto &neighbor : adj[curr_value])
            {
                ll neighbor_value = neighbor.first;
                ll weight = neighbor.second;
                if (distance[neighbor_value] > distance[curr_value] + weight)
                {
                    distance[neighbor_value] = distance[curr_value] + weight;
                    pq.push({distance[neighbor_value], neighbor_value});
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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vpll> adj(n + 1);
        fr(i, 1, m)
        {
            ll a, b, w;
            cin >> a >> b >> w;
            adj[a].pb({b, w});
            adj[b].pb({a, w});
        }
        ll source, destination, blocker;
        cin >> source >> destination >> blocker;
        vll distance_blocker = djisktra(blocker, adj);
        vll before(n + 1, -1);
        vll distance_source(n + 1, LLONG_MAX);
        distance_source[source] = 0;
        priority_queue<pll, vpll, greater<pll>> pq;
        pq.push({0LL, source});
        while (!pq.empty())
        {
            pll curr = pq.top();
            pq.pop();
            ll curr_distance = curr.first;
            ll curr_value = curr.second;
            if (curr_distance == distance_source[curr_value])
            {
                for (auto &neighbor : adj[curr_value])
                {
                    ll neighbor_value = neighbor.first;
                    ll weight = neighbor.second;
                    if (distance_source[neighbor_value] > distance_source[curr_value] + weight && distance_source[curr_value] + weight < distance_blocker[neighbor_value])
                    {
                        distance_source[neighbor_value] = distance_source[curr_value] + weight;
                        pq.push({distance_source[neighbor_value], neighbor_value});
                        before[neighbor_value] = curr_value;
                    }
                }
            }
        }
        if (distance_source[destination] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << distance_source[destination] << endl;
            vll ans;
            ll curr = destination;
            while (curr != -1)
            {
                ans.pb(curr);
                curr = before[curr];
            }
            reverse(ans);
            printVectorSet(ans);
        }
    }
}