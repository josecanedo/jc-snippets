// Saying Hello with C++
#include <iostream> // Stream declarations
using namespace std;
int main() {
	cout << "Hello, World! I am "
	<< 8 << " Today!" << endl;
} ///:~

// More streams features
#include <iostream>
using namespace std;
int main() {
	// Specifying formats with manipulators:
	cout << "a number in decimal: "
	<< dec << 15 << endl;
	cout << "in octal: " << oct << 15 << endl;
	cout << "in hex: " << hex << 15 << endl;
	cout << "a floating-point number: "
	<< 3.14159 << endl;
	cout << "non-printing char (escape): "
	<< char(27) << endl;
} ///:~

/// reading input
// Converts decimal to octal and hex
#include <iostream>
using namespace std;
int main() {
	int number;
	cout << "Enter a decimal number: ";
	cin >> number;
	cout << "value in octal = 0"
	<< oct << number << endl;
	cout << "value in hex = 0x"
	<< hex << number << endl;
} ///:~

// The basics of the Standard C++ string class
#include <string>
#include <iostream>
using namespace std;
int main() {
	string s1, s2; // Empty strings
	string s3 = "Hello, World."; // Initialized
	string s4("I am"); // Also initialized
	s2 = "Today"; // Assigning to a string
	s1 = s3 + " " + s4; // Combining strings
	s1 += " 8 "; // Appending to a string
	cout << s1 + s2 + "!" << endl;
} ///:~


// Copy one file to another, a line at a time
#include <string>
#include <fstream>
using namespace std;
int main() {
	ifstream in("Scopy.cpp"); // Open for reading
	ofstream out("Scopy2.cpp"); // Open for writing
	string s;
	while(getline(in, s)) // Discards newline char
	out << s << "\n"; // ... must add it back
} ///:~


// Copy an entire file into a vector of string
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
	vector<string> v;
	ifstream in("Fillvector.cpp");
	string line;
	while(getline(in, line))
	v.push_back(line); // Add the line to the end
	// Add line numbers:
	for(int i = 0; i < v.size(); i++)
	cout << i << ": " << v[i] << endl;
} ///:~

// Break a file into whitespace-separated words
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
	vector<string> words;
	ifstream in("GetWords.cpp");
	string word;
	while(in >> word)
	words.push_back(word);
	for(int i = 0; i < words.size(); i++)
	cout << words[i] << endl;
} ///:~








