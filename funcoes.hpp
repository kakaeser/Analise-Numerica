#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

void clearScreen() {
   #ifdef _WIN32
       system("cls"); // Para Windows
   #else
       std::cout << "\033[2J\033[H"; // Para Linux/MacOS
   #endif
   }

