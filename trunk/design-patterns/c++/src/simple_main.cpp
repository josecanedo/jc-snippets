#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

extern int inner_main(int argc, char * argv[]);

int main(int argc, char* argv[])
{
	inner_main(argc, argv);

	cout << "Enter any key to exit" << endl;
	getch();
	return 0;
}