#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool solveMean(long double x, vector<long long int> A)
{
    long long int n = A.size();
    vector<long double> B(n);
    for (long long int i = 0; i < n; i++)
    {
        B[i] = A[i] - x;
        // cout << B[i] << " ";
    }
    // cout << endl;
    for (long long int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            continue;
        }
        else if (i == 1)
        {
            B[i] = B[i] + max(B[i - 1], (long double)0);
        }
        else
        {
            B[i] = B[i] + max(B[i - 1], B[i - 2]);
        }
    }
    return (max(B[n - 1], B[n - 2]) >= 0);
}

bool solveMedian(long long int x, vector<long long int> A)
{
    long long int n = A.size();
    vector<long long int> B(n);
    for (long long int i = 0; i < n; i++)
    {
        B[i] = (A[i] >= x ? 1 : -1);
        // cout << B[i] << " ";
    }
    // cout << endl;
    for (long long int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            continue;
        }
        else if (i == 1)
        {
            B[i] = B[i] + max(B[i - 1], (long long int)0);
        }
        else
        {
            B[i] = B[i] + max(B[i - 1], B[i - 2]);
        }
    }
    return (max(B[n - 1], B[n - 2]) > 0);
}

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    long double l = 0, r = 1e9;
    long double mean = -1;
    long double precision = 1e-4;
    long long int iterations = 100;
    for (long long int i = 0; i < iterations; i++)
    {
        long double mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (solveMean(mid, A))
        {
            mean = mid;
            l = mid + precision;
        }
        else
        {
            r = mid - precision;
        }
    }
    long long int median = -1;
    long long int d = 0, u = 1e9;
    while (d <= u)
    {
        long long int mid = (d + u) / 2;
        if (solveMedian(mid, A))
        {
            median = mid;
            d = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
    }
    cout << setprecision(10) << mean << endl
         << median << endl;
}