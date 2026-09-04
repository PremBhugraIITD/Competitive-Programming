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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll countClosing = 0;
        fr(i, 0, n)
        {
            if (s[i] == ')')
            {
                countClosing++;
            }
        }
        if (countClosing == n - countClosing)
        {
            vll temp(n);
            ll score = 0;
            bool positive = false, negative = false;
            fr(i, 0, n)
            {
                if (s[i] == '(')
                {
                    score++;
                }
                else
                {
                    score--;
                }
                temp[i] = score;
                if (score > 0)
                {
                    positive = true;
                }
                else if (score < 0)
                {
                    negative = true;
                }
            }
            if (positive && negative)
            {
                cout << 2 << endl;
                fr(i, 0, n)
                {
                    if (temp[i] > 0)
                    {
                        cout << 1 << " ";
                        if (temp[i + 1] == 0)
                        {
                            cout << 1 << " ";
                            i++;
                        }
                    }
                    else if (temp[i] < 0)
                    {
                        cout << 2 << " ";
                        if (temp[i + 1] == 0)
                        {
                            cout << 2 << " ";
                            i++;
                        }
                    }
                }
                cout << endl;
            }
            else
            {
                cout << 1 << endl;
                fr(i, 0, n)
                {
                    cout << 1 << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}