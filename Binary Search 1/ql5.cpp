#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long double n;
    cin >> n;
    long double precision = 1e-7;
    long double l = 0, r = n;
    long long int iterations = 100;
    long double ans;
    for (long long int i = 0; i < iterations; i++)
    {
        long double mid = (l + r) / 2;
        if (mid * mid <= n)
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