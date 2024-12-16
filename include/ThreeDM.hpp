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
    void setMatchings(const std::vector<Matching>& matchings_parameter) { matchings = matchings_parameter; }
    void to_json();
    void Print(const ThreeDM& t_dm);

 private:
    int group_size;
    std::vector<Matching> matchings;
};