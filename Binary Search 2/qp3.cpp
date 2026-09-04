#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int limit = sqrt(2 * n - 1) + 1;
        long long int ans = 0;
        for (long long int a = 1; a < limit; a += 2)
        {
            long long int b = (a * a - 1) / 2;
            long long int c = (a * a + 1) / 2;
            if ((a < b && b < c) && (c == a * a - b) && (c * c == a * a + b * b))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}