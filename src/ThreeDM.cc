#include "../include/ThreeDM.h"

ThreeDM::ThreeDM(int group_size) {
  group_size_ = group_size;
}

void ThreeDM::toJson() {
  std::ofstream json_file{"3dm.json", std::ios_base::out};
  json_file << '{' << std::endl;
  json_file << "\t\"size\": " << group_size_ << ',' << std::endl;
  json_file << "\t\"matchings\": [" << std::endl;
  for (size_t matching_number{0}; matching_number < matchings_.size(); ++matching_number) {
    Matching matching = matchings_[matching_number];
    json_file << "\t\t{" << std::endl;
    json_file << "\t\t\t\"w\": " << matching.w << ',' << std::endl;
    json_file << "\t\t\t\"x\": " << matching.x << ',' << std::endl;
    json_file << "\t\t\t\"y\": " << matching.y << std::endl;
    if (matching_number == matchings_.size() - 1) {
      json_file << "\t\t}" << std::endl;
    } else {
      json_file << "\t\t}," << std::endl;
    }
  }
  json_file << "\t]" << std::endl << '}';
}

void ThreeDM::print(const ThreeDM& t_dm) {
  std::cout << "SETS\n\n";
  std::cout << t_dm.matchings_[t_dm.matchings_.size() - 1].y << " }\n\n";
  std::cout << "M {\n";
  for (size_t l = 0; l < (t_dm.matchings_.size() - 1); ++l) {
    std::cout << "(" << t_dm.matchings_[l].w << ", " << t_dm.matchings_[l].x << ", " << t_dm.matchings_[l].y << "),\n";
  }
  std::cout << "(" << t_dm.matchings_[t_dm.matchings_.size() - 1].w << ", " << t_dm.matchings_[t_dm.matchings_.size() - 1].x << ", " << t_dm.matchings_[t_dm.matchings_.size() - 1].y << ")\n}\n";
  std::cout << t_dm.matchings_.size() << std::endl;
}