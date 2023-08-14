#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char *argv[]) {
	int n, i, result;
	cin >> n;
	int arr[n];
	
	double start_time = clock();

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;

	for (i = 3; i < n ; i++) {
		arr[i] = arr[i-1] + arr[i-2];
		result = arr[i];
	}
	
	double end_time = clock();
	cout << result << endl;
	double sp_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC; 
	cout << fixed <<"Spent time:" << sp_time;

	
	return 0;
}