#include <iostream>

using std::cout, std::endl;


T myMax(T x, T y) {
    return (x > y) ? x : y;
}





int main () {
    cout << myMax<int>(3,7) << endl;

    cout << myMax<double>(3.9, 7.2) << endl ;

    cout << myMax<char>('g', 'e') << endl;

    return 0;

}
