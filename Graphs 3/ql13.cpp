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

bool isCycle(ll curr, vb &visited, vb &dfs_visited, vvll &adj)
{
    visited[curr] = true;
    dfs_visited[curr] = true;
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            if (isCycle(neighbor, visited, dfs_visited, adj))
            {
                return true;
            }
        }
        else if (dfs_visited[neighbor])
        {
            return true;
        }
    }
    dfs_visited[curr] = false;
    return false;
}

void topological_sort(ll curr, vvll &adj, vb &visited, vll &ans)
{
    visited[curr] = true;
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            topological_sort(neighbor, adj, visited, ans);
        }
    }
    ans.pb(curr);
}

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
        vector<string> names(n + 1);
        fr(i, 1, n)
        {
            cin >> names[i];
        }
        if (n == 1)
        {
            cout << "abcdefghijklmnopqrstuvwxyz" << endl;
        }
        else
        {
            vvll adj(27);
            bool found = false;
            fr(i, 1, n - 1)
            {
                string curr = names[i], next = names[i + 1];
                ll j = 0;
                ll n = curr.length(), m = next.length();
                while (j < n && j < m && curr[j] == next[j])
                {
                    j++;
                }
                if (j < n && j < m)
                {
                    adj[curr[j] - 'a' + 1].pb(next[j] - 'a' + 1);
                }
                else if (j > n && j > m)
                {
                    // curr == next
                    continue;
                }
                else if (j < m)
                {
                    // curr is a prefix of
                    continue;
                }
                else
                {
                    // j < n
                    found = true;
                    cout << "Impossible" << endl;
                    break;
                }
            }
            if (!found)
            {
                vb visited(27, false);
                vb dfs_visited(27, false);
                fr(i, 1, 26)
                {
                    if (!visited[i])
                    {
                        if (isCycle(i, visited, dfs_visited, adj))
                        {
                            found = true;
                            cout << "Impossible" << endl;
                            break;
                        }
                    }
                }
                if (!found)
                {
                    visited.assign(27, false);
                    vll ans;
                    fr(i, 1, 26)
                    {
                        if (!visited[i])
                        {
                            topological_sort(i, adj, visited, ans);
                        }
                    }
                    reverse(ans);
                    fr(i, 0, 25)
                    {
                        cout << char('a' + ans[i] - 1);
                    }
                    cout << endl;
                }
            }
        }
    }
}