//const_cast<>
//static_cast<>
//dynamic_cast<>
//reinterpret_cast<>


//: C03:SimpleCast.cpp
int main() {
	int b = 200;
	unsigned long a = (unsigned long int)b;
} ///:~


//: C03:FunctionCallCast.cpp
int main() {
	float a = float(200);
	// This is equivalent to:
	float b = (float)200;
} ///:~

////////////////////////////////////////////////////////////
//static_cast For “well-behaved” and
//“reasonably well-behaved” casts,
//including things you might now
//do without a cast (such as an
//automatic type conversion).
//: C03:static_cast.cpp
void func(int) {}
int main() {
	int i = 0x7fff; // Max pos value = 32767
	long l;
	float f;
	// (1) Typical castless conversions:
	l = i;
	f = i;
	// Also works:
	l = static_cast<long>(i);
	f = static_cast<float>(i);
	3: The C in C++ 183
	// (2) Narrowing conversions:
	i = l; // May lose digits
	i = f; // May lose info
	// Says "I know," eliminates warnings:
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i);
	// (3) Forcing a conversion from void* :
	void* vp = &i;
	// Old way produces a dangerous conversion:
	float* fp = (float*)vp;
	// The new way is equally dangerous:
	fp = static_cast<float*>(vp);
	// (4) Implicit type conversions, normally
	// performed by the compiler:
	double d = 0.0;
	int x = d; // Automatic type conversion
	x = static_cast<int>(d); // More explicit
	func(d); // Automatic type conversion
	func(static_cast<int>(d)); // More explicit
} ///:~

/////////////////////////////////////////////////////////////////
//const_cast To cast away const and/or volatile.
//: C03:const_cast.cpp
int main() {
	const int i = 0;
	int* j = (int*)&i; // Deprecated form
	j = const_cast<int*>(&i); // Preferred
	// Can't do simultaneous additional casting:
	//! long* l = const_cast<long*>(&i); // Error
	volatile int k = 0;
	int* u = const_cast<int*>(&k);
} ///:~

////////////////////////////////////////////////////////////////
//reinterpret_cast To cast to a completely different
//meaning. The key is that you’ll
//need to cast back to the original
//type to use it safely. The type you
//cast to is typically used only for
//bit twiddling or some other
//mysterious purpose. This is the
//most dangerous of all the casts.
//: C03:reinterpret_cast.cpp
#include <iostream>
using namespace std;
const int sz = 100;
struct X { int a[sz]; };
void print(X* x) {
	for(int i = 0; i < sz; i++)
		cout << x->a[i] << ' ';
	cout << endl << "--------------------" << endl;
}
int main() {
	X x;
	print(&x);
	int* xp = reinterpret_cast<int*>(&x);
	for(int* i = xp; i < xp + sz; i++)
		*i = 0;
	// Can't use xp as an X* at this point
	// unless you cast it back:
	print(reinterpret_cast<X*>(xp));
	// In this example, you can also just use
	// the original identifier:
	print(&x);
} ///:~

////////////////////////////////////////////////////////////////
//dynamic_cast For type-safe downcasting