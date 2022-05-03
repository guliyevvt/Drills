#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include <algorithm>
#include <iterator>

using namespace std;

ostream& print_array10(ostream& os, int* a) {

	for (int i = 0; i < 10; i++) {
		os << a[i] << " ";
	}
	os << "\n";

	return os;
}

ostream& print_array(ostream& os, int* a, int n) {
	for (int i = 0; i < n; i++) {
		os << a[i] << " ";
	}
	os << "\n";

	return os;
}

int main() {

	int* arr = new int[10];

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	int* arr2 = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };
	int* arr3 = new int[11]{ 1,2,3,4,5,6,7,8,9,10,11 };

	print_array10(cout, arr2);

	int* arr4 = new int[20]{ 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
	print_array(cout, arr4, 20);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

}
