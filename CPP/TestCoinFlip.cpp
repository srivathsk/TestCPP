#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinCoins(std::vector<int>& values, int amount, int curr_pos, int curr_value);

bool greater_than(int i1, int i2)
{
    if (i1 >= i2)
        return true;
    return false;
}

void print(int x)
{
    cout << x << " ";
}

int main()
{
    cout << "Enter coin values " << endl;
    std::vector<int> values;
    int curr_value = 0;
    while (curr_value != -1)
    {
        cin >> curr_value;
        values.push_back(curr_value);
    }
    int amount = 0;
    cout << "Enter amount to find change for " << endl;
    cin >> amount ;
    curr_value = 0;
    int curr_pos = 0;

    std::sort(values.begin(), values.end(), greater_than); 
    std::for_each(values.begin(), values.end(), print);
    cout << endl;
    cout << "Minimum number of coins required is " << findMinCoins(values, amount, curr_pos, curr_value) << endl; 
}

int findMinCoins(std::vector<int>& values, int amount, int curr_pos, int curr_value)
{
    if (curr_value >= amount || curr_pos >= values.size())
        return 0;
    int tmp_Value = curr_value + values[curr_pos];
    if (tmp_Value <= amount)
    {
        return 1 + findMinCoins(values, amount, curr_pos, tmp_Value);
    } else {
        return findMinCoins(values, amount, curr_pos+1, curr_value);
    }
}

