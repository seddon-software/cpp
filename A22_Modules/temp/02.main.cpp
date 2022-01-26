/* 
 *  We have one module named "speech".
 *  "speech" has two partitions: "english" and "spanish"
 */
// https://vector-of-bool.github.io/2019/03/10/modules-1.html
// https://vector-of-bool.github.io/2019/03/31/modules-2.html
// https://vector-of-bool.github.io/2019/10/07/modules-3.html

import speech;

import <iostream>;
import <stdlib.h>;
import <cstdlib>;

using namespace std;

int main() {
    srand(time(0));
    if (rand() % 2) {
        cout << get_phrase_en() << '\n';
    } else {
        cout << get_phrase_es() << '\n';
    }
}
