#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MinValue
{
    int operator()(const vector<int>& vec)
    {
        return *min_element(vec.begin(), vec.end());
    }
};

struct MaxValue
{
    int operator()(const vector<int>& vec)
    {
        return *max_element(vec.begin(), vec.end());
    }
};

struct SortDescending
{
    void operator()(vector<int>& vec)
    {
        sort(vec.begin(), vec.end(), greater<int>());
    }
};

struct SortAscending
{
    void operator()(vector<int>& vec)
    {
        sort(vec.begin(), vec.end());
    }
};

struct IncrementValues
{
    int increment;
    IncrementValues(int inc) : increment(inc) {}
    void operator()(vector<int>& vec) {
        transform(vec.begin(), vec.end(), vec.begin(),
            [this](int val) { return val + increment; });
    }
};

struct DecrementValues
{
    int decrement;
    DecrementValues(int dec) : decrement(dec) {}
    void operator()(vector<int>& vec)
    {
        transform(vec.begin(), vec.end(), vec.begin(),
            [this](int val) { return val - decrement; });
    }
};

struct RemoveValue
{
    int valueToRemove;
    RemoveValue(int value) : valueToRemove(value) {}
    void operator()(vector<int>& vec)
    {
        vec.erase(remove(vec.begin(), vec.end(), valueToRemove), vec.end());
    }
};

int main()
{
    vector<int> numbers = { 10, 20, 30, 40, 45, 50, 60 };

    MinValue minFunc;
    MaxValue maxFunc;
    SortDescending sortDescFunc;
    SortAscending sortAscFunc;
    IncrementValues incrementFunc(5);
    DecrementValues decrementFunc(3);
    RemoveValue removeFunc(30);

    cout << "Min value: " << minFunc(numbers) << endl;
    cout << "Max value: " << maxFunc(numbers) << endl;

    sortDescFunc(numbers);
    cout << "Sorted in descending order: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    sortAscFunc(numbers);
    cout << "Sorted in ascending order: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    incrementFunc(numbers);
    cout << "Increased by 5: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    decrementFunc(numbers);
    cout << "Decreased by 3: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    removeFunc(numbers);
    cout << "Removed elements equal to 30: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    return 0;
}