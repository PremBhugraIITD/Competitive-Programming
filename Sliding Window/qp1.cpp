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
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n;
    cin >> n;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    sort(A);
    vll ans(n);
    ll j = 0;
    fr(i, 1, n)
    {
        ans[i] = A[j];
        j++;
        i++;
    }
    fr(i, 0, n)
    {
        ans[i] = A[j];
        j++;
        i++;
    }
    ll count = 0;
    fr(i, 0, n)
    {
        if (i > 0 && i < n - 1)
        {
            if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])
            {
                count++;
            }
        }
    }
    cout << count << endl;
    fr(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}