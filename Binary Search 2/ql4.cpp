#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> ans(n, -1);
    cout << "? 1 2" << endl;
    long long int x1;
    cin >> x1;
    cout << "? 2 3" << endl;
    long long int x2;
    cin >> x2;
    cout << "? 1 3" << endl;
    long long int x3;
    cin >> x3;
    ans[0] = (x1 - x2 + x3) / 2;
    ans[1] = x1 - ans[0];
    ans[2] = x2 - ans[1];
    for (long long int i = 4; i <= n; i++)
    {
        cout << "? 1 " << i << endl;
        long long int x;
        cin >> x;
        ans[i - 1] = x - ans[0];
    }
    cout << "! ";
    for (long long int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}