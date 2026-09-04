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
        vll A(n), H(n);
        fr(i, 0, n)
        {
            cin >> A[i];
        }
        fr(i, 0, n)
        {
            cin >> H[i];
        }
        ll ans = 0;
        ll i = 0, j = 0;
        ll sum = 0;
        while (j < n)
        {
            sum += A[j];
            if (j != 0 && (H[j - 1] % H[j] != 0))
            {
                sum = A[j];
                i = j;
            }
            while (i <= j && sum > k)
            {
                sum -= A[i];
                i++;
            }
            if (i <= j)
            {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        cout << ans << endl;
    }
}