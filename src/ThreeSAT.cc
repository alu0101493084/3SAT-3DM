#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "../include/json.h"
#include "../include/ThreeSAT.h"

ThreeSAT::ThreeSAT(const std::string& json_file_name) {
  std::ifstream input_stream(json_file_name, std::ifstream::binary);
  if (input_stream.bad()) {
    printf("File %s could not be opened\n", json_file_name.c_str());
    return;
  }
  Json::Value json;
  input_stream >> json;

  variable_amount_ = json["numV"].asInt();
  clauses_.resize(json["numC"].asInt());
  Json::Value json_clauses = json["clauses"];
  // read clauses
  for (unsigned int c = 0; c < json_clauses.size(); c++) {
    const std::vector<std::string>& var_names = json_clauses[c].getMemberNames();
    // set literal values
    for (int l = 0; l < 3; l++) {
      clauses_[c].literals[l].variable = std::stoi(var_names[l]);
      clauses_[c].literals[l].value = !json_clauses[c][var_names[l]].asInt();
    }
  }
}

std::ostream& operator<<(std::ostream& out, const ThreeSAT& t_sat) {
  out << "Variable amount: " << t_sat.variable_amount_;
  for (Clause c : t_sat.clauses_) {
    out << "\n{";
    for (Literal l : c.literals) {
      out << ' ';
      if (!l.value) out << '-';
      out << l.variable << ' ';
    }
    out << '}';
  }
  return out;
}
