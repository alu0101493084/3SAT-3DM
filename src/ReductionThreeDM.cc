#include <vector>

#include "../include/ReductionThreeDM.h"

ThreeDM ReductionThreeDM::reduce(const ThreeSAT& t_sat) {
  int group_size{2 * t_sat.getVariableAmount() * t_sat.getClauseAmount()};
  ThreeDM t_dm(group_size);
  std::vector<Matching> matchings;

  // Truth setting and fan-out
  for (int star{0}; star < t_sat.getVariableAmount(); ++star) {
    int star_index{star * 2 * t_sat.getClauseAmount()};
    for (int clausule_number{0}; clausule_number < t_sat.getClauseAmount(); ++clausule_number) {
      int index{star_index + clausule_number * 2};
      
      Matching matching = {index, index / 2, index / 2}; // True triangle
      matchings.push_back(matching);
      if (clausule_number == t_sat.getClauseAmount() - 1) {
        matching = {index + 1, index / 2, star_index / 2}; // False triangle
        matchings.push_back(matching);
      } else {
        matching = {index + 1, index / 2, index / 2 + 1}; // False triangle
        matchings.push_back(matching);
      }
    }
  }

  // Starting indexes of elements for each component
  const int element_st{t_sat.getVariableAmount() * t_sat.getClauseAmount()};
  const int element_gc{element_st + t_sat.getClauseAmount()};

  // Satisfaction testing
  for (int clausule_number{0}; clausule_number < t_sat.getClauseAmount(); ++clausule_number) {
    Clause clause{t_sat.getClauses()[clausule_number]};
    for (Literal literal : clause.literals) {
      int star_index{literal.variable * 2 * t_sat.getClauseAmount()};
      int spike_index{star_index + clausule_number * 2 + !literal.value};
      Matching matching = {spike_index, element_st + clausule_number, element_st + clausule_number};
      matchings.push_back(matching);
    }
  }

  // Garbage collector
  const int gc_size{t_sat.getClauseAmount() * (t_sat.getVariableAmount() - 1)};
  for (int gc{0}; gc < gc_size; ++gc) {
    for (int spike{0}; spike < group_size; ++spike) {
      Matching matching = {spike, element_gc + gc, element_gc + gc};
      matchings.push_back(matching);
    }
  }
  t_dm.setMatchings(matchings);  
  return t_dm;
}
