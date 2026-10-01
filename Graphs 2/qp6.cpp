#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
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

class vvb : public vector<vector<bool>>
{
public:
    vvb() = default;
    vvb(ll rows) : vector<vector<bool>>(rows) {}
    vvb(ll rows, ll cols) : vector<vector<bool>>(rows, vector<bool>(cols, false)) {}
    vvb(ll rows, ll cols, bool val) : vector<vector<bool>>(rows, vector<bool>(cols, val)) {}
};

class vvc : public vector<vector<char>>
{
public:
    vvc() = default;
    vvc(ll rows) : vector<vector<char>>(rows) {}
    vvc(ll rows, ll cols) : vector<vector<char>>(rows, vector<char>(cols, 'a')) {}
    vvc(ll rows, ll cols, char val) : vector<vector<char>>(rows, vector<char>(cols, val)) {}
};

class vvs : public vector<vector<string>>
{
public:
    vvs() = default;
    vvs(ll rows) : vector<vector<string>>(rows) {}
    vvs(ll rows, ll cols) : vector<vector<string>>(rows, vector<string>(cols, "a")) {}
    vvs(ll rows, ll cols, string val) : vector<vector<string>>(rows, vector<string>(cols, val)) {}
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
        map<pll, ll> index;
        fr(i, 1, n)
        {
            ll x, y;
            cin >> x >> y;
            index[{x, y}] = i;
        }
        queue<pll> q;
        set<pll> visited;
        map<pll, pll> ans;
        vll dx = {0, 0, 1, -1}, dy = {-1, 1, 0, 0};
        for (auto &i : index)
        {
            ll x = i.first.first, y = i.first.second;
            fr(j, 0, 3)
            {
                ll new_x = x + dx[j], new_y = y + dy[j];
                if (new_x >= 0 && new_y >= 0 && new_x <= 2e5 + 1 && new_y <= 2e5 + 1)
                {
                    if (!index.count({new_x, new_y}))
                    {
                        ans[{x, y}] = {new_x, new_y};
                        q.push({x, y});
                        visited.insert({x, y});
                        break;
                    }
                }
            }
        }
        while (!q.empty())
        {
            pll curr = q.front();
            q.pop();
            ll curr_x = curr.first, curr_y = curr.second;
            fr(i, 0, 3)
            {
                ll new_x = curr_x + dx[i], new_y = curr_y + dy[i];
                if (new_x >= 0 && new_y >= 0 && new_x <= 2e5 && new_y <= 2e5 && index.count({new_x, new_y}))
                {
                    if (!visited.count({new_x, new_y}))
                    {
                        visited.insert({new_x, new_y});
                        q.push({new_x, new_y});
                        ans[{new_x, new_y}] = ans[{curr_x, curr_y}];
                    }
                }
            }
        }
        vpll res(n);
        for (auto &i : index)
        {
            ll x = i.first.first, y = i.first.second;
            res[index[{x, y}] - 1] = ans[{x, y}];
        }
        printPairVectorMap(res);
    }
}