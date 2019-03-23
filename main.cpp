#include <iostream>
#include <fstream>
#include "List.h"
#include <assert.h>

using namespace std;

fstream fin("list.in");

int main()
{
    List a, b;
    fin >> a >> b;
    cout << a << b << a + b;
    cout << a[1]->value;
    if(a < b)
        cout << "first list is greater than the second" << '\n';
        else
        cout << "second list is greater than the first";
    if(a > b)
        cout << "second list is greater than the first";
        else
        cout << "first list is greater than the second" << '\n';
    cout << "first list " << a << '\n';
    a.mirror();
    cout << "first list mirrored  " << a;

    return 0;
}
