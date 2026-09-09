#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // code here
    a = a^b;
    b = a^b;// a^b^b
    a = a^b;//a^a

    cout << a << " " << b;
    return 0;
}