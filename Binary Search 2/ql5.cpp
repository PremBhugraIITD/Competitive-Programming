#include <iostream>
using namespace std;
int main()
{
    long long int ans;
    string input;
    long long int l = 0, r = 1e6;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        cin >> input;
        if (input == "<")
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << "! " << ans << endl;
}