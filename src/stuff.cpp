#include <iostream>

using namespace std;

int add(int *a, int b);
int intro_to_pointers();
int intro_to_structs();
int intro_to_arrays();
int intro_to_c_strings();

int main() {
	return intro_to_c_strings();
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

int intro_to_arrays() {
	int x;
	int y;
	int array[8][8]; // Declares an array like a chessboard

	for (x = 0; x < 8; x++) {
		for (y = 0; y < 8; y++)
			array[x][y] = x * y; // Set each element to a value
	}
	cout << "Array Indices:\n";
	for (x = 0; x < 8; x++) {
		for (y = 0; y < 8; y++)
			cout << "[" << x << "][" << y << "]=" << array[x][y] << " ";
		cout << "\n";
	}

	/*
	 * Here we show that the address of the array is actually the
	 * address of the first element of the array.
	 */
	cout << "looking at the array itself shows a pointer address of: " << array
			<< "\n";
	cout << "the address of the first element: " << &array[0][0] << "\n";
	cout << "the address of the second element: " << &array[0][1] << "\n";

	cin.get();
	return 0;
}

int intro_to_c_strings() {
	char name[50];
	char lastname[50];
	char fullname[100]; // Big enough to hold both name and lastname

	cout << "Please enter your name: ";
	cin.getline(name, 50);
	if (strcmp(name, "Julienne") == 0) // Equal strings
		cout << "That's my name too.\n";
	else
		// Not equal
		cout << "That's not my name.\n";
	// Find the length of your name
	cout << "Your name is " << strlen(name) << " letters long\n";
	cout << "Enter your last name: ";
	cin.getline(lastname, 50);
	fullname[0] = '\0'; // strcat searches for '\0' to cat after
	strcat(fullname, name); // Copy name into full name
	strcat(fullname, " "); // We want to separate the names by a space
	strcat(fullname, lastname); // Copy lastname onto the end of fullname
	cout << "Your full name is " << fullname << "\n";
	cin.get();
	return 0;
}
