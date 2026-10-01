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
    ll a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        vvll distance(8, 8, LLONG_MAX);
        distance[a][b] = 0;
        priority_queue<vll, vvll, greater<vll>> pq;
        pq.push({0ll, a, b});
        vll dx = {2, 2, -2, -2, 1, 1, -1, -1}, dy = {1, -1, 1, -1, 2, -2, 2, -2};
        while (!pq.empty())
        {
            vll curr = pq.top();
            pq.pop();
            ll curr_x = curr[1], curr_y = curr[2], curr_dist = curr[0];
            if (curr_dist == distance[curr_x][curr_y])
            {
                fr(i, 0, 7)
                {
                    ll new_x = curr_x + dx[i], new_y = curr_y + dy[i];
                    if (new_x >= 0 && new_y >= 0 && new_x <= 7 && new_y <= 7)
                    {
                        ll weight = curr_x * new_x + curr_y * new_y;
                        if (distance[new_x][new_y] > distance[curr_x][curr_y] + weight)
                        {
                            distance[new_x][new_y] = distance[curr_x][curr_y] + weight;
                            pq.push({distance[new_x][new_y], new_x, new_y});
                        }
                    }
                }
            }
        }
        if (distance[c][d] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << distance[c][d] << endl;
        }
    }
}