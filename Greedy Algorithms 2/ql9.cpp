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
        string s;
        cin >> s;
        ll n = s.length();
        ll count = 0;
        fr(i, 0, n)
        {
            if (s[i] == '?')
            {
                count++;
            }
        }
        if (count == n)
        {
            if (n == 2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (s[0] == '?')
            {
                s[0] = '(';
            }
            if (s[n - 1] == '?')
            {
                s[n - 1] = ')';
            }
            if (count <= 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                ll countOpen = 0;
                fr(i, 0, n)
                {
                    if (s[i] == '(')
                    {
                        countOpen++;
                    }
                }
                ll reqOpen = (n / 2) - countOpen;
                fr(i, 0, n)
                {
                    if (s[i] == '?')
                    {
                        if (reqOpen)
                        {
                            reqOpen--;
                            s[i] = '{';
                        }
                        else
                        {
                            s[i] = '}';
                        }
                    }
                }
                // cout << s << endl;
                countOpen = 0;
                ll countClose = 0;
                fr(i, 0, n)
                {
                    if (s[i] == '{')
                    {
                        countOpen++;
                    }
                    else if (s[i] == '}')
                    {
                        countClose++;
                    }
                }
                if (countOpen == 0 || countClose == 0)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    ll openIndex, closeIndex = -1;
                    fr(i, 0, n)
                    {
                        if (s[i] == '{')
                        {
                            openIndex = i;
                        }
                        else if (s[i] == '}' && closeIndex == -1)
                        {
                            closeIndex = i;
                        }
                    }
                    swap(s[openIndex], s[closeIndex]);
                    ll score = 0;
                    fr(i, 0, n)
                    {
                        if (s[i] == '(' || s[i] == '{')
                        {
                            score++;
                        }
                        else
                        {
                            score--;
                        }
                        if (score < 0)
                        {
                            break;
                        }
                    }
                    if (score == 0)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
            }
        }
    }
}