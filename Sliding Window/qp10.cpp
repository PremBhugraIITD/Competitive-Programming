#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n, x;
    cin >> n >> x;
    vpll A(n);
    fr(i, 0, n)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A);
    bool found = false;
    int i1, i2, i3;
    fr(i, 0, n)
    {
        ll sum = x - A[i].first;
        ll l = 0, r = n - 1;
        found = false;
        while (l < r)
        {
            if (l == i)
            {
                l++;
                continue;
            }
            if (r == i)
            {
                r--;
                continue;
            }
            ll temp = A[l].first + A[r].first;
            if (temp < sum)
            {
                l++;
            }
            else if (temp > sum)
            {
                r--;
            }
            else
            {
                found = true;
                i1 = A[i].second + 1, i2 = A[l].second + 1, i3 = A[r].second + 1;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    if (found)
    {
        cout << i1 << " " << i2 << " " << i3 << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}