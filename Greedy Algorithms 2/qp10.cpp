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
    int t;
    cin >> t;
    while (t--)
    {
        ll w, h, n;
        cin >> w >> h >> n;
        vll X(n), Y(n);
        fr(i, 0, n)
        {
            cin >> X[i] >> Y[i];
        }
        sort(X);
        sort(Y);
        ll maxLength = 0, maxBreadth = 0;
        fr(i, 0, n)
        {
            if (i == 0)
            {
                maxLength = max(maxLength, X[i] - 1);
                maxBreadth = max(maxBreadth, Y[i] - 1);
            }
            else
            {
                maxLength = max(maxLength, X[i] - X[i - 1] - 1);
                maxBreadth = max(maxBreadth, Y[i] - Y[i - 1] - 1);
            }
        }
        if (n > 0)
        {
            maxLength = max(maxLength, w - X[n - 1]);
            maxBreadth = max(maxBreadth, h - Y[n - 1]);
        }
        else{
            maxLength = w;
            maxBreadth = h;
        }
        cout << maxLength * maxBreadth << endl;
    }
}