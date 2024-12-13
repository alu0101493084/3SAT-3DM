#include <string>
#include <vector>

struct Literal {
    int variable;
    bool negated;
};

struct Clausule {
    Literal literals[3];
};

class ThreeSAT {
public:
    // Read json from file
    ThreeSAT(const std::string& json_file_name) {
    }

    ~ThreeSAT() {
    }

private:
    int variable_amount; // Variables are integers in [ 0 , variable_amount-1 ]
    std::vector<Clausule> clausules;
};
