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
    int t;
    cin >> t;
    while (t--)
    {
        ll q;
        cin >> q;
        vll count1(26, 0), count2(26, 0);
        ll l1 = 1, l2 = 1;
        count1[0]++;
        count2[0]++;
        while (q--)
        {
            ll d, k;
            cin >> d >> k;
            string x;
            cin >> x;
            if (d == 1)
            {
                fr(i, 0, x.length())
                {
                    count1[x[i] - 'a'] += k;
                }
                l1 += k * x.length();
            }
            else
            {
                fr(i, 0, x.length())
                {
                    count2[x[i] - 'a'] += k;
                }
                l2 += k * x.length();
            }
            if (l1 < l2)
            {
                if (count2[0] == l2)
                { // if all charactrs in t are a
                    if (count1[0] == l1)
                    { // if all characters in s are a
                        cout << "YES" << endl;
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else // t has atleast 1 character other than a
                {
                    cout << "YES" << endl;
                }
            }
            else if (l1 > l2)
            {
                if (count2[0] == l2)
                { // if all charactrs in t are a
                    cout << "NO" << endl;
                }
                else // t has atleast 1 character other than a
                {
                    cout << "YES" << endl;
                }
            }
            else
            {
                if (count2[0] == l2)
                { // if all charactrs in t are a
                    cout << "NO" << endl;
                }
                else // t has atleast 1 character other than a
                {
                    cout << "YES" << endl;
                }
            }
        }
    }
}