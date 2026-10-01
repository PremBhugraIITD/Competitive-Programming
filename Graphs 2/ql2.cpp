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
        ll source, destination;
        cin >> source >> destination;
        vll before(n + 1, -1);
        vll distance(n + 1, LLONG_MAX);
        distance[source] = 0;
        priority_queue<pll, vpll, greater<pll>> pq;
        pq.push({0LL, source});
        while (!pq.empty())
        {
            pll curr = pq.top();
            pq.pop();
            if (curr.first == distance[curr.second])
            {
                for (auto &neighbor : adj[curr.second])
                {
                    if (distance[neighbor.first] > distance[curr.second] + neighbor.second)
                    {
                        distance[neighbor.first] = distance[curr.second] + neighbor.second;
                        pq.push({distance[neighbor.first], neighbor.first});
                        before[neighbor.first] = curr.second;
                    }
                }
            }
        }
        vll ans;
        ll curr = destination;
        while (curr != -1)
        {
            ans.pb(curr);
            curr = before[curr];
        }
        reverse(ans);
        cout << distance[destination] << endl;
        printVectorSet(ans);
    }
}