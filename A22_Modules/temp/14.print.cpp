export module A;   // declares the primary module interface unit for named module 'A'

import <iostream>;
import <string>;
 
// print() will be visible by translations units importing 'A'
export void print(const std::string& message) { std::cout << message << std::endl; }
