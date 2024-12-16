#pragma once

#include <vector>
#include <iostream>

struct Matching {
    int w;
    int x;
    int y;
};

class ThreeDM {
 public:
    ThreeDM(int group_size);
    friend std::ostream& operator<<(std::ostream& out, const ThreeDM& t_dm);

 private:
    int group_size;
    std::vector<Matching> matchings;
};
