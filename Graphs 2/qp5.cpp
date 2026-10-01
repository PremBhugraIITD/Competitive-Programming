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

int countPaths(int n, vector<vector<int>> &roads)
{
    long long int m = roads.size();
    vector<vector<pair<long long int, long long int>>> adj(n);
    for (long long int i = 0; i < m; i++)
    {
        long long int a = roads[i][0], b = roads[i][1], w = roads[i][2];
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<long long int> distance(n, LLONG_MAX);
    distance[0] = 0;
    priority_queue<pair<long long int, long long int>,
                   vector<pair<long long int, long long int>>,
                   greater<pair<long long int, long long int>>>
        pq;
    pq.push({0, 0});
    vector<long long int> ways(n, 0);
    ways[0] = 1;
    while (!pq.empty())
    {
        pair<long long int, long long int> curr = pq.top();
        pq.pop();
        long long int curr_dist = curr.first, curr_val = curr.second;
        if (curr_dist == distance[curr_val])
        {
            for (auto &neighbor : adj[curr_val])
            {
                long long int neighbor_val = neighbor.first,
                              weight = neighbor.second;
                if (distance[neighbor_val] > distance[curr_val] + weight)
                {
                    distance[neighbor_val] = distance[curr_val] + weight;
                    pq.push({distance[neighbor_val], neighbor_val});
                    ways[neighbor_val] = ways[curr_val];
                }
                else if (distance[neighbor_val] ==
                         distance[curr_val] + weight)
                {
                    ways[neighbor_val] =
                        (ways[neighbor_val] + ways[curr_val]) % mod;
                }
            }
        }
    }
    return ways[n - 1];
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
        vector<vector<int>> roads(m, vector<int>(3));
        fr(i, 0, m - 1)
        {
            cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
        }
        cout << countPaths(n, roads) << endl;
    }
}