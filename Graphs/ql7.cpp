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
    vvll() = default;
    vvll(ll rows) : vector<vector<ll>>(rows) {}
    vvll(ll rows, ll cols) : vector<vector<ll>>(rows, vector<ll>(cols, 0)) {}
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
        vvll adj(n + 1);
        fr(i, 1, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vll A(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
        }
        if (A[1] != 1)
        {
            cout << "No" << endl;
            continue;
        }
        ll source = 1;
        queue<ll> q;
        q.push(source);
        vector<bool> visited(n + 1, false);
        visited[source] = true;
        bool found = false;
        ll i = 2;
        while (!q.empty())
        {
            ll size = q.size();
            while (size--)
            {
                set<ll> temp1, temp2;
                ll curr = q.front();
                q.pop();
                ll count = 0;
                for (auto &neighbor : adj[curr])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        count++;
                        temp1.insert(neighbor);
                    }
                }
                ll init = i;
                fr(j, 1, count)
                {
                    temp2.insert(A[i++]);
                }
                if (temp1 == temp2)
                {
                    i = init;
                    while (count--)
                    {
                        q.push(A[i++]);
                    }
                }
                else
                {
                    found = true;
                    cout << "No" << endl;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        if (!found)
        {
            cout << "Yes" << endl;
        }
    }
}