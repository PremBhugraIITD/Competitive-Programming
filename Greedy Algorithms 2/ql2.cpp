#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n, m;
    cin >> n >> m;
    vpll A(n);
    fr(i, 0, n)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    mll count;
    fr(i, 0, n)
    {
        count[A[i].first]++;
    }
    sort(A);
    ll average = n / m, rem = n % m;
    ll r = n - 1;
    ll ans = 0;
    fr(value, 1, m + 1)
    {
        if (count[value] >= average)
        {
            continue;
        }
        else
        {
            while (A[r].first > m)
            {
                count[A[r].first]--;
                A[r].first = value;
                count[value]++;
                r--;
                ans++;
                if (count[value] == average)
                {
                    break;
                }
            }
        }
    }
    vector<vll> temp;
    fr(i, 0, n)
    {
        ll value = A[i].first, index = A[i].second;
        if (value <= m)
        {
            temp.pb({count[value], value, index});
        }
        else
        {
            break;
        }
    }
    sort(temp);
    r = temp.size() - 1;
    fr(value, 1, m + 1)
    {
        while (count[value] < average)
        {
            while (count[temp[r][1]] == average)
            {
                r--;
            }
            count[temp[r][1]]--;
            count[value]++;
            temp[r][1] = value;
            r--;
            ans++;
        }
    }
    vll result(n);
    fr(i, 0, n)
    {
        result[A[i].second] = A[i].first;
    }
    fr(i, 0, temp.size())
    {
        result[temp[i][2]] = temp[i][1];
    }
    cout << average << " " << ans << endl;
    fr(i, 0, n)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}