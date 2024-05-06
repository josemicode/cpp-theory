/*In the context of programming, particularly when dealing with containers such as vectors that hold dynamically allocated objects, memory management is a critical aspect. In the provided C++ program, the vector myVector holds pointers to objects of MyClass that are dynamically allocated using the new operator.

When the use of these objects is no longer required, it is essential to deallocate the memory they occupy. This is achieved by using the delete operator, as demonstrated in the final loop of the program. Failure to properly deallocate memory can result in memory leaks, which can degrade system performance over time and lead to unexpected behavior.

However, manual memory management like this can be error-prone and difficult to manage in complex programs. Therefore, modern C++ provides smart pointers, such as std::unique_ptr and std::shared_ptr, which automatically manage memory. When a smart pointer goes out of scope, it automatically deletes the object it points to, thus preventing memory leaks. For robust and efficient memory management in real-world applications, the use of smart pointers is highly recommended over raw pointers.*/

#include <iostream>
#include <vector>
#include <iterator> // Required for advance

using namespace std;

// Let's create a simple class for demonstration
class MyClass {
	public:
		MyClass(int val) : value(val) {}
		void setValue(int val) { value = val; }
		int getValue() const { return value; }
	private:
		int value;
};

int main() {

	cout << "In this program, we first create a vector of MyClass pointers. We then add dynamically allocated MyClass objects to this vector. We use an iterator to go through the vector and access the MyClass objects. For each object, we print its original value, double the value, and then print the doubled value. Finally, we use another iterator to go through the vector again and delete the dynamically allocated objects.\n" << endl;

	// Create a vector to hold pointers to MyClass objects
	vector<MyClass*> myVector;

	// Add some dynamically allocated objects to the vector
	for (int i = 0; i < 10; ++i) {
		myVector.push_back(new MyClass(i));
	}

	// Use an iterator to go through the vector and manipulate the objects
	for (vector<MyClass*>::iterator it = myVector.begin(); it != myVector.end(); advance(it, 2)) {
		cout << "Original value: " << (*it)->getValue() << endl;
		(*it)->setValue((*it)->getValue() * 2);
		cout << "Doubled value: " << (*it)->getValue() << endl;
	}

	// Don't forget to delete the dynamically allocated objects
	for (vector<MyClass*>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
		delete *it;
	}

	return 0;
}
