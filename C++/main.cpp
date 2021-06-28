#include <iostream>
#include <sstream>
#include <vector>

const std::string input_nums = "1 2 3 4 5 6 7 8 9";

// In all generated expressions are formated with  A denoting concatonation, B denoting sum and C denoting subtraction
// all functions accepting string expr use this formatting

int eval(std::string expr)
{
    std::string::iterator iter = expr.begin();
    int number = 0, result = 0;
    bool add_or_sub = 1;
    auto numberAdd = [&add_or_sub, &number, &result] {
        if (add_or_sub)
            result += number;
        else
            result -= number;
        number = 0;
    };
    for(auto iter : expr)
    {
        switch (iter)
        {
        case 'B':
            numberAdd();
            add_or_sub = 1;
            break;
        case 'C':
            numberAdd();
            add_or_sub = 0;
            break;
        case 'A':
            number *= 10;
            break;
        default:
            number += iter - '0';
            break;
        }
    }
    numberAdd();
    return result;
}

void print_expr(std::string expr)
{
    for(auto iter : expr)
    {
        switch (iter)
        {
        case 'A':
            break;
        case 'B':
            std::cout << '+';
            break;
        case 'C':
            std::cout << '-';
            break;
        default:
            std::cout << iter;
            break;
        }
    }
}

void wierd_combi(std::string numbers, int stage = 0)
{
    if (stage == 8)
    {
        if (eval(numbers) == 100)
        {
            print_expr(numbers);
            std::cout << '=' << eval(numbers) << std::endl;
        }
        return;
    }
    else
    {
        for (char state = 'A'; state <= 'C'; state++)
        {
            numbers[2 * stage + 1] = state;
            wierd_combi(numbers, stage + 1);
        }
    }
    return;
}

int main()
{
    wierd_combi(input_nums);
}