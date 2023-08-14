#include <iostream>
#include <random>
#include <stdlib.h>
#include <ctime>

using namespace std;

int n;


void buble(int B[], int list_lenght){
	
	while (list_lenght--) {
		bool swapped = false;
		for (int i = 0; i < list_lenght; i++) {
			if (B[i] > B[i+1]) {
				swap(B[i], B[i+1]);
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
	}
	cout << endl;
	
}

void paste(int C[], int list_length){
	for (int i = 1; i < list_length; i++) {
		int j = i - 1 ;
		while (j >= 0 && C[j] > C[j+1]) {
			swap(C[j], C[j+1] );
			j--;
		}
	}
}

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
	for (int i = 0; i < length; i++) {
		int small = smallestpos(D, i, length);
		swap(D[i], D[small]);
	}
	return;
}

int quick_half(int E[], int start ,int lengh){
	int i = start;
	while (i < lengh) {
		if (E[i] > E[lengh] && i == lengh-1) {
			swap(E[i], E[lengh]);
			lengh--;
		}
		else if (E[i] > E[lengh]) {
			swap(E[lengh-1], E[lengh]);
			swap(E[i], E[lengh]);
			lengh--;
		}
		else i++;
			
	}
	return lengh;
}

void quick(int E[], int start, int end){
	
	if(start < end)
		{
			int length = quick_half(E, start, end);
			
			quick(E, start, length - 1);
			quick(E, length + 1, end);
		}
	
}

int main(int argc, char *argv[]) {
	srand(1);
	cin >> n;
	int A[n], B[n], C[n], D[n], E[n];
	for (int i = 0; i < n; i++) {
		A[i] = 1 + rand() % (n-1);
	}
	
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	for (int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}

	cout << endl;
	
	cout << "buble:"<< endl;
	double start = clock();
	buble(B, n);
	double end = clock();
	for (int i = 0; i < n; i++) {
		cout << B[i] << ' ';
	}
	cout << endl;
	cout << "Spent time: " << fixed << (double)(end - start)/CLOCKS_PER_SEC; 
	cout << endl;
	
	cout << "Shell:" << endl; 
	double start2 = clock();
	paste(C, n);
	double end2 = clock();
	for (int i = 0; i < n; i++) {
		cout << C[i] << ' ';
	}
	cout << endl;
	cout << "Spent time: " << fixed << (double)(end2 - start2)/CLOCKS_PER_SEC;
	cout << endl;
	
	cout << "choice:" << endl;
	double start3 = clock();
	choice(D, n);
	double end3 = clock();
	for (int i = 0; i < n; i++) {
		cout << D[i] << ' ';
	}
	cout << endl;
	cout << "Spent time: " << fixed << (double)(end3 - start3)/CLOCKS_PER_SEC;
	cout << endl;

	cout << "quick:" << endl;
	double start4 = clock();
	quick(E, 0, n);
	double end4 = clock();
	for (int i = 0; i < n; i++) {
		cout << E[i] << ' ';
	}
	cout << endl;
	cout << "Spent time: " << fixed << (double)(end4 - start4)/CLOCKS_PER_SEC;

	
	
}

