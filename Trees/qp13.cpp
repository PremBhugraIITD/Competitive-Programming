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

bool isGood(ll p, ll n, vll &subtree, vll &A, vll &pos)
{
    if (2 * p > n)
    {
        return true;
    }
    else
    {
        ll parentPos = pos[p];
        ll leftPos = pos[2 * p];
        ll rightPos = pos[2 * p + 1];
        if (leftPos == parentPos + 1 && rightPos == parentPos + 1 + subtree[2 * p] + 1)
        {
            return true;
        }
        else if (rightPos == parentPos + 1 && leftPos == parentPos + 1 + subtree[2 * p] + 1)
        {
            return true;
        }
        else
        {
            return false;
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
        ll n, q;
        cin >> n >> q;
        fr(i, 2, n)
        {
            ll p;
            cin >> p;
        }
        vll subtree(n + 1, n - 1);
        fr(i, 2, n)
        {
            ll p = i / 2;
            subtree[i] = (subtree[p] / 2) - 1;
        }
        vll A(n + 1);
        vll pos(n + 1);
        fr(i, 1, n)
        {
            cin >> A[i];
            pos[A[i]] = i;
        }
        ll bad = 0;
        fr(i, 1, n)
        {
            if (!isGood(i, n, subtree, A, pos))
            {
                bad++;
            }
        }
        fr(i, 1, q)
        {
            ll x, y;
            cin >> x >> y;
            ll u = A[x], v = A[y];
            set<ll> affected;
            affected.insert(u);
            affected.insert(v);
            if (2 * u <= n)
            {
                affected.insert(2 * u);
            }
            if (2 * v <= n)
            {
                affected.insert(2 * v);
            }
            if (2 * u + 1 <= n)
            {
                affected.insert(2 * u + 1);
            }
            if (2 * v + 1 <= n)
            {
                affected.insert(2 * v + 1);
            }
            if (u / 2 >= 1)
            {
                affected.insert(u / 2);
            }
            if (v / 2 >= 1)
            {
                affected.insert(v / 2);
            }
            for (auto &j : affected)
            {
                if (!isGood(j, n, subtree, A, pos))
                {
                    bad--;
                }
            }
            swap(A[x], A[y]);
            pos[A[x]] = x;
            pos[A[y]] = y;
            for (auto &j : affected)
            {
                if (!isGood(j, n, subtree, A, pos))
                {
                    bad++;
                }
            }
            cout << (bad || pos[1] != 1 ? "NO" : "YES") << endl;
        }
    }
}