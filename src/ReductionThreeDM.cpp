#include <vector>

#include "../include/ReductionThreeDM.hpp"

ReductionThreeDM::ReductionThreeDM() {
}

ThreeDM ReductionThreeDM::reduce(const ThreeSAT& t_sat) {
    ThreeDM t_dm(2 * t_sat.get_variable_amount() * t_sat.get_clauses().size());
    std::vector<Matching> matchings;

    // Truth setting and fan-out
    // Satisfactory testing
    // Garbage collector

    return t_dm;
}
