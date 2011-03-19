#include <iostream>

using namespace std;

int add(int *a, int b);
int intro_to_pointers();
int intro_to_structs();

int main() {
	// return intro_to_pointers();
	return intro_to_structs();
}

int intro_to_pointers() {
	cout << "intro_to_pointers() called\n";

	/*
	 * Note that a is a pointer and b is a regular int.  note the
	 * difference in how they are handled to get the value, but
	 * the same thing is done to get the actual address (although
	 * I'm not sure there's any point in doing that)
	 */
	int *a = new int;
	int b;

	cout << "Please enter a number: ";
	cin >> *a;
	cin.ignore();
	cout << "address of a is " << &a << " and a itself is " << *a << "\n";
	cout << "And another: ";
	cin >> b;
	cin.ignore();
	cout << "address of b is " << &b << " and b itself is " << b << "\n";
	cout << "You entered: " << add(a, b) << "\n";
	cin.get();
	return 0;
}

int add(int *a, int b) {
	return *a + b;
}

struct xampl {
	int x;
};

int intro_to_structs() {
	cout << "intro_to_structs() called\n";
	xampl structure;
	xampl *ptr;

	structure.x = 12;

	// Yes, you need the & when dealing with structures
	//  and using pointers to them
	ptr = &structure;

	// The -> acts somewhat like the * when used with pointers
	//  It says, get whatever is at that memory address
	//  Not "get what that memory address is"
	cout << ptr->x;

	cin.get();
	return 0;
}
