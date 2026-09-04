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
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

void dfs(ll curr, ll parent, vector<vll> &adj, vll &A, vpll &counts)
{
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, A, counts);
            if (counts[neighbor].first > counts[neighbor].second)
            {
                counts[curr].first += counts[neighbor].first;
                counts[curr].second += counts[neighbor].second;
            }
        }
    }
    if (A[curr])
    {
        counts[curr].first++;
    }
    else
    {
        counts[curr].second++;
    }
}

void dfs2(ll curr, ll parent, vector<vll> &adj, vll &ans, vpll &counts)
{
    if (parent != 0)
    {
        if (counts[curr].first > counts[curr].second)
        {
            ans[curr] = counts[curr].first - counts[curr].second;
            ll temp = ans[parent] - (counts[curr].first - counts[curr].second);
            if (temp > 0)
            {
                ans[curr] += temp;
            }
        }
        else
        {
            ans[curr] = counts[curr].first - counts[curr].second;
            ll temp = ans[parent];
            if (temp > 0)
            {
                ans[curr] += temp;
            }
        }
    }
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs2(neighbor, curr, adj, ans, counts);
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
        ll n;
        cin >> n;
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vpll counts(n + 1, {0, 0});
        dfs(1, 0, adj, A, counts);
        vll ans(n + 1, 0);
        ans[1] = counts[1].first - counts[1].second;
        dfs2(1, 0, adj, ans, counts);
        fr(i, 1, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}