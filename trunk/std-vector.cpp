#include <vector>

using namespace std;

/*initialization*/
//vector<T> tvec(10); //create vector of 10 elements of type T
vector<int> vec0; //empty vector
vector<int> vec1(10, 42); //10 elements init to 42
vector<int> vec3(vec1); //vec3 is a copy of vec1

/*access*/
for(int i = 0; i < vec.size(); ++i){vec[i] = i;}
for(vec<int>::iterator i = vec.begin(); i  != vec.end(); ++i){*i = 42;}
for(auto i = vec.begin(); i  != vec.end(); ++i){*i = 42;}

/*algorithms*/
sort(vec.begin(), vec.end());
T found = find(vec.begin(), vec.end()); //if not found, found = vec.end()
reverse(vec.begin(), vec.end());

/**/