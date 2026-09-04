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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vll> children(n + 1);
        fr(i, 2, n)
        {
            ll p;
            cin >> p;
            children[p].pb(i);
        }
        bool found = false;
        fr(i, 1, n)
        {
            if (children[i].empty())
            {
                continue;
            }
            else
            {
                ll count = 0;
                for (auto &child : children[i])
                {
                    if (children[child].empty())
                    {
                        count++;
                        if (count == 3)
                        {
                            break;
                        }
                    }
                }
                if (count == 3)
                {
                continue;
                }
                else
                {
                    found = true;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Yes" << endl;
        }
    }
}