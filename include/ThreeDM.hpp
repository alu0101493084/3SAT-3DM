#include <vector>
struct Matching {
    int w;
    int x;
    int y;
};

class ThreeDM {
public:
    ThreeDM(int group_size);

private:
    int group_size;
    std::vector<Matching> matchings;
};
