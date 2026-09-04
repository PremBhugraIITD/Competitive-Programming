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

void build_path(ll start, ll end, ll len, ll &next, vpll &ans)
{
    if (len == 1)
    {
        ans.pb({start, end});
    }
    else
    {
        ans.pb({start, next});
        next++;
        len--;
        while (len--)
        {
            if (!len)
            {
                ans.pb({next - 1, end});
            }
            else
            {
                ans.pb({next - 1, next});
                next++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, d12, d23, d13;
        cin >> n >> d12 >> d23 >> d13;
        ll sum = d12 + d23 + d13;
        if (sum & 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            sum >>= 1;
            ll x = sum - d23, y = sum - d13, z = sum - d12;
            if (x < 0 || y < 0 || z < 0)
            {
                cout << "NO" << endl;
            }
            else if (1 + x + y + z > n)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
                vpll ans;
                ll next = 4;
                ll edges = n - 1;
                if (x == 0)
                {
                    build_path(2, 1, d12, next, ans);
                    build_path(1, 3, d13, next, ans);
                    edges -= d12 + d13;
                }
                else if (y == 0)
                {
                    build_path(1, 2, d12, next, ans);
                    build_path(2, 3, d23, next, ans);
                    edges -= d12 + d23;
                }
                else if (z == 0)
                {
                    build_path(1, 3, d13, next, ans);
                    build_path(3, 2, d23, next, ans);
                    edges -= d13 + d23;
                }
                else
                {
                    next++;
                    build_path(1, 4, x, next, ans);
                    build_path(2, 4, y, next, ans);
                    build_path(3, 4, z, next, ans);
                    edges -= x + y + z;
                }
                while (edges--)
                {
                    ans.pb({1, next++});
                }
                printPairVectorMap(ans);
            }
        }
    }
}