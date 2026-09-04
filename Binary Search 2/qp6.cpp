#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> A(n);
        for (long long int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        vector<long long int> prefixSum(n, 0);
        prefixSum[0] = A[0];
        for (long long int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + A[i];
        }
        long long int l = 0, r = n - 1;
        long long int ans;
        while (l <= r)
        {
            long long int mid = (l + r) / 2;
            cout << "? " << mid + 1 << " ";
            long long int sum = prefixSum[mid];
            for (long long int i = 1; i <= mid + 1; i++)
            {
                cout << i << " ";
            }
            cout << endl;
            long long int input;
            cin >> input;
            if (input > sum)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << "! " << ans + 1 << endl;
    }
}