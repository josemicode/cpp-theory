#include <iostream>

using namespace std;

void concatenationEg(string *arrayPtr, string &ref)
{
	// Use the pointer to concatenate the first three elements of the array
	string concat = *(arrayPtr) + *(arrayPtr + 1) + *(arrayPtr + 2);
	cout << "Concatenation of the first three months: " << concat << endl;
}

int countElements(string *arrayPtr, int arraySize)
{
	int count = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (*(arrayPtr + i) != "")
		{
			count++;
		}
	}
	return count;
}

int main()
{

	string months[]{"Jan", "Feb", "Mar", "Apr", "May", "JUN", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	string pos5copy = months[5];
	string &pos5ref = months[5];
	string *arrayPtr = &months[0];

	cout << "Fifth position of the array being called directly: " << months[5] << endl;
	cout << "Value being called from another (copy) variable: " << pos5copy << endl;
	cout << "Position 5's value being called from a reference: " << pos5ref << endl;
	cout << "\nNow the value will be modified...\n" << endl;

	pos5ref = "Jun";

	cout << "Fifth position of the array being called directly: " << months[5] << endl;
	cout << "Value being called from another (copy) variable: " << pos5copy << endl;
	cout << "Position 5's value being called from a reference: " << pos5ref << endl;

	cout << "\nNow, we have initialised a special kind of variable which points at the array's first element: " << arrayPtr << endl;
	cout << "This is a Hexadecimal code that represents the elements's positon in the stack and, as references, needs to be initialised as the same type as the original variable" << endl;
	cout << "We can use it to access its value: " << *arrayPtr << endl;

	cout << "\nOne of its uses is going over array elements, as they are consecutive. The two elements that follow the first are: " << *(arrayPtr + 1) << " and " << *(arrayPtr + 2) << endl;
	cout << "This is done by adding to the pointer's index; we can also get to the last element by using 'sizeof' (or knowing its size beforehand): " << *(arrayPtr + (sizeof(months) / sizeof(*arrayPtr)) - 1) << endl;

	concatenationEg(arrayPtr, pos5ref);

	cout << "Now we will count the elements of the array by using a function which takes the pointer and the number of actual elements. This follows the premise that we have previously implemented " << endl;
	cout << "a method that takes the easiest route in order to delete an element: simply leaving a blank space when found. We do have to give the extent to which the array is filled (not by gibberish elements)." << endl;

	cout << "\nThe initial number of months is: " << countElements(arrayPtr, 12) << endl;

	months[2] = "";
	months[3] = "";
	months[6] = "";
	months[7] = "";

	cout << "Now that we have quote on quote erased some elements [pos: 2, 3, 6, 7]... Here's the result: " << countElements(arrayPtr, 12) << endl;
}