#include <iostream>
using namespace std;

void TOH(int a, char src, char helper, char desti)
{
    if (a > 0)
    {
        TOH(a - 1, src, desti, helper);
        cout << src << "->" << desti << endl;
        TOH(a - 1, helper, src, desti);
    }
}

int main()
{
    TOH(4, 'A', 'B', 'C');
}
