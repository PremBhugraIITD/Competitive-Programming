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

ll bfs(ll source, vvll &adj, vll &A, ll s, ll k, ll n)
{
    // cout << source << " " << A[source] << ": " << endl;
    queue<ll> q;
    q.push(source);
    vb visited(n + 1, false);
    visited[source] = true;
    vb goods(k + 1, false);
    ll ans = 0;
    ll count = 0;
    ll distance = 0;
    while (!q.empty())
    {
        ll size = q.size();
        while (size--)
        {
            ll curr = q.front();
            q.pop();
            if (!goods[A[curr]])
            {
                goods[A[curr]] = true;
                count++;
                ans += distance;
                // cout << distance << endl;
                if (count == s)
                {
                    return ans;
                }
            }
            for (auto &neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        distance++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, k, s;
        cin >> n >> m >> k >> s;
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vvll adj(n + 1);
        fr(i, 1, m)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        fr(source, 1, n)
        {
            cout << bfs(source, adj, A, s, k, n) << " ";
        }
        cout << "\n";
    }
}