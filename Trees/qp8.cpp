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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vll> adj(n + 1);
        vll degree(n + 1, 0);
        fr(i, 1, n - 1)
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
            degree[a]++;
            degree[b]++;
        }
        ll count = 0;
        fr(i, 1, n)
        {
            if (degree[i] == 1)
            {
                count++;
            }
        }
        if (count == 2)
        {
            ll first = 0, second;
            fr(i, 1, n)
            {
                if (degree[i] == 1)
                {
                    if (first == 0)
                    {
                        first = i;
                    }
                    else
                    {
                        second = i;
                        break;
                    }
                }
            }
            cout << "Yes" << endl
                 << 1 << endl
                 << first << " " << second << endl;
        }
        else
        {
            ll maxi = 0, root = 0;
            fr(i, 1, n)
            {
                if (degree[i] > maxi)
                {
                    maxi = degree[i];
                    root = i;
                }
            }
            bool found = false;
            fr(i, 1, n)
            {
                if (degree[i] >= 3 && i != root)
                {
                    found = true;
                    cout << "No" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Yes" << endl;
                vpll ans;
                fr(i, 1, n)
                {
                    if (degree[i] == 1)
                    {
                        ans.pb({root, i});
                    }
                }
                cout << ans.size() << endl;
                printPairVectorMap(ans);
            }
        }
    }
}