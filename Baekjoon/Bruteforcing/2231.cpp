#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i < N; i++) {
        int num = i;
        int sum = num;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum == N) {
            answer = i;
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
