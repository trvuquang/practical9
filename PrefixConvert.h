# ifndef PREFIXCONVERT_H
# define PREFIXCONVERT_H

# include <array>
# include <string>
# include <iostream>

using namespace std;

class PrefixConvert {
    public:
        string convert (string input[], int size);
    private:
        bool err;
        int n_operations;
        int cum_res;
        string output;
        bool open_parenthesis;
        

};

# endif