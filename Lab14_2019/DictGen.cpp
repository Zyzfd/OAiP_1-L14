//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//
//
//
//#define MAX_WORDS 10000
//#define MAX_LEN 25
//
//struct Dictionary {
//	char words[MAX_WORDS][MAX_LEN];
//	int cnt_words;
//};
//
//struct Dictionary * create();
//void destroy(struct Dictionary * dict);
//void addWord(struct Dictionary * dict, char * word);
//int contains(struct Dictionary * dict, char * word);
//
//
//struct Dictionary * create()
//{
//	struct Dictionary * dict = (struct Dictionary *)
//		malloc(sizeof(struct Dictionary));
//	dict->cnt_words = 0;
//	return dict;
//}
//
//void destroy(struct Dictionary * dict) {
//	free(dict);
//}
//
//
//
//void addWord(struct Dictionary * dict, char * word)
//{
//	if (dict->cnt_words >= MAX_WORDS) {
//		return; // словарь переполнен!
//	}
//
//	int i = dict->cnt_words;
//	while ((i > 0) && (strcmp(word, dict->words[i - 1]) < 0)) {
//		strncpy(dict->words[i], dict->words[i - 1], MAX_LEN - 1);
//		i--;
//	}
//	strncpy(dict->words[i], word, MAX_LEN - 1);
//	++dict->cnt_words;
//}
//
//
//int contains(struct Dictionary * dict, char * word)
//{
//	int left = 0;
//	int right = dict->cnt_words - 1;
//
//	while (left <= right) {
//		int middle = (left + right) / 2;
//
//		int dif = strcmp(dict->words[middle], word);
//		if (dif == 0) {
//			return 1;
//		}
//		if (dif < 0) {
//			left = middle + 1;
//		}
//		if (dif > 0) {
//			right = middle - 1;
//		}
//	}
//	return 0;
//}
//
//
//
//
//void shuffle(struct Dictionary * dict)
//{
//	srand(42);
//	for (int i = 0; i < dict->cnt_words * 2; i++) {
//		int i1 = rand() % dict->cnt_words;
//		int i2 = rand() % dict->cnt_words;
//
//		char s[MAX_LEN];
//
//		strncpy(s, dict->words[i1], MAX_LEN - 1);
//		strncpy(dict->words[i1], dict->words[i2], MAX_LEN - 1);
//		strncpy(dict->words[i2], s, MAX_LEN - 1);
//	}
//}
//
//
//
//int createDictionary(struct Dictionary * dict,
//	const char * filename) {
//
//	FILE *fin = fopen(filename, "rt");
//
//	if (fin == NULL) {
//		return 0;
//	}
//
//	int is_letter = 0;
//	char word[81]; // если слово будет длиннее 80 символов Ц всЄ сломаетс€!
//	int word_len = 0;
//	int ch;
//
//
//
//	while ((ch = getc(fin)) != EOF)
//	{
//		if (isalpha((unsigned char)ch)) {
//			if (!is_letter) {
//				word_len = 0;
//				is_letter = 1;
//			}
//			word[word_len++] = ch;
//		}
//		//else { // if (!isalpha(ch)) {
//
//
//		else { // if (!isalpha(ch)) {
//
//			if (is_letter) {
//				word[word_len] = '\0';
//				if (!contains(dict, word)) {
//					addWord(dict, word);
//				}
//			}
//			is_letter = 0;
//		} // else 
//	} // while ((ch = getc(fin)) != EOF)
//
//
//	fclose(fin);
//
//
//	return 1;
//}
//
//void saveDictionary(struct Dictionary * dict, const char * filename)
//{
//
//	// открыть файл
//	FILE * fout = fopen(filename, "wt");
//	// в цикле дл€ всех строк
//	int i;
//	for (i = 0; i < dict->cnt_words; ++i)
//	{
//		fprintf(fout, "%s\n", dict->words[i]);
//	}
//	// закрыть файл
//	fclose(fout);
//}
//
//
//
//void main() {
//	long t0, t1, t2;
//	t0 = clock();
//	printf("t0 = %f sec \n", t0 / (float)CLOCKS_PER_SEC);
//
//	struct Dictionary *dict = create();
//	
//	//createDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Alice.txt");
//	//createDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Tolkien.txt");
//	//createDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Tolkien2.txt");
//	createDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Harry.txt");
//	//char m[][50] = { "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Alice.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Tolkien.txt", "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\Tolkien2.txt" };
//
//
//	t1 = clock();
//	printf("t1 = %f sec \n", t1 / (float)CLOCKS_PER_SEC);
//
//	//shuffle(dict);
//	//saveDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict12.txt");
//
//	//saveDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict22.txt");
//	saveDictionary(dict, "C:\\Users\\yanka\\OneDrive\\stuff\\Texts\\dict32.txt");
//	destroy(dict);
//
//	t2 = clock();
//	printf("t2 = %f sec \n",
//		t2 / (float)CLOCKS_PER_SEC);
//
//	printf("Run time = t2 - t0 = %f sec \n",
//		(t2 - t0) / (float)CLOCKS_PER_SEC);
//
//	{
//		int x;
//		scanf("%d", &x);
//	}
//}
