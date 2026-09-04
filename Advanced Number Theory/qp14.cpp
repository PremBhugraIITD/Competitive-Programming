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
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "Yes" << endl;
    }
    else if (n == 1)
    {
        if (k == 2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (k >= n)
    {
        cout << "No" << endl;
    }
    else
    {
        // k>1 and k<n
        if (!(n & 1))
        {
            cout << "No" << endl;
        }
        else
        {
            bool found = false;
            fr(i, 1, k + 1)
            {
                if ((n + 1) % i == 0)
                {
                    continue;
                }
                else
                {
                    found = true;
                    cout << "No" << endl;
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