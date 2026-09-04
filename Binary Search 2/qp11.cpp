#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll <pair<long long int, long long int>>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{

    ll m, n;
    cin >> m >> n;
    vll P(n);
    bool found = false;
    fr(i, 0, n)
    {
        cout << 1 << endl;
        ll input;
        cin >> input;
        if (input == 0)
        {
            found = true;
            break;
        }
        else if (input == 1)
        {
            P[i] = 1;
        }
        else
        {
            P[i] = 0;
        }
    }
    // fr(i, 0, n)
    // {
    //     cout << P[i] << " ";
    // }
    // cout << endl;
    if (!found)
    {
        ll i = 0;
        ll l = 1, r = m;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            // cout << l << " " << r << " " << mid << endl;
            cout << mid << endl;
            ll input;
            cin >> input;
            if (P[i % n] == 0)
            {
                input = -input;
            }
            i++;
            if (input == 0)
            {
                break;
            }
            else if (input == -1)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
}