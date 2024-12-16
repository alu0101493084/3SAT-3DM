#include <vector>

#include "../include/ReductionThreeDM.hpp"

ReductionThreeDM::ReductionThreeDM() {
}

ThreeDM ReductionThreeDM::reduce(const ThreeSAT& t_sat) {
    ThreeDM t_dm(2 * t_sat.get_variable_amount() * t_sat.get_clauses().size());
    std::vector<Matching> matchings;

    // Starting indexes of elements for each component
    int element_st = t_sat.get_variable_amount() * t_sat.get_clause_amount();
    int element_gc = element_st + t_sat.get_clause_amount();

    // Truth setting and fan-out
    for (int star = 0; star < t_sat.get_variable_amount(); star++) {
        for (int spike = 0; spike < 2 * t_sat.get_clause_amount(); spike++) {
        }
    }

    // Satisfactory testing

    // Garbage collector

    return t_dm;
}
