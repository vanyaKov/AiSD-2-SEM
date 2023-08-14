#include <iostream>
#include <random>
using namespace std;

int smallestpos(int D[], int startpos, int length ){
	int small = startpos;
	for (int i = startpos; i < length; i++) {
		if (D[i] < D[small]) {
			small = i;
		}
	}
	return small;
}

void choice(int D[], int length){
	for (int i = 0; i < length; i++){
		int small = smallestpos(D, i, length);
		swap(D[i], D[small]);
	}
	return;
}


int main(int argc, char *argv[]) {
	
	int n;
	cin >> n;
	
	int A[n], first = 0, second = 0, third = 0, sum = 0;
	
	for (int i = 0; i < n; i++) {
		A[i] = 1 + rand() % 100;
	}
	
	choice(A, n);
	
	first = A[n-1];
	
	for (int i = n-1; i >= 0; i--) {
		if (A[i] > second && A[i] != first) {
			second = A[i];
			break;
		}
	}
	
	for (int i = n-1; i >= 0; i--) {
		if (A[i] > third && A[i] != second && A[i] != first) {
			third = A[i];
			break;
		}
	}
	
	for (int i = 0; i < n; i++)
		if (A[i] == first || A[i] == second || A[i] == third)
		sum++;
	
	for (int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}
	
	cout << endl;
	
	cout << first << ' ' << second << ' ' << third;
	
	cout << endl;
	
	cout << sum;
	

	
	return 0;
}