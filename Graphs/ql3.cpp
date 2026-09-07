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
        ll n, m;
        cin >> n >> m;
        vvll A(n, m);
        queue<pll> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        fr(i, 0, n - 1)
        {
            fr(j, 0, m - 1)
            {
                cin >> A[i][j];
                if (A[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        // 0 means empty, 1 means rotten, 2 means fresh
        vvll times(n, m, 0);
        vll dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
        ll time = 0;
        while (!q.empty()) // Multisource BFS
        {
            ll size = q.size();
            fr(i, 1, size)
            {
                pll curr = q.front();
                q.pop();
                times[curr.first][curr.second] = time;
                fr(j, 0, 3)
                {
                    ll new_x = curr.first + dx[j], new_y = curr.second + dy[j];
                    if (new_x >= 0 && new_y >= 0 && new_x <= n - 1 && new_y <= m - 1 && !visited[new_x][new_y] && A[new_x][new_y] != 0)
                    {
                        q.push({new_x, new_y});
                        visited[new_x][new_y] = true;
                    }
                }
            }
            time++;
        }
        ll maxi = 0;
        bool found = false;
        fr(i, 0, n - 1)
        {
            fr(j, 0, m - 1)
            {
                if (A[i][j] == 2)
                {
                    if (times[i][j] == 0)
                    {
                        found = true;
                        cout << -1 << endl;
                        break;
                    }
                    else
                    {
                        maxi = max(maxi, times[i][j]);
                    }
                }
            }
            if (found)
            {
                break;
            }
        }
        if (!found)
        {
            cout << maxi << endl;
        }
    }
}