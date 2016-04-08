#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

char* substr(char* str, char* sub){
	for(int i = 0, j = 0; str[i] != '\0'; i++){
		while ((str[i + j] != '\0') && ((toupper)(sub[j]) == (toupper)(str[i + j])))
			j++;
		if (sub[j] == '\0') return &str[i];	//адрес начала подстроки
		j = 0; 	//если не точное совпадение
	}
	return NULL;
}

int main(int argc, char *argv[]){
	//char word[40];
	//char a[400];
	char* word=(char*)malloc(sizeof(char));
	char* a = (char*)malloc(sizeof(char));;
	char ch;
	int wordLen=0,senLen=0;


	//scanf("%s", &word);//считывание без пробелов
	while (ch=getchar() != ' '){
		word[wordLen] = ch;
		word = (char*)realloc(a, (1 + (wordLen++))*sizeof(char));
	}
	word[wordLen] = '\0';

	//gets(a);
	while (ch = getchar() != EOF){
		a[senLen] = ch;
		a = (char*)realloc(a, (1 + (senLen++))*sizeof(char));
	}
	word[senLen] = '\0';
	//ВЫВОД
	printf("%s%s\n", word,a);
	_getch();
	//подсчет совпадений
	int cntWord=0;
	bool flag = 1;
	char *t = a; 
	t++;
	while (flag){
		if (substr(t, word)){
			t = substr(t, word);
			t += strlen(word);
			//t = t + strlen(word);
			//t = substr(a, word) - strlen(substr(t, word))+strlen(word);
			cntWord++;
		}
		//if (strcmp(t, word)==0) 
			else flag = false;
	}

	//ВЫВОД
	//printf("%s%s\n", word,a);
	//ВЫВОД
	//for (int i = 1; i < len; i++){
	//	printf("%c", a[i]);
	//}

	//подсчет предложений
	int len = strlen(a);
	a[len] = '\0';
	int cntSentense = 0;
	for (int i = 1; i < len; i++){
		if (a[i] == '.' || a[i] == '!' || a[i] == '?')
			cntSentense++;
	}
	printf("\ncount of word = %d\ncount of sentense= %d\n%g", cntWord, cntSentense, (float)cntWord/cntSentense);
	
	_getch();
	return 0;
}