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
        vpll A;
        ll sum = 0;
        fr(i, 1, n)
        {
            ll w;
            cin >> w;
            A.pb({w, i});
            sum += w;
        }
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
        fr(i, 1, n)
        {
            degree[i]--;
        }
        sort(A);
        reverse(A);
        ll i = 0;
        fr(k, 1, n - 1)
        {
            if (k > 1)
            {
                ll v = A[i].second;
                ll w = A[i].first;
                while (degree[v] - 1 < 0)
                {
                    i++;
                    v = A[i].second;
                    w = A[i].first;
                }
                degree[v]--;
                sum += w;
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}