///standard string class takes care of memory allocation

#include <string>   // for std::string and std::getline
#include <iostream> // for std::cin and std::cout
 
int main() {
  std::string name;
  std::cout << "Please enter your full name: ";
  std::getline(std::cin, name);
  std::cout << "Hello " << name << '\n';
  return 0;
}

//////////////////////////////////////////////////////////
///smart pointers from std e boost

#include <memory> // for std::auto_ptr
#include <iostream>
 
class Simple {
public:
    std::auto_ptr<int> theInt;
 
    Simple() : theInt(new int()) {
        *theInt = 3; //get object like normal pointer
    }
    int f() {return 42;}   
    // when this class is destroyed, theInt will
    // automatically be freed
};
 
int main() {
    std::auto_ptr<Simple> simple(new Simple());
    // note that the following won't work:
    // std::auto_ptr<Simple> simple = new Simple();
    // as auto_ptr can only be constructed with new values
    // access member functions like normal pointers
    std::cout << simple->f(); 
    // the Simple object is freed when simple goes out of scope
    return 0;
}


/////////////////////////////////////////////////////////
//ownership transference of std::auto
#include <memory>
#include <iostream>
int main() {
    std::auto_ptr<int> a(new int(3));
    // a.get() returns the raw pointer of a
    std::cout << "a loc: " << a.get() << '\n';
    std::cout << "a val: " << *a << '\n';
 
    std::auto_ptr<int> b;
 
    b = a; // now b points to the int, a is null
 
    std::cout << "b loc: " << b.get() << '\n';
    std::cout << "b val: " << *b << '\n';
    std::cout << "a loc: " << a.get() << '\n'; 
 
    return 0;
}

//////////////////////////////////////////////////////////
//Pointer				Usage situation	Performance cost	Transfer of ownership	Sharing objects	Works with	Other
//std::auto_ptr			An object can only be owned by one auto_ptr at a given time, this owner may be changed though	nil	Yes	No	Single instance	Doesn't work with standard containers (std::vector etc.)
//boost::scoped_ptr		An object is assigned to a scoped_ptr, it can never be assigned to another pointer	Nil	No	No	Single instance	If used as a member of a class, must be assigned in the constructor. Also, doesn't work with standard containers (std::vector etc.)
//boost::shared_ptr		Many shared_ptrs may point to a single object, when all go out of scope, the object is destroyed	Yes, uses reference counting	Yes	Yes	Single instance	Works with standard containers
//boost::weak_ptr		used with shared_ptrs to break possible cycles, which may result in memory leaks. To use, must be converted into a shared_ptr	same as shared_ptr	Yes	Yes	Single instance	Only ever used in conjunction with shared_ptrs
//boost::scoped_array	same as scoped_ptr, but works with arrays	Nil	No	No	Array of instances	See scoped_ptr
//boost::shared_array	Same as shared_ptr, but works with arrays	Yes, uses reference counting	Yes	Yes	Array of instances	See shared_ptr
//boost::intrusive_ptr	Used to create custom smart pointers for objects that have their own reference count	Depends on implementation	Yes	yes	Single Instance	In most cases, shared_ptr should be used instead of this


///////////////////////////////////////////////////////////
//STL memory management comparision 
struct Foo { int i; };

// Creates 10 Foo objects in a continuous memory block on the heap. e.g. think of "new Foo[10]"
// don't call any delete on f1 or its members! It's handled everything by vector.
vector<Foo> f1(10);

// Creates 10 uninitialized pointers to Foo in a continuous memory block on the heap. You have
// to fill them before using! Use this for "heavy objects", e.g. when copying Foo is expensive
vector<Foo*> f2(10);

// Fill the previously uninitialized Foo pointers with 10 Foo objects,
// also from the heap but spread around somewhere in memory (non-continous)
for(auto i = f2.begin(); i != f2.end(); ++i) *i = new Foo;

// You have to delete the created Foo objects!
for(auto i = f2.begin(); i != f2.end(); ++i) delete *i;

// Create 10 Foo objects on the stack. there is no way to create them on the stack using vector!
// Of course, do not even think about calling delete on f3 or it's objects!
Foo f3[10];

// Old way, used in pre-vector times. Don't use this without a reason today. Use f1-way instead.
Foo* f4 = new Foo[10];

// You have to delete f4 itself (but not the objects it points to). You have to use the almost unknown delete[] for this!
delete [] f4;

// Using smart pointers to not have to worry about deletion. This is similar to f2, except you 
// must not delete the pointers yourself.
// Use this for "heavy Foo" objects, e.g. when copying/constructing Foo is expensive,
// but when you still want value-semantic of Foo (i.e. no ownership of the objects)
vector<std::tr1::shared_ptr<Foo>> f5(10);

// You still have to allocate Foo objects (but don't delete them)
// shared_ptr does not have an implicit conversion constructor..
for(auto i = f2.begin(); i != f2.end(); ++i) *i = std::tr1::shared_ptr<Foo>(new Foo);
