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

int minimumObstacles(vector<vector<int>> &grid)
{
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        pq;
    int obstacle = (grid[0][0] == 1);
    distance[0][0] = obstacle;
    pq.push({obstacle, 0, 0});
    while (!pq.empty())
    {
        vector<int> curr = pq.top();
        pq.pop();
        int curr_dist = curr[0], curr_x = curr[1], curr_y = curr[2];
        if (curr_dist == distance[curr_x][curr_y])
        {
            for (int i = 0; i <= 3; i++)
            {
                int new_x = curr_x + dx[i], new_y = curr_y + dy[i];
                if (new_x >= 0 && new_y >= 0 && new_x <= n - 1 &&
                    new_y <= m - 1)
                {
                    // cout << curr_x << " " << curr_y << " " << new_x << " " << new_y << endl;
                    obstacle = (grid[new_x][new_y] == 1);
                    if (distance[new_x][new_y] >
                        distance[curr_x][curr_y] + obstacle)
                    {
                        distance[new_x][new_y] =
                            distance[curr_x][curr_y] + obstacle;
                        pq.push({distance[new_x][new_y], new_x, new_y});
                    }
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << distance[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return distance[n - 1][m - 1];
}

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
        vector<vector<int>> grid(n, vector<int>(m));
        fr(i, 0, n - 1)
        {
            fr(j, 0, m - 1)
            {
                cin >> grid[i][j];
            }
        }
        cout << minimumObstacles(grid) << endl;
    }
}