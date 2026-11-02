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

void dfs(ll curr, vb &visited, vvll &adj, set<ll> &component)
{
    visited[curr] = true;
    component.insert(curr);
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, adj, component);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        if (k == 1)
        {
            bool found = false;
            fr(i, 1, n)
            {
                if (A[i] != i)
                {
                    found = true;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            bool found = false;
            fr(i, 1, n)
            {
                if (A[i] == i)
                {
                    found = true;
                    cout << "NO" << endl;
                    break;
                }
            }
            if (!found)
            {
                vvll adj(n + 1);
                vvll undirected_adj(n + 1);
                vll indegree(n + 1, 0);
                fr(i, 1, n)
                {
                    adj[i].pb(A[i]);
                    indegree[A[i]]++;
                    undirected_adj[i].pb(A[i]);
                    undirected_adj[A[i]].pb(i);
                }
                // Every node has outdegree==1, but indegree>=1
                vb visited(n + 1, false);
                bool found = false;
                fr(i, 1, n)
                {
                    if (!visited[i])
                    {
                        set<ll> component;
                        dfs(i, visited, undirected_adj, component);
                        queue<ll> q;
                        for (auto &u : component)
                        {
                            if (!indegree[u])
                            {
                                q.push(u);
                            }
                        }
                        while (!q.empty())
                        {
                            ll curr = q.front();
                            q.pop();
                            for (auto &neighbor : adj[curr])
                            {
                                indegree[neighbor]--;
                                if (!indegree[neighbor])
                                {
                                    q.push(neighbor);
                                }
                            }
                        }
                        ll cycleLength = 0;
                        for (auto &u : component)
                        {
                            if (indegree[u])
                            {
                                cycleLength++;
                            }
                        }
                        if (cycleLength != k)
                        {
                            found = true;
                            cout << "NO" << endl;
                            break;
                        }
                    }
                }
                if (!found)
                {
                    cout << "YES" << endl;
                }
            }
        }
    }
}