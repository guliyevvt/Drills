#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include <algorithm>
#include <iterator>

using namespace std;

int ga[] = { 1,2,4,6,8,16,32,64,128,256 };

vector<int> gv = { 1,2,4,6,8,16,32,64,128,256 };


void f(int arr[], int n) {
	int la[10];

	cout << "la: ";
	for (int i = 0; i < n; i++) {
		la[i] = ga[i];
		cout << la[i] << " ";
	}
	cout << "\n";

	int* laPtr = new int[n];

	for (int i = 0; i < n; i++) {
		laPtr[i] = arr[i];
	}
	cout << "laptr: ";
	for (int i = 0; i < n; i++) {
		cout << laPtr[i] << " ";
	}
	cout << "\n";

	delete laPtr;
}

void f(vector<int> arr) {

	vector<int> lv;

	for (int i = 0; i < arr.size(); i++) {
		lv.push_back(arr[i]);
	}

	cout << "la: ";
	for (int i = 0; i < lv.size(); i++) {
		cout << lv[i] << " ";
	}
	cout << "\n";

	vector<int> lv2(arr);

	cout << "laptr: ";
	for (int i = 0; i < lv2.size(); i++) {
		cout << lv2[i] << " ";
	}
	cout << "\n";

}

int main() {

	f(ga, 10);

	int aa[] = { 1,2,6,24,120,720,5040,40320, 362880,3628800 };

	f(aa, 10);

	f(gv);
	vector<int> vv = { 1,2,6,24,120,720,5040,40320, 362880,3628800 };
	f(vv);
}
