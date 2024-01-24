// #include <iostream>
// using namespace std;

// int main(void) {
// 	int x = 80;
// 	int &y = x;
// 	x++;
// 	cout << x << " " << --y;
// 	cin.get();
// 	return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// long GetNumber(long int Number) {
// 	return --Number;
// }

// float GetNumber(int Number) {
// 	return ++Number;
// }

// int main(void) {
// 	int x = 20;
// 	int y = 30;
// 	cout << GetNumber(x) << " ";
// 	cout << GetNumber(y);

// 	cin.get();
// 	return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// int main(void) {
// 	cout << "  \\/" << endl;
// 	cout << " \\\\//" << endl;
// 	cout << "\\\\\\///" << endl;
// 	cout << "///\\\\\\ " << endl;
// 	cout << " //\\\\ " << endl;
// 	cout << "  /\\ " << endl;

// 	cin.get();
// 	return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// int main() {
// 	float radius;
// 	float area, perimeter;

// 	cout << "Input your circle's radius: " << endl;
// 	cin >> radius;

// 	area = (3.14) * (radius * radius);
// 	perimeter = 2 * 3.14 * radius;

// 	cout << "Area: " << area << endl;
// 	cout << "Perimeter: " << perimeter << endl;

// 	return 0;
// }

/////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// int main(void) {
// 	int feet;
// 	float inch, total_inches, centimeters;

// 	cout << "Input length in feet and inches: " << endl;
// 	cout << "Example:" << endl << "(feet)" << endl << "(inches)" << endl;
// 	cin >> feet >> inch;

// 	total_inches = (feet * 12) + inch;
// 	centimeters = total_inches * 2.54;

// 	cout << "Input in Centimeters is: " << centimeters;

// 	return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <string>
// using namespace std;

// int main(void) {
// 	string inputString;

//     // Taking the whole line as input
// 	cout << "Input a string: " << endl;
// 	getline(cin, inputString);
	
//     // Converting all lowercase alphabets to their upper counterparts
// 	for (int i = 0; i < inputString.length(); i++) {
//   		if(inputString[i] >= 97 && inputString[i] <= 122 ) {
//   			inputString[i] = inputString[i] - 32;
// 		}
//   	}
// 	cout << "Uppercased String: " << inputString;
		
//  	return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// int main ()
// {
//     int numbers[5];
//     int i, j, temp;

//     // Taking the inputs
//     cout << "Enter 5 Numbers: " << endl;

//     for (i = 0; i < 5; ++i) {
//         cin >> numbers[i];
//     }

//     // Main Algorithm
//     for (i = 0; i < 5; ++i)
//     {
//         for (j = i + 1; j < 5; ++j)
//         {
//             if (numbers[i] < numbers[j])
//             {
//                 temp = numbers[i];
//                 numbers[i] = numbers[j];
//                 numbers[j] = temp;
//             }
//         }
//     }

//     // Output
//     cout << "Descending Order: " << endl;
//     for (i = 0; i < 5; ++i)
//     {
//         cout << numbers[i];
//         cout << " ";
//     }

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
    int rows, coef = 1;

    cout << "Enter number of rows: ";
    cin >> rows;

    for (int i = 0; i < rows; i++) {
        for (int space = 1; space <= rows - i; space++)
            cout << "  ";

        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef * (i - j + 1) / j;

            cout << coef << "   ";
        }
        cout << endl;
    }

    return 0;
}