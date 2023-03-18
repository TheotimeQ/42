#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

bool is_operator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int evaluate(const std::string& op, const int& a, const int& b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return (0);
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" <<  std::endl;
        return 1;
    }

    std::stack<int> s;
    std::string token;
    std::istringstream iss(argv[1]);
    while (iss >> token) 
    {
        if (!is_operator(token)) {
            if (!(token.length() == 1 && std::isdigit(token[0])))
            {
                std::cerr << "Invalid number: " << token <<  std::endl;
                return 1;
            }
            s.push(token[0] - 48);
            // std::cerr << "Adding :" << s.top() <<  std::endl;
        }
        else {
            if (s.size() < 2) {
                std::cerr << "Invalid expression: not enough operands" <<  std::endl;
                return 1;
            }
            int b = s.top(); 
            s.pop();
            int a = s.top(); 
            s.pop();
            int result = evaluate(token, a, b);
            s.push(result);
            // std::cerr << a << token << b << "=" << s.top() <<  std::endl;
        }
    }

    if (s.size() != 1) {
        std::cerr << "Invalid expression: too many operands" <<  std::endl;
        return 1;
    }

    std::cout << s.top() <<  std::endl;
    return 0;
}
