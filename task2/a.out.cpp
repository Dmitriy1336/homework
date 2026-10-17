#include <iostream>

int toInt(const char* s) {
    int res = 0;
    while (*s != '\0') {
        res = res*10 + (*s - '0');
        s++;
    }
    return res;
}

void reverse(int* ptr, int lenArr) {
    while (lenArr > 0) {
        int el1 = *ptr;
        int* ptr1 = ptr;
        int* ptr2 = ptr+(lenArr-1);
        *ptr1 = *ptr2;
        *ptr2 = el1;
        lenArr -= 2;
        ptr+=1;
        if (lenArr <= 1) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) return 1;
    int lenArr = toInt(argv[1]);
    int* arr = new int[lenArr];
    for (int i = 0; i < lenArr; i++) {
        int el;
        std::cin >> el;
        arr[i] = el;
    }
    int k;
    std::cin >> k;
    k = ((k % lenArr) + lenArr) % lenArr;
    int lenArr1 = k;
    int lenArr2 = lenArr-k;
    reverse(arr,lenArr);
    reverse(arr,lenArr1);
    reverse(arr+k,lenArr2);

    for (int i = 0; i < lenArr; i++) {
        std::cout << arr[i] << std::endl;
    }
    for (int i = 0; i < lenArr; i++) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}