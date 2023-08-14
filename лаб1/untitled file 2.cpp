#include <iostream>
#include <ctime>
using namespace std;
int f(int n)
{
	if (n==1 || n==2) 
		return 1;
	if (n==0) 
		return 0;
	return f(n-1)+f(n-2);
}
int main()
{
	int n;
	cin >> n;
	double start_time = clock();
	cout<<f(n-1)<<endl;
	double end_time = clock();
	
	float sp_time = (double)(end_time - start_time)/ CLOCKS_PER_SEC; 
	cout << fixed <<"Spent time:" << sp_time;
	return 0;
}