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
#define printVector(v)    \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define printPairVector(v) \
    for (auto &x : v)      \
        cout << x.first << ' ' << x.second << endl;
#define mod 1000000007

class vvll : public vector<vector<ll>>
{
public:
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

void dfs(ll curr, ll p, vector<vll> &adj, vll &A, vll &res)
{
    ll count = 0;
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != p)
        {
            if (A[neighbor])
            {
                count++;
            }
            dfs(neighbor, curr, adj, A, res);
        }
    }
    if (count == adj[curr].size() - 1 && A[curr])
    {
        res.pb(curr);
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
        ll n;
        cin >> n;
        vector<vll> adj(n + 1);
        ll root;
        vll A(n + 1);
        fr(i, 1, n)
        {
            ll p;
            cin >> p;
            if (p == -1)
            {
                root = i;
            }
            else
            {
                adj[i].pb(p);
                adj[p].pb(i);
            }
            cin >> A[i];
        }
        vll ans;
        dfs(root, -1, adj, A, ans);
        if (ans.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(ans);
            printVector(ans);
        }
    }
}