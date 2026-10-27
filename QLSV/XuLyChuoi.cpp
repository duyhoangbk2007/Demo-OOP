#include "XuLyChuoi.h"

int doDaiChuoi(const char* s) {
    if (s == nullptr) {
        return 0;
    }
    int doDai = 0;
    while (s[doDai] != '\0') {
        doDai++;
    }
    return doDai;
}

void saoChepChuoi(char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) {
        return;
    }
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

bool haiChuoiBangNhau(const char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) {
        return s1 == s2;
    }
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return false;
        }
        i++;
    }
    return s1[i] == s2[i];
}
