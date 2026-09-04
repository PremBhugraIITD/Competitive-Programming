#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mod 1000000007

int main()
{
    vll numbers = {4, 8, 15, 16, 23, 42};
    vll ans(6, -1);
    vll temp(4, -1);
    fr(i, 2, 6)
    {
        cout << "? 1 " << i << endl;
        cin >> temp[i - 2];
    }
    ll limit = 4;
    while (limit > 0)
    {
        fr(i, 0, 6)
        {
            ll number = numbers[i];
            if (number != -1)
            {
                ll score = 0;
                fr(j, 0, limit)
                {
                    if ((number == 16 && temp[j] == 32) || (number == 16 && temp[j] == 8 * 42) || (number == 16 && temp[j] == 4 * 42) || (number == 8 && temp[j] == 64) || (number == 8 && temp[j] == 16 * 42) || (number == 8 && temp[j] == 16 * 15) || (number == 8 && temp[j] == 16 * 23) || (number == 8 && temp[j] == 4 * 42) || (number == 4 && temp[j] == 128) || (number == 4 && temp[j] == 16 * 42) || (number == 4 && temp[j] == 16 * 15) || (number == 4 && temp[j] == 16 * 23) || (number == 4 && temp[j] == 8 * 42) || (number == 4 && temp[j] == 8 * 15) || (number == 4 && temp[j] == 8 * 23) || (temp[j] % number != 0))
                    {
                        score++;
                    }
                }
                if (score == limit)
                {
                    ans[limit + 1] = number;
                    numbers[i] = -1;
                    break;
                }
            }
        }
        limit--;
    }
    long long int maxi = INT_MIN;
    long long int mini = INT_MAX;
    fr(i, 0, 6)
    {
        maxi = max(maxi, numbers[i]);
        if (numbers[i] != -1)
        {
            mini = min(mini, numbers[i]);
        }
    }
    ll number = maxi;
    ll score = 0;
    fr(j, 0, 4)
    {
        if (temp[j] % number == 0)
        {
            score++;
        }
    }
    if (score == 4)
    {
        ans[0] = number;
        ans[1] = mini;
    }
    else
    {
        ans[0] = mini;
        ans[1] = number;
    }
    cout << "! ";
    fr(i, 0, 6)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}