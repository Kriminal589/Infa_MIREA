#include "Math.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Math* math = new Math();
    math->first_operation(5, '%', 4);
    math->second_operation('+', 4);
    math->therd_operation('+', 5);
    return 0;
}
