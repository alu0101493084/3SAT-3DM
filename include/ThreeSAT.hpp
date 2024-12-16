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
    ThreeSAT(const std::string& json_file_name);        // Read json from file
    const std::vector<Clause>& get_clauses() const;     // Get clauses

    int get_variable_amount() const;                    // Get amount of variables
    int get_clause_amount() const;                      // Get amount of clauses

    friend std::ostream& operator<<(std::ostream& out, const ThreeSAT& t_sat);

 private:
    int variable_amount;            // Variables are integers in [ 0 , variable_amount-1 ]
    std::vector<Clause> clauses;
};