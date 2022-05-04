#include<iostream>
#include<list>
#include<vector>

using namespace std;

template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2) {

	for (Iter1 f = f1; f != e1; f++) {
		f2.push_back(*f);
	}
	return f2;
}


int main() {

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> llist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


	int arr2[10];
	for (int i = 0; i < 10; i++) {
		arr2[i] = arr[i];
	}

	vector<int> vec2(vec);
	list<int> llist2(llist);
	std::vector<int>::iterator it = find(vec2.begin(), vec2.end(), 3);



	cout << "find 3 at " << it - vec2.begin() << "\n";


	vector<int> v3 = copy2(vec2.begin(), vec2.end(), v3);
	for (auto n : v3) {
		cout << n << " ";
	}
	cout << "\n";



}
