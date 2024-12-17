#include <iostream>

#include "../include/ThreeSAT.h"
#include "../include/ThreeDM.h"
#include "../include/ReductionThreeDM.h"

int main (int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Please specify the file with the 3-sat json\n";
    return 1;
  }

  ReductionThreeDM problem_reduction;
  ThreeSAT three_sat(argv[1]);
  ThreeDM three_dm{problem_reduction.reduce(three_sat)};
  three_dm.toJson();
  return 0;
}
