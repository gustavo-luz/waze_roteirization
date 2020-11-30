#include <iostream>
#include <vector>

using namespace std;

// Change cin terminator from here
const int cinTerminator = 3;

int main() {

    int num;
    std::vector<int> v;

    cout << "Enter numbers: ";

    //insert number into vector from cin
    while ((cin >> num) && num != cinTerminator) {
        v.push_back(num);
    }

    cout << "Elements into vector: " << endl;
    // print vector
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
