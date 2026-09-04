#include <iostream>
using namespace std;
int main()
{
    long long int n, t, k;
    cin >> n >> t >> k;
    long long int l = 0, r = n - 1;
    long long int sum;
    long long int ans;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        cout << "? 1 " << mid + 1 << endl;
        cin >> sum;
        if (mid + 1 - sum < k)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << "! "<<ans + 1 << endl;
}