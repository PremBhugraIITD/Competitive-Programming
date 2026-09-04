#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits.h>
using namespace std;

bool solve(long double x, long long int k, vector<long long int> &A)
{
    for (long long int i = 0; i < A.size(); i++)
    {
        long long int length = A[i];
        if (length < x)
        {
            continue;
        }
        else
        {
            long long int pieces = length / x;
            if (pieces >= k)
            {
                return true;
            }
            else
            {
                k -= pieces;
            }
        }
    }
    return false;
}

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> A(n);
    long long int maxi = INT_MIN;
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
        maxi = max(maxi, A[i]);
    }
    long double precision = 1e-7;
    long double l = 0, r = maxi;
    long double ans;
    long long int iterations = 100;
    for (long long int i = 0; i < iterations; i++)
    {
        long double mid = (l + r) / 2;
        // cout << "mid: " << mid << endl;
        if (solve(mid, k, A))
        {
            ans = mid;
            l = mid + precision;
        }
        else
        {
            r = mid - precision;
        }
    }
    cout << setprecision(10) << ans << endl;
}