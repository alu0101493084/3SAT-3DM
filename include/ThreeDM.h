#pragma once

#include <vector>
#include <iostream>
#include <fstream>

struct Matching {
  int w;
  int x;
  int y;
};

class ThreeDM {
 public:
  ThreeDM(int group_size);
  void setMatchings(const std::vector<Matching>& matchings_parameter) { matchings_ = matchings_parameter; }
  void toJson();
  void print(const ThreeDM& t_dm);

 private:
  int group_size_;
  std::vector<Matching> matchings_;
};