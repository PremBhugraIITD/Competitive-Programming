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
        vpll edges;
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            edges.pb({x, y});
        }
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        vpll candidates;
        fr(i, 0, n - 2)
        {
            ll x = edges[i].first;
            ll y = edges[i].second;
            if (A[x] != A[y])
            {
                candidates.pb({x, y});
            }
        }
        if (candidates.empty())
        {
            cout << "YES" << endl
                 << 1 << endl;
        }
        else
        {
            vll count(n + 1);
            ll maxi = 0, root = 0;
            fr(i, 0, candidates.size() - 1)
            {
                ll x = candidates[i].first;
                ll y = candidates[i].second;
                count[x]++;
                count[y]++;
                if (count[x] > maxi)
                {
                    maxi = count[x];
                    root = x;
                }
                if (count[y] > maxi)
                {
                    maxi = count[y];
                    root = y;
                }
            }
            if (maxi == candidates.size())
            {
                cout << "YES" << endl
                     << root << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}