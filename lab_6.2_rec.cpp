#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i = 0) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i = 0) {
    cout << "a[" << i << "] = " << a[i] << "    ";
    if (i < size - 1) 
        Print(a, size, i + 1);
    else 
        cout << endl;
    
}

int Max(int* a, const int size, int i, int max) {
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}

int Min(int* a, const int size, int i, int min) {
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}

int main() {
    srand((unsigned)time(NULL));

    const int n = 5;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    cout << "Start array: ";
    Print(a, n);

    int min = a[0];
    int max = a[0];

    min = Min(a, n, 0, min);
    max = Max(a, n, 0, max);

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    return 0;
}
