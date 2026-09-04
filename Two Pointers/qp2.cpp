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
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
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
    mll count;
    ll ans = 0;
    ll i = 0, j = 0;
    while (j < n)
    {
        count[A[j]]++;
        while (i <= j && count.size() > k)
        {
            count[A[i]]--;
            if (count[A[i]] == 0)
            {
                count.erase(A[i]);
            }
            i++;
        }
        if (i <= j)
        {
            ans += (j - i + 1);
        }
        j++;
    }
    cout << ans << endl;
}