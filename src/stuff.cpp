#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int add(int *a, int b);
int intro_to_pointers();
int intro_to_structs();
int intro_to_arrays();
int intro_to_c_strings();
int intro_to_file_io();
int intro_to_typecasting();
int intro_to_classes();
void handle_command_line_arguments(int argc, char *argv[]);
void generate_linked_list();
int intro_to_vectors();
void intro_to_maps();
void chars_strings();

int main(int argc, char *argv[]) {
	chars_strings();
	return 0;
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

int intro_to_file_io() {
	char str[10];

	//Creates an instance of ofstream, and opens example.txt
	ofstream a_file("example.txt");
	// Outputs to example.txt through a_file
	a_file << "This text will now be inside of example.txt\n";
	// Close the file stream explicitly
	a_file.close();
	//Opens for reading the file
	ifstream b_file("example.txt");
	//Reads one string from the file
	b_file >> str;
	//Should output 'this'
	cout << str << "\n";
	cin.get(); // wait for a keypress
	// b_file is closed implicitly here
	return 0;
}

int intro_to_typecasting() {
	for (int x = 0; x < 256; x++) {
		cout << x << ". " << (char) x << "\n";
	}
	cin.get();
	return 0;
}

class Computer {
public:
	Computer();
	~Computer();
	void setAge(int a);
	int getAge();
protected:
	int age;
};

Computer::Computer() {
	age = -1;
}

Computer::~Computer() {
}

void Computer::setAge(int a) {
	age = a;
}

int Computer::getAge() {
	return age;
}

int intro_to_classes() {
	// Slightly non-obviously (to me, anyway), this calls the constructor:
	Computer compute;

	cout << "Current age: " << compute.getAge() << "\n";
	compute.setAge(38);
	cout << "New age: " << compute.getAge() << "\n";
	return 0;
}

void handle_command_line_arguments(int argc, char *argv[]) {
	if (argc != 2) // argc should be 2 for correct execution
		// We print argv[0] assuming it is the program name
		cout << "usage: " << argv[0] << " <filename>\n";
	else {
		// We assume argv[1] is a filename to open
		ifstream the_file(argv[1]);
		// Always check to see if file opening succeeded
		if (!the_file.is_open())
			cout << "Could not open file: " << argv[1] << "\n";
		else {
			char x;
			// the_file.get ( x ) returns false if the end of the file
			//  is reached or an error occurs
			while (the_file.get(x)) {
				/*
				 * for the avoidance of doubt, this is reading one character
				 * at a time.
				 */
				cout << x;
			}
		}
		// the_file is closed implicitly here
	}

}

struct node {
	int x;
	node *next;
};

void generate_linked_list() {
	// first element
	node *root = new node;
	root->x = 4;
	root->next = new node;

	// second element
	node *nextElement = root->next;
	nextElement->x = 8;
	nextElement->next = new node;

	// third and final element
	nextElement = nextElement->next;
	nextElement->x = 12;
	nextElement->next = 0; // to indicate there are no more elements in the linked list

	nextElement = root;
	while (nextElement != NULL) { // Makes sure there is a place to start
		cout << "nextElement: " << nextElement->x << "\n";
		nextElement = nextElement->next;
	}

}

int intro_to_vectors() {
	vector<int> example; //Vector to store integers
	example.push_back(3); //Add 3 onto the vector
	example.push_back(10); //Add 10 to the end
	example.push_back(33); //Add 33 to the end
	for (unsigned int x = 0; x < example.size(); x++) {
		cout << example[x] << " "; //Should output: 3 10 33
	}
	cout << endl;

	if (!example.empty()) //Checks if empty
		example.clear(); //Clears vector

	/*
	 * here, we create another vector with the same data as the other one,
	 * and show that we can test for equality between them.
	 */
	vector<int> another_vector;
	another_vector.push_back(10);
	example.push_back(10);
	if (example == another_vector) {
		example.push_back(20);
		/*
		 * at this point, example has two entries, 10 and 20
		 */
	}

	/*
	 *  iterate over the vector again, but this time,
	 *  let's use an iterator. this time, we'll see:
	 *
	 *  10 20
	 */
	vector<int>::iterator i;
	for (i = example.begin(); i != example.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}

void intro_to_maps() {
	map<string, int> hash;
	hash["Kenny"] = 38;
	hash["Kathryn"] = 38;
	hash["Lauren"] = 10;
	hash["Rebecca"] = 6;
	hash["Jo"] = 3;

	cout << "There are " << hash.size() << " people in the hash" << endl;

	/*
	 * we need to search for something.  note that we find() on the map,
	 * and the returned value is an iterator object
	 */
	map<string, int>::iterator person = hash.find("Rebecca");

	// now we access the key (first) and value (second)
	cout << "The person is " << person->first << " and their age is "
			<< person->second << endl;

	person = hash.begin();
	cout << "The person deemed at the beginning is " << person->first << endl;

	// now we loop over the entire hash.
	typedef std::map<std::string, int> MapType;
	MapType::const_iterator end = hash.end();
	for (MapType::const_iterator it = hash.begin(); it != end; ++it) {
		std::cout << it->first << " is " << it->second << " years old" << endl;
	}
}

void chars_strings() {
	char one[] = "hello";
	char two[] = { 'c', 'h', 'e', 'e', 'r', 'i', 'o' };
	char three[12];

	cout << "say something: ";
	cin >> three;

	/*
	 * strlen() (from cstring) tells us how long the string in the array is,
	 * no matter how long the array was that was originally defined.  note,
	 * therefore, that three[12] won't return 12, unless of course you
	 * enter a 12 character phrase
	 */
	cout << strlen(one) << " " << strlen(two) << " " << strlen(three);
}
