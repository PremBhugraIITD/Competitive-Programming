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

class DSU
{
public:
    vll rank, parent;
    DSU(ll n)
    {
        rank.assign(n + 1, 0);
        fr(i, 0, n)
        {
            parent.pb(i);
        }
    }
    ll find_set(ll x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
    void union_sets(ll x, ll y)
    {
        x = find_set(x);
        y = find_set(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                parent[x] = y;
            }
            else if (rank[x] > rank[y])
            {
                parent[y] = x;
            }
            else
            {
                parent[x] = y;
                rank[y]++;
            }
        }
    }
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
        vpll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i].first >> A[i].second;
        }
        vll B(n + 1);
        fr(i, 1, n)
        {
            cin >> B[i];
        }
        vll C(n + 1);
        fr(i, 1, n)
        {
            cin >> C[i];
        }
        vvll edges;
        fr(i, 1, n)
        {
            ll x1 = A[i].first, y1 = A[i].second;
            fr(j, i + 1, n)
            {
                ll x2 = A[j].first, y2 = A[j].second;
                edges.pb({(C[i] + C[j]) * (abs(x1 - x2) + abs(y1 - y2)), i, j});
            }
        }
        fr(i, 1, n)
        {
            edges.pb({B[i], 0, i});
        }
        sort(edges);
        ll mini = 0;
        vll nodes;
        vpll edges2;
        DSU dsu(n);
        fr(i, 0, edges.size() - 1)
        {
            ll w = edges[i][0], u = edges[i][1], v = edges[i][2];
            if (dsu.find_set(u) != dsu.find_set(v))
            {
                mini += w;
                if (u == 0)
                {
                    nodes.pb(v);
                }
                else
                {
                    edges2.pb({u, v});
                }
                dsu.union_sets(u, v);
            }
        }
        cout << mini << endl;
        cout << nodes.size() << endl;
        printVectorSet(nodes);
        cout << edges2.size() << endl;
        printPairVectorMap(edges2);
    }
}