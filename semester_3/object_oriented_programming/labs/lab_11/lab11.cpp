#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template <typename T>
T matrix(int dim)
{
    T** sum = new T*[dim];
    for (int i = 0; i < dim; i++) {
        sum[i] = new T[dim];
    }
    T** diff = new T*[dim];
    for (int i = 0; i < dim; i++) {
        diff[i] = new T[dim];
    }
    T** mult = new T*[dim];
    for (int i = 0; i < dim; i++) {
        mult[i] = new T[dim];
    }

    int i, j;
    int r = dim, c = dim;

    T** ptr1 = new T*[dim];
    for (int i = 0; i < dim; i++) {
        ptr1[i] = new T[dim];
    }

    T** ptr2 = new T*[dim];
    for (int i = 0; i < dim; i++) {
        ptr2[i] = new T[dim];
    }

    // Storing elements of first matrix entered by user.
    cout << endl
         << "Enter elements of 1st matrix: " << endl;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            cout << "Enter element A" << i + 1 << j + 1 << ": ";
            cin >> ptr1[i][j];
        }
    }

    // Storing elements of second matrix entered by user.
    cout << endl
         << "Enter elements of 2nd matrix: " << endl;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            cout << "Enter element B" << i + 1 << j + 1 << ": ";
            cin >> ptr2[i][j];
        }
    }

    // Displaying the resultant sum matrix.
    // Adding two matrices
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            sum[i][j] = ptr1[i][j] + ptr2[i][j];
        }
    }
    cout << endl
         << "Sum of two matrices yields: " << endl;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            cout << sum[i][j] << "  ";
            if (j == c - 1)
                cout << endl;
        }
    }

    // Displaying the resultant diff matrix.
    // Subtracting two matrices
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            diff[i][j] = ptr1[i][j] - ptr2[i][j];
        }
    }
    cout << endl
         << "Diffenece of two matrices yields: " << endl;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            cout << diff[i][j] << "  ";
            if (j == c - 1)
                cout << endl;
        }
    }

    // Displaying the multiplication of two matrix.
    // Initializing elements of matrix mult to 0.
    for (i = 0; i < dim; ++i) {
        for (j = 0; j < dim; ++j) {
            mult[i][j] = 0;
        }
    }
    // Multiplying matrix a and b and storing in array mult.
    for (i = 0; i < dim; ++i) {
        for (j = 0; j < dim; ++j)
            for (int k = 0; k < dim; ++k) {
                mult[i][j] += ptr1[i][k] * ptr2[k][j];
            }
    }
    cout << endl
         << "Multiplication of two matrices yields: " << endl;
    for (i = 0; i < dim; ++i) {
        for (j = 0; j < dim; ++j) {
            cout << " " << mult[i][j];
            if (j == c - 1)
                cout << endl;
        }
    }
    return 0;
}

int main()
{
    int dimension;
    cout << "Input dimension of matrix: ";
    cin >> dimension;
    
    matrix<float>(dimension);
    cout << endl;
    return 0;
}