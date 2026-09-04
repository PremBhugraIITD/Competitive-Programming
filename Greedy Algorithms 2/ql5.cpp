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
    ll n;
    cin >> n;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    string ans;
    ll l = 0, r = n - 1;
    while (l <= r)
    {
        if (A[l] < A[r])
        {
            ans.pb('L');
            l++;
            if (A[l] <= A[l - 1])
            {
                ll scoreRight = 1;
                frr(i, r, l + 1)
                {
                    if (A[i - 1] > A[i])
                    {
                        scoreRight++;
                    }
                    else
                    {
                        break;
                    }
                }
                while (scoreRight--)
                {
                    ans.push_back('R');
                }
                break;
            }
        }
        else if (A[l] > A[r])
        {
            ans.pb('R');
            r--;
            if (A[r] <= A[r + 1])
            {
                ll scoreLeft = 1;
                fr(i, l, r)
                {
                    if (A[i] < A[i + 1])
                    {
                        scoreLeft++;
                    }
                    else
                    {
                        break;
                    }
                }
                while (scoreLeft--)
                {
                    ans.push_back('L');
                }
                break;
            }
        }
        else
        {
            ll scoreLeft = 1, scoreRight = 1;
            fr(i, l, r)
            {
                if (A[i] < A[i + 1])
                {
                    scoreLeft++;
                }
                else
                {
                    break;
                }
            }
            frr(i, r, l + 1)
            {
                if (A[i - 1] > A[i])
                {
                    scoreRight++;
                }
                else
                {
                    break;
                }
            }
            if (scoreLeft >= scoreRight)
            {
                while (scoreLeft--)
                {
                    ans.pb('L');
                }
            }
            else
            {
                while (scoreRight--)
                {
                    ans.pb('R');
                }
            }
            break;
        }
    }
    cout << ans.length() << endl
         << ans << endl;
}