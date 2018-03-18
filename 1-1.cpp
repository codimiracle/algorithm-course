#include <iostream>

using namespace std;

int n;
int count[10];

void count_num(int n);

int main()
{
    while (cin >> n) {
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            count_num(i);
        }
        for (int i = 0; i < 10; i++)
            cout << i << ":" << count[i] << " ";
        cout << endl;
    }
    return 0;
}

void count_num(int n) {
    int low;
    while (n != 0) {
        low = n % 10;
        count[low]++;
        n /= 10;
    }
}
