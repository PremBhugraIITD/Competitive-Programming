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

bool isGovt(ll source, vvll &adj, vb &visited, ll &count, vb &isGovernment, ll &edges)
{
    visited[source] = true;
    bool found = false;
    count++;
    edges += adj[source].size();
    // cout << source << endl;
    if (isGovernment[source])
    {
        found = true;
    }
    for (auto &neighbor : adj[source])
    {
        if (!visited[neighbor])
        {
            if (isGovt(neighbor, adj, visited, count, isGovernment, edges))
            {
                found = true;
            }
        }
    }
    return found;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vb isGovernment(n + 1, false);
        fr(i, 1, k)
        {
            ll temp;
            cin >> temp;
            isGovernment[temp] = true;
        }
        vvll adj(n + 1);
        fr(i, 1, m)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vb visited(n + 1, false);
        ll maxi = 0;
        vll not_included;
        ll ans = 0;
        fr(source, 1, n)
        {
            if (!visited[source])
            {
                ll count = 0, edges = 0;
                bool present = isGovt(source, adj, visited, count, isGovernment, edges);
                edges >>= 1;
                ans += (count * (count - 1)) / 2 - edges;
                if (present)
                {
                    maxi = max(maxi, count);
                }
                else
                {
                    not_included.pb(count);
                }
            }
        }
        for (auto &i : not_included)
        {
            ans += maxi * i;
            maxi += i;
        }
        cout << ans << endl;
    }
}