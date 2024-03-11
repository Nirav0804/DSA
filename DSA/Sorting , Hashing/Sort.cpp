#include <iostream>
using namespace std;
class Sort
{
public:
    void Insertion_Sort(int a[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int key = a[j + 1];
            while (key < a[j] && j >= 0)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }
    void Quick_Sort(int a[], int l, int r)
    {
        int i, j, pivot;
        if (l < r)
        {
            pivot = a[l];
            i = l;
            j = r + 1;
            do
            {
                do
                {
                    i++;
                } while (pivot > a[i]);
                do
                {
                    j--;
                } while (pivot < a[j]);
                if (i < j)
                    Swap(&a[i], &a[j]);
            } while (i < j);
            Swap(&a[l], &a[j]);

            Quick_Sort(a, l, j - 1);
            Quick_Sort(a, j + 1, r);
        }
    }
    void Swap(int *x, int *y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
};
int main()
{
    int n;
    cout << "Enter Size:";
    cin >> n;
    int a[n];
    cout << "Enter Array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Sort A;
    A.Insertion_Sort(a, n);
    // A.Quick_Sort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}