#include <iostream>
using namespace std;

void random(int arr[], int size)
{
    
    for (int i = 0; i < size; ++i)
    {
        int randIndex = rand() % size;
    
        swap(arr[randIndex], arr[i]);
    }
}


int findRandNumber(int arr[], int size)
{
    int randIndex = rand() % size;
    int value = arr[randIndex];
    cout << "Random number: " << value;
    cout << endl;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == value)
        {
            cout << "the index of the same number is: " << i;
            return i;
        }
    }
    cout << "No match found" << endl;
}
int pivot(int* arr, int size)
{
    srand(time(0));
    int randIndex = rand() % size;
    cout << "Random index: " << randIndex << ", value: " << *(arr + randIndex) << endl;
    return randIndex;
}
void bubbleSort(int* arr, int start, int end, bool ascending)
{
    for (int i = start; i < end; i++)
    {
        for (int j = start; j < end - (i - start); j++)
        {
            if ((ascending && *(arr + j) > *(arr + j + 1)) || (!ascending && *(arr + j) < *(arr + j + 1)))
            {
                swap(*(arr + j), *(arr + j + 1));
            }
        }
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    const int SIZE = 20;
    int arr[SIZE] = { 2, 4, 5, 13, 17, 15, 19, 9, 11, 7, 20, 18, 16, 12, 8, 14, 10, 3, 6, 1};
    for (int i = 0; i < SIZE; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    random(arr, SIZE);
    cout << "scattered array in a random way: ";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    cout << endl;
    cout << endl;
    findRandNumber(arr, SIZE);
    cout << endl;
    cout << endl;
    cout << endl;
    int pivotIndex = pivot(arr, SIZE);
    bubbleSort(arr, 0, pivotIndex - 1, false);
    bubbleSort(arr, pivotIndex + 1, SIZE - 1, true);
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(arr + i) << " ";
    }
    return 0;
}

