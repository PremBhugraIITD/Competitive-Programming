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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll A(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        ll peaks = 0;
        fr(i, 0, k)
        {
            if (i > 0 && i < k - 1 && A[i] > A[i - 1] && A[i] > A[i + 1])
            {
                peaks++;
            }
        }
        ll maxPeaks = peaks;
        ll l = 0;
        fr(i, k, n)
        {
            if (A[i - 1] > A[i] && A[i - 1] > A[i - 2])
            {
                peaks++;
            }
            if (A[i - k + 1] > A[i - k] && A[i - k + 1] > A[i - k + 2])
            {
                peaks--;
            }
            if (peaks > maxPeaks)
            {
                maxPeaks = peaks;
                l = i - k + 1;
            }
        }
        cout << maxPeaks + 1 << " " << l + 1 << endl;
    }
}