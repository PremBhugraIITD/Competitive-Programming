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
        vector<vc> A(n, vc(m));
        pll start, end;
        fr(i, 0, n - 1)
        {
            fr(j, 0, m - 1)
            {
                cin >> A[i][j];
                if (A[i][j] == 'A')
                {
                    start = {i, j};
                }
                else if (A[i][j] == 'B')
                {
                    end = {i, j};
                }
            }
        }
        vll dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        vector<vpll> parent(n, vpll(m, {-1, -1}));
        queue<pll> q;
        q.push(start);
        vector<vb> visited(n, vb(m, false));
        visited[start.first][start.second] = true;
        bool found = false;
        string ans;
        while (!q.empty())
        {
            ll size = q.size();
            while (size--)
            {
                pll curr = q.front();
                q.pop();
                fr(i, 0, 3)
                {
                    ll new_x = curr.first + dx[i], new_y = curr.second + dy[i];
                    if (new_x >= 0 && new_y >= 0 && new_x <= n - 1 && new_y <= m - 1 && !visited[new_x][new_y] && A[new_x][new_y] != '#')
                    {
                        q.push({new_x, new_y});
                        visited[new_x][new_y] = true;
                        parent[new_x][new_y] = {curr};
                        if (make_pair(new_x, new_y) == end)
                        {
                            found = true;
                            cout << "YES" << endl;
                            pll curr = end;
                            while (curr != start)
                            {
                                pll p = parent[curr.first][curr.second];
                                if (p.first == curr.first + 1)
                                {
                                    ans.pb('U');
                                }
                                else if (p.first == curr.first - 1)
                                {
                                    ans.pb('D');
                                }
                                else if (p.second == curr.second + 1)
                                {
                                    ans.pb('L');
                                }
                                else
                                {
                                    ans.pb('R');
                                }
                                curr = p;
                            }
                            cout << ans.length() << endl;
                            reverse(ans);
                            cout << ans << endl;
                            break;
                        }
                    }
                }
                if (found)
                {
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
            cout << "NO" << endl;
        }
    }
}