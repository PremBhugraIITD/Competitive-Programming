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

bool isCycle(ll curr, vvll &adj, vb &visited, vb &visited2)
{
    visited[curr] = true;
    visited2[curr] = true;
    for (auto &neighbor : adj[curr])
    {
        if (!visited[neighbor])
        {
            if (isCycle(neighbor, adj, visited, visited2))
            {
                return true;
            }
        }
        else if (visited2[neighbor])
        {
            return true;
        }
    }
    visited2[curr] = false;
    return false;
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
        vvll A(k + 1, n + 1);
        fr(i, 1, k)
        {
            fr(j, 1, n)
            {
                cin >> A[i][j];
            }
        }
        if (n == 1)
        {
            cout << "YES" << endl;
        }
        else if (k == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            vvll adj(n + 1);
            vll indegree(n + 1, 0);
            fr(i, 1, k)
            {
                ll last = A[i][2];
                fr(j, 3, n)
                {
                    ll curr = A[i][j];
                    adj[last].pb(curr);
                    indegree[curr]++;
                    last = curr;
                }
            }
            bool found = false;
            bool foundSource = false;
            fr(i, 1, n)
            {
                if (!indegree[i])
                {
                    foundSource = true;
                    vb visited(n + 1, false), visited2(n + 1, false);
                    if (isCycle(i, adj, visited, visited2))
                    {
                        found = true;
                        cout << "NO" << endl;
                        break;
                    }
                }
            }
            if (!foundSource)
            {
                cout << "NO" << endl;
            }
            else if (!found)
            {
                cout << "YES" << endl;
            }
        }
    }
}