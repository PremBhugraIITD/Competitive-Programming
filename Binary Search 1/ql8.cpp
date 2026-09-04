#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool solve(long double time, vector<pair<long long int, long long int>> &A)
{
    long long int i = 0;
    long double x = A[i].first;
    long long int v = A[i].second;
    long double distance = v * time;
    long double prevLeft = x - distance;
    long double prevRight = x + distance;
    i++;
    for (; i < A.size(); i++)
    {
        x = A[i].first;
        v = A[i].second;
        distance = v * time;
        long double currLeft = x - distance;
        long double currRight = x + distance;
        prevLeft = max(prevLeft, currLeft);
        prevRight = min(prevRight, currRight);
        if (prevLeft > prevRight)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int>> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i].first >> A[i].second;
    }
    long double l = 0, r = 1e10;
    long double ans;
    long long int iterations = 100;
    long double precision = 1e-7;
    for (long long int i = 0; i < iterations; i++)
    {
        long double mid = (l + r) / 2;
        // cout << setprecision(10) << l << " " << r << " " << mid << endl;
        if (solve(mid, A))
        {
            ans = mid;
            r = mid - precision;
        }
        else
        {
            l = mid + precision;
        }
    }
    cout << setprecision(10) << ans << endl;
}