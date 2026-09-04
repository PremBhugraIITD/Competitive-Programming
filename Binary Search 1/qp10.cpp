#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        long long int temp;
        cin >> temp;
        A[i] = abs(temp);
    }
    long long int ans = 0;
    sort(A.begin(), A.end());
    for (long long int i = 0; i < n; i++)
    {
        ans += upper_bound(A.begin() + i + 1, A.end(), 2 * A[i]) - A.begin() - i - 1;
    }
    cout << ans << endl;
}