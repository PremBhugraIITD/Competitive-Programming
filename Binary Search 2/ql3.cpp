#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool solve(long double x, vector<long long int> &A, long long int d)
{
    long long int n = A.size();
    vector<long double> B(n);
    for (long long int i = 0; i < n; i++)
    {
        B[i] = A[i] - x;
    }
    vector<long double> C(n);
    for (long long int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            C[i] = B[i];
        }
        else
        {
            B[i] = B[i] + B[i - 1];
            C[i] = min(C[i - 1], B[i]);
        }
    }
    for (long long int i = d - 1; i < n; i++)
    {
        if ((B[i] >= (i - d >= 0 ? C[i - d] : 0)) || (B[i] >= 0))
        {
            return true;
        }
    }
    return false;
}

pair<long long int, long long int> findIndices(long double mean, vector<long long int> &A, long long int d)
{
    long long int n = A.size();
    vector<long double> B(n);
    for (long long int i = 0; i < n; i++)
    {
        B[i] = A[i] - mean;
    }
    vector<long double> C(n);
    for (long long int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            C[i] = i;
        }
        else
        {
            B[i] = B[i] + B[i - 1];
            if (B[i] < B[C[i - 1]])
            {
                C[i] = i;
            }
            else
            {
                C[i] = C[i - 1];
            }
        }
    }
    for (long long int i = d - 1; i < n; i++)
    {
        if (B[i] >= ((i - d >= 0) ? B[C[i - d]] : 0))
        {
            return {((i - d >= 0) ? (C[i - d] + 2) : 1), i + 1};
        }
        else if (B[i] >= 0)
        {
            return {1, i + 1};
        }
    }
}

int main()
{
    long long int n, d;
    cin >> n >> d;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    long double mean;
    long double l = 0, r = 100;
    long double precision = 1e-3;
    long long int iterations = 50;
    for (long long int i = 0; i < iterations; i++)
    {
        long double mid = (l + r) / 2;
        if (solve(mid, A, d))
        {
            mean = mid;
            l = mid + precision;
        }
        else
        {
            r = mid - precision;
        }
    }
    pair<long long int, long long int> ans = findIndices(mean, A, d);
    cout << ans.first << " " << ans.second << endl;
}