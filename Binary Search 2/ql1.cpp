#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool solve(long double x, vector<pair<long long int, long long int>> A, long long int k)
{
    long long int n = A.size();
    vector<long double> B(n);
    for (long long int i = 0; i < n; i++)
    {
        B[i] = A[i].first - x * A[i].second;
    }
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    long double sum = 0;
    for (long long int i = 0; i < k; i++)
    {
        sum += B[i];
    }
    return sum >= 0;
}

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<pair<long long int, long long int>> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i].first >> A[i].second;
    }
    long double precision = 1e-7;
    long long int iterations = 60;
    double ans;
    long double l = 0, r = 1e6;
    for (long long int i = 0; i < iterations; i++)
    {
        long double mid = (l + r) / 2;
        if (solve(mid, A, k))
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