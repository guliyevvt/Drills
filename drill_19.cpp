#include<iostream>
#include <vector>
using namespace std;

template<typename T>
struct S {
private:
	T val;

public:
	S(T t) : val(t) {}
	T get();
	void set(T v);

	S<T> operator=(const T& t);
};


template<typename T>
S<T> S<T>::operator=(const T& t) {
	this->val = t;
	return *this;
}

template<typename T>
T S<T>::get() {
	return val;
}

template<typename T>
void S<T>::set(T v) {
	val = v;
}



int main() {

	S<int> mInt(2);
	S<char> mChar('c');
	S<double> mDouble(2.3);
	S<string> mString("hello");
	S<vector<int>> mVector(vector<int>(3));

	mInt = 5;
	mChar.set('t');

	cout << mInt.get() << "\n";
	cout << mChar.get() << "\n";
	cout << mDouble.get() << "\n";
	cout << mVector.get().size() << "\n";

}
