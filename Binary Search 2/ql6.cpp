#include <iostream>
#include <vector>
#include <map>
#include <random>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int turns = 100;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long int> dist(1, n);
    while (turns--)
    {
        long long int index;
        index = dist(gen);
        cout << "? " << index << endl;
        long long int input;
        cin >> input;
        if (input == 0)
        {
            continue;
        }
        else
        {
            cout << "! " << index << endl;
            break;
        }
    }
}