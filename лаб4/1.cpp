#include <iostream>

using namespace std;

int task1(int n) {
  
  int a[n], b[n], ans = 0;

  for (int i = 0; i < n; i++) {
    a[i] = 1 + rand() % 100;
  }
  
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] > a[i])
        swap(a[i], a[j]);
    }
  }
  for (int i = 0, j = 0; i < (n + 1) / 2; i++, j += 2) {
    b[j] = a[i];
    ans += a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        swap(a[i], a[j]);
    }
  }
  for (int i = 0, j = 1; i < n / 2; i++, j += 2) {
    b[j] = a[i];
  }
  cout << "Один из возможных вариантов вывода: ";
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl << "Максимальная сумма чека: " << ans << endl;
  return 0;
}

int main()
{
  setlocale(LC_CTYPE, "Russian");
  int n;
  cin >> n;
  task1(n);

}