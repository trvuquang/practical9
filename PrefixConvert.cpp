# include "PrefixConvert.h"

// Reference:
// https://www.delftstack.com/howto/cpp/how-to-determine-if-a-string-is-number-cpp/#:~:text=Use%20std%3A%3Aisdigit%20Method%20to%20Determine%20if%20a%20String%20Is%20a%20Number,-The%20first%20version&text=Namely%2C%20pass%20a%20string%20as,none%20is%20found%20returns%20true.
bool isNumber(const string& str){
    return str.find_first_not_of("0123456789") == string::npos;
}

string PrefixConvert::convert(string T[], int str_index){
    n_operations = str_index / 2;
    string optr[n_operations];
    int  oprd[n_operations+1];
    // If there are more than 3 elements and total of elements is odd:
    if (str_index >= 3 && (str_index %2)){
        // test passed, do nothing
    }
    else    
        err = 1;

    // Assign operators
    int optr_index = 0;
    for (int i = n_operations - 1; i >= 0; i--){
        if (T[i] == "+" || T[i] == "-" || T[i] == "*" || T[i] == "/")
            optr[optr_index] = T[i];
        else    
            err = 1;
        // cout << optr[optr_index] << endl;
        optr_index++; 
    }

    // cout << "n_operations: " << n_operations << endl;

    int oprd_index = 0;
    for (int i = n_operations; i < str_index; i++){
        if (isNumber(T[i])){
            oprd[oprd_index] = stoi(T[i]);
            oprd_index++;       
        }
        else
            err = 1;
    }

    for (int i = 0; i < oprd_index; i++){
        if (oprd[i] > 99 || oprd[i] < 0)
            err = 1;
    }
        

    cum_res = oprd[0];
    output = to_string(oprd[0]);
    open_parenthesis = 0;
    for (int i = 0; i < n_operations; i++){
        if (optr[i] == "+"){
            cum_res += oprd[i+1];
            open_parenthesis = 1;
            output.insert(0, 1, '(');
        }
        else if (optr[i] == "-"){
            cum_res -= oprd[i+1];
            open_parenthesis = 1;
            output.insert(0, 1, '(');
        }
        else if (optr[i] == "*"){
            cum_res *= oprd[i+1];
        }
        else if (optr[i] == "/"){
            cum_res /= oprd[i+1];
        }
        
        output.append(" ");
        output.append(optr[i]);
        output.append(" ");
        output.append(to_string(oprd[i+1]));
        
        if (open_parenthesis)
            output.append(")");
        open_parenthesis = 0;
    }
    output.append(" = ");
    output.append(to_string(cum_res));

    if (err)
        return output = "Error";
    else   
        return output;
}