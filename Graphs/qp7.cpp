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

void dfs(ll source, vvll &adj, vb &visited, vll &component)
{
    visited[source] = true;
    component.pb(source);
    for (auto &neighbor : adj[source])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, component);
        }
    }
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
        vvll groups(n + 1);
        vvll A(m + 1);
        fr(i, 1, m)
        {
            ll size;
            cin >> size;
            while (size--)
            {
                ll temp;
                cin >> temp;
                groups[temp].pb(i);
                A[i].pb(temp);
            }
        }
        vvll adj(m + 1);
        fr(i, 1, n)
        {
            if (!groups[i].empty())
            {
                ll first = groups[i][0];
                fr(j, 1, groups[i].size() - 1)
                {
                    adj[first].pb(groups[i][j]);
                    adj[groups[i][j]].pb(first);
                }
            }
        }
        vb visited(m + 1, false);
        vll ans(n + 1);
        fr(source, 1, m)
        {
            if (!visited[source])
            {
                vll component;
                dfs(source, adj, visited, component);
                // printVectorSet(component);
                ll size = 0;
                set<ll> temp;
                for (auto &group : component)
                {
                    for (auto &member : A[group])
                    {
                        temp.insert(member);
                    }
                }
                for (auto &member : temp)
                {
                    ans[member] = temp.size();
                }
            }
        }
        fr(i, 1, n)
        {
            cout << max((ll)1, ans[i]) << " ";
        }
        cout << endl;
    }
}