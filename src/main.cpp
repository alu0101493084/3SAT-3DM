#include <iostream>

#include "../include/ThreeSAT.hpp"
#include "../include/ThreeDM.hpp"
#include "../include/ReductionThreeDM.hpp"

int main (int argc, char *argv[]) {
    ReductionThreeDM problem_reduction;
    ThreeSAT three_sat("3sat.json");
    ThreeDM three_dm(2);
    problem_reduction.reduce(three_sat);
    std::cout << three_sat << std::endl;
    return 0;
}
