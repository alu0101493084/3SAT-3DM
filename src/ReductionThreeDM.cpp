#include <vector>

#include "../include/ReductionThreeDM.hpp"

ReductionThreeDM::ReductionThreeDM() {
}

ThreeDM ReductionThreeDM::reduce(const ThreeSAT& t_sat) {
    int group_size = 2 * t_sat.get_variable_amount() * t_sat.get_clause_amount();
    ThreeDM t_dm(group_size);
    std::vector<Matching> matchings;

    // Truth setting and fan-out
    for (int star = 0; star < t_sat.get_variable_amount(); ++star) {
        int star_index = star * 2 * t_sat.get_clause_amount();
        for (int c = 0; c < t_sat.get_clause_amount(); ++c) {
            int index = star_index + c * 2;
            
            Matching matching = {index, index/2, index/2}; // Triangulo true
            matchings.push_back(matching);
            if (c == t_sat.get_clause_amount() - 1) {
                matching = {index + 1, index/2, star_index / 2}; // Triangulo false
                matchings.push_back(matching);
            } else {
                matching = {index + 1, index/2, index/2 + 1}; // Triangulo false
                matchings.push_back(matching);
            }
        }
    }

    // Starting indexes of elements for each component
    const int element_st = t_sat.get_variable_amount() * t_sat.get_clause_amount();
    const int element_gc = element_st + t_sat.get_clause_amount();

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
    const int gc_size = t_sat.get_clause_amount() * (t_sat.get_variable_amount() - 1);
    for (int gc = 0; gc < gc_size; gc++) {
        for (int spike = 0; spike < group_size; spike++) {
            Matching m = {spike, element_gc + gc, element_gc + gc};
            matchings.push_back(m);
        }
    }
    t_dm.setMatchings(matchings);  
    return t_dm;
}
