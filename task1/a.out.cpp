#include <iostream>

void parse(const char* s, int& sign, const char*& intStart, int& intLen,
const char*& fracStart, int& fracLen) {
    intLen = 0;
    fracLen = 0;
    fracStart = nullptr;
    if (*s == '+') {
        sign = 1;
        intStart = ++s;
    } else if (*s == '-') {
        sign = -1;
        intStart = ++s;
    } else {
        sign = 1;
        intStart = s;
    }
    while (*s != '.' && *s != '\0') {
        intLen+=1;
        s++;
    }
    if (*s != '\0') {
        fracStart = ++s;
        while (*s != '\0') {
            fracLen+=1;
            s++;
        }
    }
           
}

int compareAbs(const char* intA, int intLenA, const char* fracA, int fraclenA,
    const char* intB, int intLenB, const char* fracB, int fraclenB) {
    if (intLenA > intLenB) {
        return 1;
    } else if (intLenA < intLenB) {
        return -1;
    } else {
        while (intLenA > 0 && intLenB > 0) {
        if (*intA == *intB) {
            intLenA--, intLenB--;
            intA++, intB++;
        } else if (*intA > *intB) {
            return 1;
        } else if (*intA < *intB) {
            return -1;
        }
    }
    while (fraclenA > 0 && fraclenB > 0) {
    if (*fracA == *fracB) {
        fraclenA--, fraclenB--;
        fracA++, fracB++;
    } else if (*fracA > *fracB) {
        return 1;
    } else if (*fracA < *fracB) {
        return -1;
    }
    }
    if (fraclenA > fraclenB) {
        return 1;
    } else if (fraclenB > fraclenA) {
        return -1;
    }    
    return 0;
    } 
}

int main(int argc, char* argv[]) {
    if (argc != 3) return 1;
    const char* numA = argv[1];
    const char* numB = argv[2];

    
    int signA = 0, intLenA = 0, fracLenA = 0;
    const char* intStartA = nullptr;
    const char* fracStartA = nullptr;

    int signB = 0, intLenB = 0, fracLenB = 0;
    const char* intStartB = nullptr;
    const char* fracStartB = nullptr;


    parse(numA, signA, intStartA, intLenA, fracStartA, fracLenA);
    parse(numB, signB, intStartB, intLenB, fracStartB, fracLenB);

    if (signA < signB) {
        std::cout << "less" << std::endl;
    } else if (signA > signB) {
        std::cout << "greater" << std::endl;
    } else {
        int res = compareAbs(intStartA, intLenA, fracStartA, fracLenA,
            intStartB, intLenB, fracStartB, fracLenB);
        if (signA == -1) {
            res = -res;
        }
        if (res == 1) {
            std::cout << "greater" << std::endl;
        } else if (res == -1) {
            std::cout << "less" << std::endl;
        } else {
            std::cout << "equal" << std::endl;
        }
    }
}