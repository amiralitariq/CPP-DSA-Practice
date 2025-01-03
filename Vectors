#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> cars;

	cars = { "Suzuki","Hyundai","Honda","Tesla" };

	for (string car : cars)
	{
		cout << car << " ";
	}
	cout << endl;

	cout << "First Element in the vector is: " << cars.front() << endl;
	cout << "Last Element in the vector is: " << cars.back() << endl;


	cout << "Changing first element of a vector \n";

	cars[0] = "Haval";

	for (int i = 0;i < cars.size();i++)
	{
		cout << cars[i] << "\n";
	}

	cout << "Car at first index is: " << cars[1] << endl;

	cars.push_back("BMW");

	cout << "New car list is \n";
	for (int i = 0;i < cars.size();i++)
	{
		cout << cars[i] << "\n";
	}

	/*Deleting an Element*/
	cars.pop_back();

	cout << "New car list after poping back \n";
	for (int i = 0;i < cars.size();i++)
	{
		cout << cars[i] << "\n";
	}
	return 0;
}
