#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (char x)  {                // NOT AN ERROR, but since a char is being
                                    // thrown, use a char to catch instead

        cout << "Caught " << x;   // Undefined identifier 'a' being used
                                    // use 'x' instead
    }
    catch (...)  {              // x is not a data type, use ellipsis instead
        cout << "Default Exception\n";
    }
    return 0;                   //  A return 1 means that there is some error while
                                //  executing the program and it is not 
                                //  performing what it was intended to do.
}