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
        string a;
        cin >> a;
        vll odd, even;
        fr(i, 0, a.length())
        {
            if ((a[i] - '0') & 1)
            {
                odd.pb(a[i] - '0');
            }
            else
            {
                even.pb(a[i] - '0');
            }
        }
        ll i = 0, j = 0;
        ll o = odd.size(), e = even.size();
        while (i < o && j < e)
        {
            if (odd[i] < even[j])
            {
                cout << odd[i++];
            }
            else // They can never be equal
            {
                cout << even[j++];
            }
        }
        while (i < o)
        {
            cout << odd[i++];
        }
        while (j < e)
        {
            cout << even[j++];
        }
        cout << endl;
    }
}