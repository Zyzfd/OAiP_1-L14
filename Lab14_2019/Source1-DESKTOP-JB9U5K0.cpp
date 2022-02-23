//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <time.h>
//#include <stdlib.h>
//
//#define MAX_LEN 25
//
//
//struct Node {
//	char * word;
//	struct Node * next;
//};
//
//struct Dictionary {
//	struct Node * first;
//	int cnt_words;
//};
//
//struct Dictionary * create();
//void destroy(struct Dictionary * dict);
//void addWord(struct Dictionary * dict, char * word);
//int contains(struct Dictionary * dict, char * word);
//
//
//
//struct Dictionary * create()
//{
//	struct Dictionary * dict = (struct Dictionary *)
//		malloc(sizeof(struct Dictionary));
//	dict->first = NULL;
//	dict->cnt_words = 0;
//	return dict;
//}
//
//void addWord(struct Dictionary * dict, char * word)
//{
//	struct Node  * newNode = (struct Node*)
//		malloc(sizeof(struct Node));
//
//	newNode->next = dict->first;
//	newNode->word = (char *)calloc(strlen(word) + 1,
//		sizeof(char));
//	strcpy(newNode->word, word);
//
//	dict->cnt_words++;
//	dict->first = newNode;
//}
//
//void destroy(struct Dictionary * dict) {
//
//	while (dict->first != NULL)
//	{
//		struct Node * delNode = dict->first;
//		dict->first = dict->first->next;
//
//		free(delNode->word);
//		free(delNode);
//	}
//	free(dict);
//
//}
//
//int contains(struct Dictionary * dict, char * word)
//{
//	struct Node * ptr = dict->first;
//	while (ptr != NULL) {
//		if (strcmp(ptr->word, word) == 0) {
//			return 1;
//		}
//		ptr = ptr->next;
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int loadDictionary(struct Dictionary * dict,
//	const char * filename) {
//	// открыть файл
//	FILE * fin;
//	char s[MAX_LEN];
//
//	fin = fopen(filename, "rt");
//	if (fin == NULL)
//	{
//		return 0;
//	}
//	// в цикле для всех строк
//	while (!feof(fin)) {
//		// загрузить строку
//		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
//			if (s[strlen(s) - 1] == '\n')
//				s[strlen(s) - 1] = '\0';
//			if (!contains(dict, s)) {
//				addWord(dict, s);
//			}
//		}
//	}
//	// закрыть файл
//	fclose(fin);
//	return 1;
//}
//
//
//int convertTextToHtml(
//	struct Dictionary * dict,
//	const char * text_in_filename,
//	const char * text_out_filename)
//{
//	char s[MAX_LEN];
//
//	// открыть файлы
//	FILE *fin = fopen(text_in_filename, "rt");
//	if (fin == NULL)
//	{
//		return 0;
//	}
//
//	FILE *fout = fopen(text_out_filename, "wt");
//	if (fout == NULL)
//	{
//		fclose(fin);
//		return 0;
//	}
//	fprintf(fout, "<!DOCTYPE html>");
//	fprintf(fout, "<html>");
//	fprintf(fout, "<head>");
//	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
//	fprintf(fout, "<title>HTML Document</title>");
//	fprintf(fout, "</head>");
//	fprintf(fout, "<body>");
//
//
//
//	char ch;
//	int is_letter = 0;
//	char word[81];
//	int word_len = 0;
//
//	while ((ch = getc(fin)) != EOF) {
//		if (isalpha((unsigned char)ch)) {
//			if (!is_letter) {
//				word_len = 0;
//			}
//			is_letter = 1;
//			word[word_len++] = ch;
//		}
//		else { // 	if (!isalpha(ch)) {
//
//
//			if (is_letter) {
//				word[word_len] = '\0';
//				if (contains(dict, word))
//					fprintf(fout, "<b>%s</b> ", word);
//				else
//					fprintf(fout, "%s", word);
//			}
//			is_letter = 0;
//			fprintf(fout, "%c", ch);
//			if (ch == '\n')
//				fprintf(fout, "<br>");
//		}
//
//	} // while ((ch = getc(fin)) != EOF)
//	fclose(fin);
//
//	fprintf(fout, "</body>");
//	fprintf(fout, "</html>");
//	fclose(fout);
//	return 1;
//} //  convertTextToHtml- конец!!!
//
//
//
//
//void main() {
//	char dic[][50] = { "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict11.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict12.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict21.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict22.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict31.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict32.txt" };
//	char text[][50] = { "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Alice.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Tolkien.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Tolkien2.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Harry.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Harry2.txt" };
//	for (int i = 0; i <= 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			printf("\ndict: %d, text: %d\n\n", i, j);
//			long t0, t1, t2;
//			t0 = clock();
//			printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);
//
//			struct Dictionary* dict = create();
//			char d[50];
//			strcpy(d, dic[i]);
//			loadDictionary(dict, d);
//
//			t1 = clock();
//			printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);
//
//			int m;
//			switch (i)
//			{
//			case 0:
//				m = 11;
//				break;
//			case 1:
//				m = 12;
//				break;
//			case 2:
//				m = 21;
//				break;
//			case 3:
//				m = 22;
//				break;
//			case 4:
//				m = 31;
//				break;
//			case 5:
//				m = 32;
//				break;
//			default:
//				break;
//			}
//			char m1[55];
//			sprintf_s(m1, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Alice_2%d.html", m);
//
//			char m2[50];
//			strcpy(m2, text[j]);
//
//			convertTextToHtml(dict, m2, m1);
//
//			destroy(dict);
//
//			t2 = clock();
//			printf("t2 = %f sec \n",
//				t2 / (float)CLOCKS_PER_SEC);
//
//			printf("Run time = t2 - t0 = %f sec \n",
//				(t2 - t0) / (float)CLOCKS_PER_SEC);
//		}
//	}
//	{
//		int x;
//		scanf("%d", &x);
//	}
//}
//
