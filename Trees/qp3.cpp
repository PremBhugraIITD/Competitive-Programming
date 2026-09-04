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
        vector<vll> adj(n + 1);
        vll degree(n + 1, 0);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
            degree[x]++;
            degree[y]++;
        }
        if (n <= 2)
        {
            cout << 0 << endl;
        }
        else
        {
            vll parent(n + 1);
            queue<ll> q;
            fr(i, 1, n)
            {
                if (degree[i] == 1)
                {
                    q.push(i);
                }
            }
            ll destroyed = 0;
            while (!q.empty() && k)
            {
                ll size = q.size();
                fr(i, 1, size)
                {
                    ll curr = q.front();
                    q.pop();
                    destroyed++;
                    for (auto &neighbor : adj[curr])
                    {
                        degree[neighbor]--;
                        if (degree[neighbor] == 1)
                        {
                            q.push(neighbor);
                        }
                    }
                }
                k--;
            }
            cout << max(0LL, n - destroyed) << endl;
        }
    }
}