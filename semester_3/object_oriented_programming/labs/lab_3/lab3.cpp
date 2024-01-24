// #include <iostream>
// using namespace std;

// void passByReference(int *x, int *y) {
// 	int z = *y;
// 	*y = *x;
// 	*x = z;
// }
// int main()
// {
// 	int a, b, z;
// 	cout << "Enter two variables to swap:\n" << "a: ";
// 	cin >> a;
// 	cout << "b: ";
// 	cin >> b;

// 	cout << "\tPass By Reference Swapping\n";
// 	cout << "Before swapping:\n a: " << a << "\tb: " << b << endl;
// 	passByReference(&a, &b);
// 	cout << "After swapping:\n a: " << a << "\tb: " << b << endl;
// 	return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    cout << "Size of Char: " << sizeof(char) << " byte" << endl;
    cout << "Size of Int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of Long Int: " << sizeof(long int) << " bytes" << endl;
    cout << "Size of Float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of Double: " << sizeof(long double) << " bytes" << endl;

    return 0;
}
