#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> ans(n);
    long long int prevSum = 0;
    long long int s13;
    for (long long int i = n; i >= 2; i--)
    {
        cout << "? 1 " << i << endl;
        long long int sum;
        cin >> sum;
        if (i != n)
        {
            ans[i] = prevSum - sum;
        }
        prevSum = sum;
        if (i == 3)
        {
            s13 = sum;
        }
    }
    long long int s23;
    cout << "? 2 3" << endl;
    cin >> s23;
    ans[0] = s13 - s23;
    ans[1] = s23 - ans[2];
    cout << "! ";
    for (long long int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}