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
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    ll sum = 0;
    ll i = 0;
    while (i < k)
    {
        sum += A[i];
        i++;
    }
    ll maxi = sum, index = 0;
    while (i < n)
    {
        sum += A[i];
        sum -= A[i - k];
        if (sum > maxi)
        {
            maxi = sum;
            index = i - k + 1;
        }
        i++;
    }
    fr(j, 0, k)
    {
        cout << A[index + j] << " ";
    }
    cout << endl;
}