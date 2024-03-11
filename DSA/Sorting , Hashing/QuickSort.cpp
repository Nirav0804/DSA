#include <bits/stdc++.h>
using namespace std;
void QuickSort(int a[], int left, int right)
{
    int Pivot, i, j;
    if (left < right)
    {
        Pivot = a[left];
        i = left;
        j = right + 1;
        do
        {
            do
            {
                i++;
            } while (Pivot > a[i]);
            do
            {
                j--;
            } while (Pivot < a[j]);
            if (i < j)
            {
                swap(a[i], a[j]);
            }
        } while (i < j);
        if (i > j)
        {
            swap(a[left], a[j]);
        }
        QuickSort(a, left, j - 1);
        QuickSort(a, j + 1, right);
    }
}
int main()
{
    int size;
    cout << "Enter No of Elements"
         << "\n";
    cin >>
        size;
    int arr[size];
    cout << "Enter Array"
         << "\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr, 0, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}