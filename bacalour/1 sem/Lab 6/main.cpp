#include <iostream>
#include <cstring>
using namespace std;

// Свои проверки символов (вместо <cctype>)
bool myIsDigit(char c) {
    return c >= '0' && c <= '9';
}

bool myIsAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool myIsAlnum(char c) {
    return myIsAlpha(c) || myIsDigit(c);
}

// Слово состоит только из цифр?
bool isAllDigits(const char* word, int len) {
    if (len == 0) return false;
    for (int i = 0; i < len; i++)
        if (!myIsDigit(word[i])) return false;
    return true;
}

// Допустимый символ идентификатора
bool isValidIdentChar(char c) {
    return myIsAlnum(c) || c == '_';
}

int main() {
    char s[256];
    cout << "Введите строку (до 255 символов, в конце точка):\n";
    cin.getline(s, 256);
    
    int n = strlen(s);
    char result[1024] = "";
    int rlen = 0;
    bool firstWord = true;
    
    int i = 0;
    while (i < n) {
        // пропускаем пробелы
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;
        
        // конец текста — точка
        if (s[i] == '.') break;
        
        // выделяем слово
        int start = i;
        while (i < n && s[i] != ' ' && s[i] != '.') i++;
        int len = i - start;
        
        // слово из одних цифр — пропускаем
        if (isAllDigits(s + start, len)) continue;
        
        // формируем идентификатор
        char ident[256];
        int k = 0;
        
        char c0 = s[start];
        if (myIsAlpha(c0) || c0 == '_') {
            ident[k++] = c0;
        } else {
            ident[k++] = '_';
            if (myIsDigit(c0)) ident[k++] = c0;
        }
        
        for (int j = 1; j < len; j++) {
            char c = s[start + j];
            ident[k++] = isValidIdentChar(c) ? c : '_';
        }
        ident[k] = '\0';
        
        // добавляем в результат через пробел
        if (!firstWord) result[rlen++] = ' ';
        strcpy(result + rlen, ident);
        rlen += k;
        firstWord = false;
    }
    
    result[rlen] = '\0';
    cout << "\nРезультат:\n" << result << endl;
    
    return 0;
}