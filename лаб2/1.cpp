#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	
	cin >> n;
	
	int arr[n];
	
	for (int i = 1; i < n+1; i++)
		arr[i] = i;
	
	bool flag = false;
	
	int mid;
	int left = 1, right = n;
	
	string l1;
	
	while (flag != true && left <= right) {
		
		mid = (left + right)/2;
		cout << arr[mid] << endl;
		cin >> l1;
		
		if (l1 == "угадал")
			flag = true;
		
		if (l1 == "много") 
			right = mid - 1; 
		
		if(l1 == "мало")
			left = mid + 1;
		
	}
	
	cout << "Ваше число:" << mid;
	
}