#include <iostream>
int toInt(const char* s) {
    int res = 0;
    while (*s != '\0') {
        res = res*10 + (*s - '0');
        s++;
    }
    return res;
}

void create(double* ptr1, double* ptr2, int lenArr) {
    std::cout.precision(10);
    double res = 0;
    for (int i = 0; i < lenArr; i++) {
        res += (*ptr1 * *ptr2);
        ptr1++, ptr2++;
    }
    std::cout << res << std::endl;

}
int main(int argc, char* argv[]) {
    if (argc != 2) return 1;
    int lenArr = toInt(argv[1]);

    double* arr1 = new double[lenArr];
    double* arr2 = new double[lenArr];

    for (int i = 0; i < lenArr; i++) {
        double el;
        std::cin >> el;
        arr1[i] = el;
    }
    for (int i = 0; i < lenArr; i++) {
        double el;
        std::cin >> el;
        arr2[i] = el;
    }
    create(arr1, arr2, lenArr);
    delete[] arr1;
    delete[] arr2;
}