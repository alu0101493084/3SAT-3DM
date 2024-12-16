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
            }
            matching = {index + 1, index/2, index/2 + 1}; // Triangulo false
            matchings.push_back(matching);
        }
    }

    /*
    // Truth Setting: Crear estrellas para cada variable
    for (int var = 0; var < t_sat.get_variable_amount(); var++) {
        int start_index = var * 2 * t_sat.get_clause_amount();

        // Para cada clausula, creamos los picos (spikes) y conexiones internas
        for (int clause = 0; clause < t_sat.get_clause_amount(); clause++) {
            int true_path = start_index + clause * 2;       // Camino True
                            
            int false_path = start_index + clause * 2 + 1;  // Camino False

            // Crear tripletas que conectan los nodos internos ciclicamente
            matchings.push_back({true_path, true_path + 1, false_path});  // Ejemplo conexion True
            matchings.push_back({false_path, true_path, false_path + 1});  // Ejemplo conexion False
        }
    }
    
    */

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
    const int gc_size = 2 * t_sat.get_clause_amount() * (t_sat.get_variable_amount() - 1);
    for (int gc = 0; gc < gc_size; gc++) {
        for (int spike = 0; spike < group_size; spike++) {
            Matching m = {spike, element_gc + gc, element_gc + gc};
            matchings.push_back(m);
        }
    }

    return t_dm;
}
