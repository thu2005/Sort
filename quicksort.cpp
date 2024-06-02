#include <iostream>
using namespace std;

bool ascending(int a, int b) {
	return a <= b;
}

bool descending(int a, int b) {
	return a >= b;
}

int partition(int a[], int n, int left, int right, bool(*compare)(int, int)) {
	int pivot = right;
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (compare(a[j], a[pivot])) { //a[j]<a[pivot] -> swap -> sort tang dan, a[j]>a[pivot] -> swap -> sort giam dan
			i++;
			swap(a[i], a[j]);
		}
	}

	i++; //vi tri dau tien lon hon pivot
	swap(a[pivot], a[i]);
	return i;
}

void quicksort(int a[], int n, int left, int right, bool(*compare)(int, int)) {
	if (left < right) {
		int mid = partition(a, n, left, right, compare);
		quicksort(a, n, left, mid - 1, compare);
		quicksort(a, n, mid + 1, right, compare);
	}
}
int main() {
	int a[8];
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
	quicksort(a, 8, 0, 8 - 1, descending);
	for (int i = 0; i < 8; i++)
		cout << a[i] << " ";
	return 0;
}