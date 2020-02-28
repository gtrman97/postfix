/*--------------------------------------------------------
 * Program to solve any postfix
 * equation that the user may enter.
 --------------------------------------------------------*/

#include <iostream>
#include <stack>

void postFix(std::string);

int main() {

    std::string equation;
    std::cout << "Enter a postfix equation to solve: ";
    std::cin >> equation;
    postFix(equation);

    return 0;
}

void postFix(std::string equation){

    std::stack<char> mathStack;
    int result;

    for(char c : equation) {
        if (std::isdigit(c))
            mathStack.push(c - '0');
        else{
            int operand2 = mathStack.top();
            mathStack.pop();

            int operand1 = mathStack.top();
            mathStack.pop();

            switch(c)
            {
                case '+':
                    result = operand1 + operand2;
                    mathStack.push(result);
                    break;
                case '-':
                    result = operand1 - operand2;
                    mathStack.push(result);
                    break;
                case '*':
                    result = operand1 * operand2;
                    mathStack.push(result);
                    break;
                case '/':
                    result = operand1 / operand2;
                    mathStack.push(result);
                    break;


            }

        }

    }

    std::cout << result << std::endl;

}
