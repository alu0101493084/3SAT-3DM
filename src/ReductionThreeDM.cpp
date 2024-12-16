#include <vector>

#include "../include/ReductionThreeDM.hpp"

ReductionThreeDM::ReductionThreeDM() {
}

ThreeDM ReductionThreeDM::reduce(const ThreeSAT& t_sat) {
    int group_size = 2 * t_sat.get_variable_amount() * t_sat.get_clause_amount();
    ThreeDM t_dm(group_size);
    std::vector<Matching> matchings;

    // Starting indexes of elements for each component
    const int element_st = t_sat.get_variable_amount() * t_sat.get_clause_amount();
    const int element_gc = element_st + t_sat.get_clause_amount();

    // Truth setting and fan-out
    int a_index = 0;
    int b_index = 0;
    for (int star = 0; star < t_sat.get_variable_amount(); star++) {
        for (int spike = 0; spike < 2 * t_sat.get_clause_amount(); spike++) {
            
        }
    }

    // Satisfactory testing
    for (int c = 0; c < t_sat.get_clause_amount(); c++) {
        Clause clause = t_sat.get_clauses()[c];
        for (Literal l : clause.literals) {
            int star_index = l.variable * 2 * t_sat.get_clause_amount();
            int spike_index = star_index + c*2 + !l.value;
            Matching m = {spike_index, element_st + c, element_st + c};
            matchings.push_back(m);
        }
    }

    // Garbage collector
    const int gc_size = 2 * t_sat.get_clause_amount() * (t_sat.get_variable_amount() - 1);
    for (int gc = 0; gc < gc_size; gc++) {
        for (int spike = 0; spike < group_size; spike++) {
            Matching m = {spike, element_gc + gc, element_gc + gc};
            matchings.push_back(m);
        }
    }

    return t_dm;
}
