#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
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

void dfs(ll curr, vector<bool> &visited, vector<set<ll>> &adj, vll &traversal)
{
    visited[curr] = true;
    traversal.pb(curr);
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, adj, traversal);
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
        ll n;
        cin >> n;
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vector<set<ll>> adj(n + 1);
        fr(i, 1, n)
        {
            adj[i].insert(A[i]);
            adj[A[i]].insert(i);
        }
        vector<bool> visited(n + 1, false);
        ll maxi = 0;
        ll cycle = 0;
        fr(source, 1, n)
        {
            vll traversal;
            if (!visited[source])
            {
                dfs(source, visited, adj, traversal);
                maxi++;
                ll count = 0;
                for (auto &i : traversal)
                {
                    if (adj[i].size() == 2)
                    {
                        count++;
                    }
                }
                if (count == traversal.size())
                {
                    cycle++;
                }
            }
        }
        ll mini = cycle == maxi ? cycle : 1 + cycle;
        cout << mini << " " << maxi << endl;
    }
}