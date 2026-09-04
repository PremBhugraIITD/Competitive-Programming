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

void dfs(ll curr, ll parent, vector<vll> &adj, vll &distance, vpll &candidates)
{
    if (parent != -1)
    {
        distance[curr] = distance[parent] + 1;
    }
    candidates.pb({distance[curr], curr});
    for (auto &neighbor : adj[curr])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, curr, adj, distance, candidates);
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
        vector<vll> adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        vector<bool> isOnDiameter(n + 1, false);
        vll distance(n + 1, 0);
        ll maxDistance = 0;
        vpll candidates;
        dfs(1, -1, adj, distance, candidates);
        sort(candidates);
        ll end = candidates.back().second;
        ll maxi = candidates.back().first;
        reverse(candidates);
        ll count = candidates.size();
        fr(i, 0, candidates.size() - 1)
        {
            if (candidates[i].first == maxi)
            {
                count--;
            }
            else
            {
                break;
            }
        }
        while (count--)
        {
            candidates.pop_back();
        }
        distance.assign(n + 1, 0);
        vpll candidates2;
        dfs(end, -1, adj, distance, candidates2);
        sort(candidates2);
        end = candidates2.back().second;
        maxi = candidates2.back().first;
        reverse(candidates2);
        count = candidates2.size();
        fr(i, 0, candidates2.size() - 1)
        {
            if (candidates2[i].first == maxi)
            {
                count--;
            }
            else
            {
                break;
            }
        }
        while (count--)
        {
            candidates2.pop_back();
        }
        ll d = distance[end];
        // d is the original tree's diameter
        // candidates and candidates2 contain all the leaves which occur at the endpoints of all possible diemeters of the original tree
        fr(i, 0, candidates.size() - 1)
        {
            isOnDiameter[candidates[i].second] = true;
        }
        fr(i, 0, candidates2.size() - 1)
        {
            isOnDiameter[candidates2[i].second] = true;
        }
        vll ans(n + 1, 0);
        fr(i, 1, n)
        {
            ans[i] = d;
            if (isOnDiameter[i])
            {
                ans[i]++;
            }
        }
        fr(i, 1, n)
        {
            cout << ans[i] << endl;
        }
    }
}