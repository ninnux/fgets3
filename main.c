/* fgets3 -- использование функции fgets() */
#include <stdio.h>
#include <locale.h>

#define STLEN 10

int main(void) {
    setlocale(LC_ALL, "Rus");
    char words[STLEN];
    int i;

    puts("Введите строки (или пустую строку для выхода из программы):");
    while (fgets(words, STLEN, stdin) != NULL
           && words[0] != '\n') {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else  // требуется наличие words[i] == '\0'
            while (getchar() != '\n')
                continue;
        puts(words);
    }
    puts("Готово.");
    return 0;
}

