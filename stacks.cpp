
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> cars;

    /* Adding Elements in Stack */
    cars.push("Tesla");
    cars.push("BMW");
    cars.push("Audi");
    cars.push("Hyundai");

    /* As Stack follows Last In First Out (LIFO), we print elements using top() and pop() */
    cout << "Cars in the stack (LIFO order):" << endl;

    while (!cars.empty()) {
        cout << cars.top() << endl; // Access the top element
        cars.pop();                 // Remove the top element
    }

    return 0;
}
