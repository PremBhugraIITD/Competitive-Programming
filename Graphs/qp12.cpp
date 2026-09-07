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

ll configuration_test(vpll &edges, vvb isAvaialble, vll &color)
{
    ll ans = 0;
    ll m = edges.size() - 1;
    fr(i, 1, m)
    {
        ll a = edges[i].first, b = edges[i].second;
        if (isAvaialble[color[a]][color[b]])
        {
            ans++;
            isAvaialble[color[a]][color[b]] = isAvaialble[color[b]][color[a]] = false;
        }
    }
    return ans;
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
        vpll edges(m + 1);
        fr(i, 1, m)
        {
            ll a, b;
            cin >> a >> b;
            edges[i] = {a, b};
        }
        if (n <= 6)
        {
            cout << m << '\n';
        }
        else
        {
            vll color(n + 1);
            vvb isAvailable(7, 7, false);
            fr(i, 1, 6)
            {
                fr(j, i, 6)
                {
                    isAvailable[i][j] = isAvailable[j][i] = true;
                }
            }
            ll maxi = 0;
            fr(i, 1, 6)
            {
                fr(j, 1, 6)
                {
                    fr(k, 1, 6)
                    {
                        fr(a, 1, 6)
                        {
                            fr(b, 1, 6)
                            {
                                fr(c, 1, 6)
                                {
                                    fr(x, 1, 6)
                                    {
                                        color[1] = i;
                                        color[2] = j;
                                        color[3] = k;
                                        color[4] = a;
                                        color[5] = b;
                                        color[6] = c;
                                        color[7] = x;
                                        maxi = max(maxi, configuration_test(edges, isAvailable, color));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << maxi << '\n';
        }
    }
}