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
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll m;
    cin >> m;
    vll usb, ps2;
    while (m--)
    {
        ll val;
        string type;
        cin >> val >> type;
        if (type == "USB")
        {
            usb.pb(val);
        }
        else
        {
            ps2.pb(val);
        }
    }
    sort(usb);
    sort(ps2);
    ll u = usb.size(), p = ps2.size();
    ll x, y, z, total;
    x = min(a, u);
    u -= x;
    y = min(b, p);
    p -= y;
    z = min(c, p + u);
    total = x + y + z;
    // cout << x << " " << y << " " << z << endl;
    ll cost = 0;
    ll i = 0;
    while (i < x)
    {
        cost += usb[i];
        i++;
    }
    // cout << cost << endl;
    ll j = 0;
    while (j < y)
    {
        cost += ps2[j];
        j++;
    }
    // cout << cost << endl;
    while (i < usb.size() && j < ps2.size() && z)
    {
        if (usb[i] < ps2[j])
        {
            cost += usb[i++];
        }
        else
        {
            cost += ps2[j++];
        }
        z--;
    }
    // cout << cost << endl;
    while (i < usb.size() && z)
    {
        z--;
        cost += usb[i];
        i++;
    }
    while (j < ps2.size() && z)
    {
        z--;
        cost += ps2[j];
        j++;
    }
    cout << total << " " << cost << endl;
}