#include "../include/ThreeDM.hpp"

ThreeDM::ThreeDM(int group_size) {
    this->group_size = group_size;
}

std::ostream& operator<<(std::ostream& out, const ThreeDM& t_dm) {
    std::cout << "SETS\n\n";
    std::cout << "W { ";
    for (int i = 0; i < t_dm.group_size - 1; i++) {
        std::cout << t_dm.matchings[i].w << ", ";
    }
    std::cout << t_dm.matchings[t_dm.matchings.size() - 1].w << " }\n\n";
    std::cout << "X { ";
    for (int i = 0; i < t_dm.group_size - 1; i++) {
        std::cout << t_dm.matchings[i].x << ", ";
    }
    std::cout << t_dm.matchings[t_dm.matchings.size() - 1].x << " }\n\n";
    std::cout << "Y { ";
    for (int i = 0; i < t_dm.group_size - 1; i++) {
        std::cout << t_dm.matchings[i].y << ", ";
    }
    std::cout << t_dm.matchings[t_dm.matchings.size() - 1].y << " }\n\n";
    std::cout << "M {\n";
    for (int i = 0; i < t_dm.group_size - 1; i++) {
        std::cout << "(" << t_dm.matchings[i].w << ", " << t_dm.matchings[i].x << ", " << t_dm.matchings[i].y << "),\n";
    }
    std::cout << "(" << t_dm.matchings[t_dm.matchings.size() - 1].w << ", " << t_dm.matchings[t_dm.matchings.size() - 1].x << ", " << t_dm.matchings[t_dm.matchings.size() - 1].y << ")\n}";
}