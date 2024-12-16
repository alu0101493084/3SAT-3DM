#include <iostream>

#include "../include/ThreeSAT.hpp"
#include "../include/ThreeDM.hpp"
#include "../include/ReductionThreeDM.hpp"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please specify the file with the 3-sat json\n";
        return 1;
    }

    ReductionThreeDM problem_reduction;
    ThreeSAT three_sat(argv[1]);
    ThreeDM three_dm = problem_reduction.reduce(three_sat);
    three_dm.to_json();
    return 0;
}
