#include <iostream>
#include <random>
#include <cstring>

int randomNumberGen(int a, int b){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 6);
    return distrib(gen);
}

void smallLetters(char *symbols){
    while (*symbols){
        if('A' <= *symbols && *symbols <= 'Z'){
            *symbols += ('a' - 'A');
        }
        symbols++;
    }
}

void largeLetters(char *symbols){
    while (*symbols){
        if('a' <= *symbols && *symbols <= 'z'){
            *symbols -= ('a' - 'A');
        }
        symbols++;
    }
}

void deleteSpecialSymbols(char *symbols){
    while (*symbols){
        if (!( (*symbols >= 'A' && *symbols <= 'Z') ||
               (*symbols >= 'a' && *symbols <= 'z') ||
               (*symbols >= '0' && *symbols <= '9') ||
               *symbols == ' ')) {
            *symbols = ' ';
        }
        symbols++;
    }
}

void deleteNumbers(char *symbols){
    while (*symbols){
        if (*symbols >= '0' && *symbols <= '9') {
            *symbols = ' ';
        }
        symbols++;
    }
}

int textLength(char *symbols){
    int length = 0;
    while(*symbols){
        length++;
        symbols++;
    }
    return length;
}

int main() {
    char original[] = "12345 Those ARE words!!!!! And THESE are SYMBOLS: #$%+-,.!!!!!";

    char withNoSymbols[256];
    char withNoNumbers[256];
    strcpy(withNoSymbols, original);
    strcpy(withNoNumbers, original);

    printf("Normal string:\t%s\n", original);

    smallLetters(withNoSymbols);
    printf("Small Letters:\t%s\n", withNoSymbols);

    largeLetters(withNoSymbols);
    printf("Large letters:\t%s\n", withNoSymbols);

    smallLetters(withNoSymbols);

    deleteSpecialSymbols(withNoSymbols);
    printf("No symbols:\t%s\n", withNoSymbols);

    smallLetters(withNoNumbers);
    deleteNumbers(withNoNumbers);
    printf("No numbers:\t%s\n", withNoNumbers);

    printf("Size: %d\n", textLength(withNoNumbers));

    return 0;
}
