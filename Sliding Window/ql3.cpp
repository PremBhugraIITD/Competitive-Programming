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
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    ll i = 0;
    ll sum = 0;
    mll count;
    while (i < k)
    {
        count[A[i]]++;
        sum += A[i];
        i++;
    }
    ll index = -1;
    ll maxi = INT_MIN;
    if (count.size() == k)
    {
        maxi = sum;
        index = 0;
    }
    while (i < n)
    {
        sum += A[i];
        sum -= A[i - k];
        count[A[i]]++;
        count[A[i - k]]--;
        if (count[A[i - k]] == 0)
        {
            count.erase(A[i - k]);
        }
        if (count.size() == k)
        {
            if (sum > maxi)
            {
                maxi = sum;
                index = i - k + 1;
            }
        }
        i++;
    }
    fr(j, 0, k)
    {
        cout << A[index + j] << " ";
    }
    cout << endl;
}