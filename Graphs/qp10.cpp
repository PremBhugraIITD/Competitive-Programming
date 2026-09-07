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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vvc A(n + 1, m + 1);
        bool goodExists = false;
        fr(i, 1, n)
        {
            fr(j, 1, m)
            {
                cin >> A[i][j];
                if (A[i][j] == 'G')
                {
                    goodExists = true;
                }
            }
        }
        vll dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
        fr(i, 1, n)
        {
            fr(j, 1, m)
            {
                if (A[i][j] == 'B')
                {
                    fr(k, 0, 3)
                    {
                        ll new_x = i + dx[k], new_y = j + dy[k];
                        if (new_x >= 1 && new_y >= 1 && new_x <= n && new_y <= m)
                        {
                            if (A[new_x][new_y] == '.')
                            {
                                A[new_x][new_y] = '#';
                            }
                        }
                    }
                }
            }
        }
        if (A[n][m] == '#')
        {
            if (goodExists)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
        else
        {
            queue<pll> q;
            q.push({n, m});
            vvb visited(n + 1, m + 1);
            visited[n][m] = true;
            while (!q.empty())
            {
                pll curr = q.front();
                q.pop();
                fr(i, 0, 3)
                {
                    ll new_x = curr.first + dx[i], new_y = curr.second + dy[i];
                    if (new_x >= 1 && new_y >= 1 && new_x <= n && new_y <= m && !visited[new_x][new_y] && A[new_x][new_y] != '#')
                    {
                        q.push({new_x, new_y});
                        visited[new_x][new_y] = true;
                    }
                }
            }
            bool found = false;
            fr(i, 1, n)
            {
                fr(j, 1, m)
                {
                    if ((A[i][j] == 'G' && !visited[i][j]) || (A[i][j] == 'B' && visited[i][j]))
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
}
