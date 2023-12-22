/*// Let us see how namespace scope the entities including variable and functions:

#include <iostream>
using namespace std;

// first name space
namespace first_space
{
   void func()
   {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space
{
   void func()
   {
      cout << "Inside second_space" << endl;
   }
}

int main ()
{
    // Calls function from first name space.
   first_space::func();
    // Calls function from second name space.
   second_space::func(); 
   return 0;
}

// If we compile and run above code, this would produce the following result:
// Inside first_space
// Inside second_space*/

#include <iostream>
using namespace std;

// first name space
namespace first_space
{
   void func()
   {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space
{
   void func()
   {
      cout << "Inside second_space" << endl;
   }
}

using namespace second_space;

int main ()
{
    // This calls function from first name space.
   func();
   return 0;
}

// If we compile and run above code, this would produce the following result:
// Inside first_space