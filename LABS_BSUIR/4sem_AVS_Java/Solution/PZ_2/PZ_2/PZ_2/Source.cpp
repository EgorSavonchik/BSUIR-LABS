#include <iostream>
#include <sstream>
#include <bitset>
#include <cmath>
#include <algorithm>

std::string binary_difference(std::string num1_s, std::string num2_s, bool is_print = false) {
    std::string res;
    int carry = 0, tmp;

    std::reverse(num1_s.begin(), num1_s.end());
    std::reverse(num2_s.begin(), num2_s.end());

    for (size_t i = 0; i < num1_s.size(); i++) {
        if (num1_s[i] == '.') {
            res += '.';
            continue;
        }

        tmp = (num1_s[i] - num2_s[i] - carry);

        if (tmp < 0) {
            tmp = std::abs(tmp);
            carry = 1;
            res += (tmp % 2) + 48;
        }
        else {
            res += tmp + 48;
            carry = 0;
        }

        if (is_print)
            std::cout << res << std::endl;
    }

    std::reverse(res.begin(), res.end());

    return res;
}

std::string binary_summarize(std::string num1_s, std::string num2_s, bool is_print = false) {
    std::string res;
    int carry = 0, tmp;

    std::reverse(num1_s.begin(), num1_s.end());
    std::reverse(num2_s.begin(), num2_s.end());

    for (size_t i = 0; i < num1_s.size(); i++) {
        if (num2_s[i] == '.') {
            res += '.';
            continue;
        }

        tmp = (num1_s[i] + num2_s[i] + carry) - 96;
        carry = tmp / 2;
        res += std::to_string(tmp % 2);

        if (is_print)
            std::cout << res << std::endl;
    }

    std::reverse(num1_s.begin(), num1_s.end());
    std::reverse(num2_s.begin(), num2_s.end());

    if (carry) {
        res += '1';
    }

    std::reverse(res.begin(), res.end());

    return res;
}

std::string binary_multiply(std::string num1_s, std::string num2_s, bool is_print = false) {
    std::string res, tmp_res, null_string(num1_s.size() * 2, '0');

    res = null_string;

    if (num1_s[0] == '0' && num2_s[0] == '1')
        std::swap(num1_s, num2_s);

    std::reverse(num1_s.begin(), num1_s.end());
    std::reverse(num2_s.begin(), num2_s.end());

    for (size_t i = 0; i < num2_s.size(); i++) {
        if (num2_s[i] == '0')
            continue;
        tmp_res = null_string;
        for (size_t j = i; j < tmp_res.size(); j++) {
            tmp_res[j] = '0';
        }
        for (size_t j = i; j < i + num1_s.size(); j++) {
            tmp_res[j] = num1_s[j - i];
        }

        std::reverse(res.begin(), res.end());
        std::reverse(tmp_res.begin(), tmp_res.end());
        res = binary_summarize(res, tmp_res);
        std::reverse(res.begin(), res.end());

        if (is_print)
            std::cout << res << std::endl;
    }

    std::reverse(res.begin(), res.end());

    return res;
}

std::string binary_divide(std::string num1_s, std::string M, bool is_print = false) {
    if (M.find("1") == std::string::npos)
        return "divide by zero";
    std::string res, tmp, A, Q, old_a;

    Q = num1_s;

    for (size_t i = 0; i < 8; i++) {
        M = M[0] + M;
    }

    for (size_t i = 0; i < Q.size(); i++)
        A += '0';



    for (size_t i = 0; i < Q.size(); i++) {
        for (size_t j = 0; j < A.size() - 1; j++)
            A[j] = A[j + 1];

        A[A.size() - 1] = Q[0];

        for (size_t j = 0; j < Q.size() - 1; j++)
            Q[j] = Q[j + 1];

        old_a = A;

        if (A[0] == M[0])
            A = binary_difference(A, M);
        else
            A = binary_summarize(A, M);

        if (A[0] == old_a[0]) {
            Q[Q.size() - 1] = '1';
        }
        else {
            Q[Q.size() - 1] = '0';
            A = old_a;
        }

        if (is_print)
            std::cout << std::to_string(i) + ": " << A << ' ' << Q << std::endl;

    }

    return Q;
}

void inc(std::string& num_s) {
    int carry = 1, tmp;

    std::reverse(num_s.begin(), num_s.end());

    for (size_t i = 0; i < num_s.size(); i++) {
        tmp = num_s[i] - 48 + carry;
        num_s[i] = tmp % 2 + 48;
        carry = tmp / 2;
    }

    if (carry == 1) {
        num_s += '1';
    }

std:reverse(num_s.begin(), num_s.end());
}

void dec(std::string& num_s) {
    int carry = 1, tmp;

    std::reverse(num_s.begin(), num_s.end());

    for (auto& x : num_s) {
        tmp = x - 48 - carry;
        if (tmp < 0) {
            carry = 1;
            x = tmp * (-1) % 2 + 48;
        }
        else {
            x = tmp + 48;
            carry = 0;
        }
    }

    std::reverse(num_s.begin(), num_s.end());
}

std::string int_part_to_binary(std::string num_s) {
    std::stringstream cont;
    int num, size;
    std::string res;

    cont << num_s;
    cont >> num;
    size = std::ceil(std::log2(num));

    while (num) {
        res += num % 2 + 48;
        num /= 2;
    }

    std::reverse(res.begin(), res.end());

    return res;
}

std::string complete_fractional(std::string num_s, size_t zero_count) {
    auto pos_it = std::find(num_s.begin(), num_s.end(), '.');
    size_t k;
    std::string zero_str(zero_count, '0');

    num_s += '.' + zero_str;

    return num_s;
}

std::string fractional_to_binary(std::string fract_part_s, size_t digit_count) {
    std::string res;
    std::stringstream cont;
    double fract_part;

    cont << fract_part_s;
    cont >> fract_part;

    for (size_t i = 0; i < digit_count; i++) {
        fract_part *= 2;

        if (fract_part >= 1) {
            res += '1';
            fract_part -= 1;
        }
        else {
            res += '0';
        }
    }

    return res;
}

std::string decimal_to_binary(std::string num_s) {
    std::stringstream tmp_cont;
    double tmp_num;
    tmp_cont << num_s;
    tmp_cont >> tmp_num;
    if (tmp_num == 0)
        num_s = "0";

    if (num_s[0] == '-')
        num_s.erase(0, 1);

    size_t pos = std::distance(num_s.begin(), std::find(num_s.begin(), num_s.end(), '.'));

    if (pos == num_s.size()) {
        std::string res = int_part_to_binary(num_s);
        res = complete_fractional(res, 24 - res.size());
        return res;
    }
    else {
        std::string int_part_s, fract_part_s, res;
        double fract_part;

        int_part_s = num_s.substr(0, pos);
        fract_part_s = num_s.substr(pos);
        res = int_part_to_binary(int_part_s);
        std::stringstream cont;
        res += '.';
        res += fractional_to_binary(fract_part_s, 25 - res.size());

        return res;
    }
}

std::string binary_to_float(std::string bin) {
    int pos = std::distance(bin.begin(), std::find(bin.begin(), bin.end(), '.')), exp;
    std::string exp_s, mant, res;

    if (pos == 1) {
        if (bin[0] == '0') {
            pos -= std::distance(bin.begin(), std::find(bin.begin(), bin.end(), '1'));
            exp = 127 + pos;
            exp_s = std::bitset<8>(exp).to_string();
            pos = std::distance(bin.begin(), std::find(bin.begin(), bin.end(), '1'));
            bin.erase(pos, 1);
            mant = bin.substr(pos - 1);
        }
        else {
            exp = 127;
            exp_s = std::bitset<8>(exp).to_string();
            bin.erase(1, 1);
            mant = bin;
        }
    }
    else if (pos == 0) {
        exp = 127;
        exp -= bin.find('1');
        bin.erase(0, bin.find('1'));
        exp_s = std::bitset<8>(exp).to_string();
        mant = bin;
    }
    else {
        exp = 127 + pos - 1;
        exp_s = std::bitset<8>(exp).to_string();
        bin.erase(pos, 1);
        mant = bin;
    }

    res = "0" + exp_s + mant;

    return res;
}

std::string decimal_to_float(std::string num_s) {
    bool is_neg = 0;
    std::string num_b, res;

    if (num_s[0] == '-') {
        is_neg = 1;
        num_s.erase(0, 1);
    }

    num_b = decimal_to_binary(num_s);
    res = binary_to_float(num_b);
    res[0] = is_neg + 48;

    return res;
}

std::string float_summarize(std::string num1_s, std::string num2_s);

std::string float_difference(std::string num1_s, std::string num2_s) {
    std::string exp1 = num1_s.substr(1, 8), exp2 = num2_s.substr(1, 8),
        mant1 = num1_s.substr(9), mant2 = num2_s.substr(9);
    std::string mant;
    char sign_bit;

    if (num1_s[0] != num2_s[0]) {
        num2_s[0] = (num2_s[0] - 48) ^ 1 + 48;
        return float_summarize(num1_s, num2_s);
    }

    if (num1_s.find('1') == std::string::npos) {
        return num2_s;
    }
    else {
        if (num2_s.find('1') == std::string::npos)
            return num1_s;
    }

    if (num1_s[0] == num2_s[0] && (exp1 + mant1 > exp2 + mant2)) {
        sign_bit = num1_s[0];
    }
    else if (num1_s[0] == num2_s[0] && (exp1 + mant1 < exp2 + mant2)) {
        sign_bit = '1';
    }

    if (exp1 + mant1 < exp2 + mant2) {
        std::swap(exp1, exp2);
        std::swap(mant1, mant2);
    }

    if (exp1 == exp2) {
        mant = binary_difference(mant1, mant2);

        if (mant.find('1') == std::string::npos)
            return std::string(33, '0');

        while (!(mant[0] - 48)) {
            mant.erase(0, 1);
            mant += '0';
            dec(exp1);
        }

        if (mant.find('1') == std::string::npos)
            return std::string(33, '0');

    }
    else {
        if (exp1 < exp2) {
            std::swap(exp1, exp2);
            std::swap(num1_s, num2_s);
            std::swap(mant1, mant2);
        }

        while (exp1 != exp2 && mant2.find('1') != std::string::npos) {
            inc(exp2);
            mant2 = '0' + mant2;
            mant2.erase(mant2.size() - 1, 1);
        }

        if (mant2.find('1') == std::string::npos) {
            return num1_s;
        }
        else {
            mant = binary_difference(mant1, mant2);

            if (mant.find('1') == std::string::npos)
                return std::string(33, '0');

            while (!(mant[0] - 48)) {
                mant.erase(0, 1);
                mant += '0';
                dec(exp1);
            }
        }
    }

    return sign_bit + exp1 + mant;
}

std::string float_summarize(std::string num1_s, std::string num2_s) {
    if (num1_s[0] != num2_s[0]) {
        if (num1_s[0] == '1') {
            std::swap(num1_s, num2_s);
            num2_s[0] = '0';
        }
        else {
            num2_s[0] = '0';
        }
        return float_difference(num1_s, num2_s);
    }

    std::string exp1 = num1_s.substr(1, 8), exp2 = num2_s.substr(1, 8),
        mant1 = num1_s.substr(9), mant2 = num2_s.substr(9);
    std::string mant;

    if (num1_s.find('1') == std::string::npos) {
        return num2_s;
    }
    else {
        if (num2_s.find('1') == std::string::npos)
            return num1_s;
    }

    if (exp1 == exp2) {
        mant = binary_summarize(mant1, mant2);

        if (mant.find('1') == std::string::npos) {
            return std::string(33, '0');
        }

        if (mant.size() > 24) {
            mant.erase(mant.size() - 1, 1);
            inc(exp1);

            if (exp1.size() > 8) {
                std::cout << "perepolnenie poriadka";
                exit(0);
            }
        }
    }
    else {
        if (exp1 < exp2) {
            std::swap(exp1, exp2);
            std::swap(num1_s, num2_s);
            std::swap(mant1, mant2);
        }

        while (exp1 != exp2 && mant2.find('1') != std::string::npos) {
            inc(exp2);
            mant2 = '0' + mant2;
            mant2.erase(mant2.size() - 1, 1);
        }

        if (mant2.find('1') == std::string::npos) {
            return num1_s;
        }
        else {
            mant = binary_summarize(mant1, mant2);

            if (mant.find('1') == std::string::npos)
                return std::string(33, '0');

            if (mant.size() > 24) {
                mant.erase(mant.size() - 1, 1);
                inc(exp1);
                if (exp1.size() > 8) {
                    std::cout << "perepolnenie poriadka";
                    exit(0);
                }
            }
        }
    }

    return num1_s[0] + exp1 + mant;
}

std::string float_multiply(std::string num1_s, std::string num2_s) {
    std::string exp1 = '0' + num1_s.substr(1, 8), exp2 = '0' + num2_s.substr(1, 8),
        mant1 = num1_s.substr(9), mant2 = num2_s.substr(9);
    char sign_bit = (num1_s[0] - 48) ^ (num2_s[0] - 48) + 48;
    std::string mant, exp;
    int pos1 = mant1.rfind('1'), pos2 = mant2.rfind('1');

    mant1.erase(pos1 + 1);
    mant2.erase(pos2 + 1);
    mant1 = std::string(24 - mant1.size(), '0') + mant1;
    mant2 = std::string(24 - mant2.size(), '0') + mant2;
    exp = binary_summarize(exp1, exp2);

    if (exp.size() == 9) {
        exp = binary_difference(exp, std::bitset<9>(127).to_string());
        exp.erase(0, 1);
    }
    else {
        exp = binary_difference(exp, std::bitset<8>(127).to_string());
    }

    mant = binary_multiply(mant1, mant2);
    int pos = mant.find('1'), size1 = mant1.size() - mant1.find('1') - 1, size2 = mant2.size() - mant2.find('1') - 1,
        size = mant.size() - mant.find('1') - 1;

    if (size > size1 + size2) {
        for (size_t i = 0; i < size - size1 - size2; i++)
            inc(exp);
    }
    else if (size < size1 + size2) {
        for (size_t i = 0; i < size1 + size2 - size; i++)
            dec(exp);
    }

    mant.erase(0, pos);

    if (mant.size() <= 23) {
        mant += std::string(24 - mant.size(), '0');
    }
    else {
        mant.erase(24);
    }

    while (mant[0] != '1') {
        dec(exp);
        mant.erase(0, 1);
        mant += '0';
    }

    return sign_bit + exp + mant;
}

std::string float_divide(std::string num1_s, std::string num2_s) {
    std::string exp1 = '0' + num1_s.substr(1, 8), exp2 = '0' + num2_s.substr(1, 8),
        mant1 = num1_s.substr(9), mant2 = num2_s.substr(9);
    std::string exp, mant;
    char sign_bit = (num1_s[0] - 48) ^ (num2_s[0] - 48) + 48;
    int pres = 24;

    exp = binary_summarize(exp1, std::bitset<9>(127).to_string());
    exp = binary_difference(exp, exp2);
    mant1 += std::string(pres, '0');
    mant2 = std::string(pres, '0') + mant2;
    mant = binary_divide(mant1, mant2);
    exp.erase(0, 1);
    int pos = mant.find('1');

    if (pos < mant.size() - 1 - pres) {
        for (size_t i = 0; i < mant.size() - 1 - pres - pos; i++)
            inc(exp);
    }
    else {
        for (size_t i = 0; i < pos - (mant.size() - 1 - pres); i++)
            dec(exp);
    }

    mant.erase(0, pos);

    if (mant.size() > 24)
        mant.erase(24);

    return sign_bit + exp + mant;
}

double float_to_decimal(std::string num_s) {
    std::string exp = num_s.substr(1, 8), mant = num_s.substr(9);
    double res = 1;

    for (int i = 1; i < mant.size() - 1; i++) {
        res += (mant[i] - 48) * std::pow(2.0, 0 - i);
    }

    res *= std::pow(2, (int(std::bitset<8>(exp).to_ulong()) - 127));

    if (num_s[0] - 48)
        res *= -1;

    return res;
}
void print_float(std::string float_s) {
    float_s.erase(9, 1);
    std::cout << float_s;
}

void print_line()
{
    std::cout << "-----------------------------------------------\n";
}

int main()
{
    std::string num1, num2, num1_d, num2_d, sum, diff, mul, div;
    std::cout << "Enter the first number (num1): ";
    std::cin >> num1;
    std::cout << "Enter the second number (num2): ";
    std::cin >> num2;
    print_line();

    std::cout << "num1 in binary: ";
    print_float(decimal_to_float(num1));
    std::cout << "\nnum1 in decimal: " << float_to_decimal(decimal_to_float(num1)) << std::endl;
    
    std::cout << "num2 in binary: ";
    print_float(decimal_to_float(num2));
    std::cout << "\nnum2 in decimal: " << float_to_decimal(decimal_to_float(num2)) << std::endl;
    print_line();

    sum = float_summarize(decimal_to_float(num1), decimal_to_float(num2));

    std::cout << "sum in binary: ";
    print_float(sum);
    std::cout  << "\nsum in decimal: " << float_to_decimal(sum) << std::endl;
    print_line();

    diff = float_difference(decimal_to_float(num1), decimal_to_float(num2));
  
    std::cout << "diff in binary: ";
    print_float(diff);
    std::cout << "\ndiff in decimal: " << float_to_decimal(diff) << std::endl;
    print_line();

    mul = float_multiply(decimal_to_float(num1), decimal_to_float(num2));

    
    std::cout << "mult in binary: ";
    print_float(mul);
    std::cout<< "\nmult in decimal: " << float_to_decimal(mul) << std::endl;
    print_line();

    div = float_divide(decimal_to_float(num1), decimal_to_float(num2));

   
    std::cout << "div in binary: ";
    print_float(div);
    std::cout << "\ndiv in decimal: " << float_to_decimal(div);
}
