#include "../include/ThreeDM.hpp"

ThreeDM::ThreeDM(int group_size) {
    this->group_size = group_size;
}

void ThreeDM::to_json() {
    std::ofstream archivo_json{"3dm.json", std::ios_base::out};
    archivo_json << '{' << std::endl;
    archivo_json << "\t\"size\": " << group_size << ',' << std::endl;
    archivo_json << "\t\"matchings\": [" << std::endl;
    for (size_t m = 0; m < matchings.size(); m++) {
        Matching matching = matchings[m];
        archivo_json << "\t\t{" << std::endl;
        archivo_json << "\t\t\t\"w\": " << matching.w << ',' << std::endl;
        archivo_json << "\t\t\t\"x\": " << matching.x << ',' << std::endl;
        archivo_json << "\t\t\t\"y\": " << matching.y << std::endl;
        if (m == matchings.size() - 1) {
            archivo_json << "\t\t}" << std::endl;
        } else {
            archivo_json << "\t\t}," << std::endl;
        }
    }
    archivo_json << "\t]" << std::endl << '}';
}

void ThreeDM::Print(const ThreeDM& t_dm) {
    std::cout << "SETS\n\n";
    std::cout << t_dm.matchings[t_dm.matchings.size() - 1].y << " }\n\n";
    std::cout << "M {\n";
    for (size_t l = 0; l < (t_dm.matchings.size() - 1); ++l) {
        std::cout << "(" << t_dm.matchings[l].w << ", " << t_dm.matchings[l].x << ", " << t_dm.matchings[l].y << "),\n";
    }
    std::cout << "(" << t_dm.matchings[t_dm.matchings.size() - 1].w << ", " << t_dm.matchings[t_dm.matchings.size() - 1].x << ", " << t_dm.matchings[t_dm.matchings.size() - 1].y << ")\n}\n";
    std::cout << t_dm.matchings.size() << std::endl;
}