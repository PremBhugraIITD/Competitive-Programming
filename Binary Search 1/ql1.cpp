#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    long long int l, r;
    cin >> l >> r;
    long long int a = n;
    long long int low = 0, high = n - 1;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        // cout << low << " " << high << " " << mid << endl;
        if (A[mid] >= l)
        {
            a = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // cout<<a<<endl;
    long long int b = -1;
    low = 0, high = n - 1;
    while (low <= high)
    {
        long long int mid = (low + high) / 2;
        // cout << low << " " << high << " " << mid << endl;
        if (A[mid] <= r)
        {
            b = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // cout<<b<<endl;
    for (int i = a; i <= b; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}