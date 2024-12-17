#pragma once

#include <string>
#include <vector>

struct Literal {
  int variable;
  bool value;
};

struct Clause {
  Literal literals[3];
};

class ThreeSAT {
 public:
  // Method that reads json from file
  ThreeSAT(const std::string& json_file_name); 
  // Getters
  const std::vector<Clause>& getClauses() const { return clauses_; }     
  int getVariableAmount() const { return variable_amount_; }                   
  int getClauseAmount() const { return clauses_.size(); }             
  friend std::ostream& operator<<(std::ostream& out, const ThreeSAT& t_sat);

 private:
  int variable_amount_;            // Variables are integers in [ 0 , variable_amount-1 ]
  std::vector<Clause> clauses_;
};

std::ostream& operator<<(std::ostream& out, const ThreeSAT& t_sat);
