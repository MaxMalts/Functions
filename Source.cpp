#include <stdio.h>


/**
*	Печатает строку
*	@param[in] outp Выводимая строка
*/

int Puts(char* outp) {
	int i = 0;
	while (outp[i] != NULL) {
		putchar(outp[i]);
		i++;
	}
	putchar('\n');
	return 0;
}


/**
*	Читает строку из файла
*
*	@param [in] str Записываемая строка
*	@param [in] num Максимальный размер строки
*	@param [in] f Файл
*
*	@return Считанная строка
*/

char* Fgets(char* str, int num, FILE* f) {
	int i = 0;
	char curch = getc(f);
	while ((curch != EOF) && (curch != '\n') && (i < num)) {
		str[i] = curch;
		curch = getc(f);
		i++;
	}
	if (curch == '\n' && i < num) {
		str[i] = '\n';
	}
	return str;
}


/**
*	Конвертирует целое число в строку
*
*	@param[in] num Число
*	@param[in] str Строка
*	@param[in] radix Основание системы счисления
*
*	@return Полученная строка
*/

char* Itoa(int num, char* str, int radix) {
	int i = 0;
	while (num != 0) {
		int digit = num % radix;
		num /= radix;
		if (digit < 10) {
			str[i] = 48 + digit;
		}
		else {
			str[i] = 87 + digit;
		}
		i++;
	}
	return str;
}


/**
*	Конвертирует строку в целое число
*	@param[in] str Строка
*
*	@return Полученное число
*/

int Atoi(char* str) {
	int isnum = 0, isminus=0, ans=0, i=0;
	if (str[0] >= '0' && str[0] <= '9') {
		isnum = 1;
	}
	else if (str[0] = '-' && str[1] >= '0' && str[1] <= '9') {
		isnum = 1;
		isminus = 1;
		i = 1;
	}
	if (isnum) {
		while (str[i] >= '0' && str[i] <= '9') {
			ans = ans * 10 + str[i]-48;
			i++;
		}
		if (isminus) {
			ans *= -1;
		}
	}
	return ans;
}