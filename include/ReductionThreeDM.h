#pragma once

#include "ThreeSAT.h"
#include "ThreeDM.h"

class ReductionThreeDM {
 public:
  ReductionThreeDM() = default;
  ThreeDM reduce(const ThreeSAT& t_sat);
};
