#include <iostream>

#include "../include/ThreeSAT.hpp"

int main (int argc, char *argv[]) {
    ThreeSAT three_sat("3sat.json");
    std::cout << three_sat << std::endl;
    return 0;
}
