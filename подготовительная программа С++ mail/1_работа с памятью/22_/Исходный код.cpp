#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* substr(char* str, char* sub){
	for (int i = 0, j = 0; str[i] != '\0'; i++){
		while ((str[i + j] != '\0') && ((toupper)(sub[j]) == (toupper)(str[i + j])))
			j++;
		if (sub[j] == '\0') return &str[i];	//адрес начала подстроки
		j = 0; 	//если не точное совпадение
	}
	return NULL;
}
int main(void){
	long wordLen = 0,senLen=0;
	char ch;
	char *word = (char *)malloc(sizeof(char));
	char *str = (char *)malloc(sizeof(char));

	while ((ch = getchar()) != ' '){
		word[wordLen] = ch;
		word = (char *)realloc(word, (1 + (++wordLen))*sizeof(char));
	}
	word[wordLen] = '\0';

	//while ((int)(ch = getchar()) != EOF){
	while ((ch = getchar()) != '\n'){
		str[senLen] = ch;
		str = (char *)realloc(str, (1 + (++senLen))*sizeof(char));
	}
	
	str[senLen] = '\0';

	int cntWord = 0;
	bool flag = 1;
	char *t = str;
	t++;
	while (flag){
		if (substr(t, word)){
			t = substr(t, word);
			t += strlen(word);
			cntWord++;
		}
		else flag = false;
	}

	int len = strlen(str);
	int cntSentense = 0;
	for (int i = 1; i < len; i++){
		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
			cntSentense++;
	}
	printf("\ncount of word = %d\ncount of sentense= %d\n%g", cntWord, cntSentense, (float)cntWord / cntSentense);
	free(word);
	free(str);

	system("pause>void");
	return 0;
}