#include <iostream>
#include "List.h"
#include "Stack.h"
#include "StackList.h"
#include <string>
#include <chrono>
# define NO_OF_CHARS 256  

// Проверка сбалансированности скобок
bool BracketsBalanced(std::string expr) {
	Stack stack;

	for (auto& letter : expr) {
		if (letter == '[' || letter == '(' || letter == '{') {
			stack.push(letter);
		}

		if (letter == ']') {
			char stacked_letter = stack.pop();
			if (stacked_letter == '[') {
				std::cout << "Fine" << std::endl;
			}
			else {
				std::cout << "UNBALANCED" << std::endl;

				return false;
			}
		}
		if (letter == ')') {
			char stacked_letter = stack.pop();
			if (stacked_letter == '(') {
				std::cout << "Fine";
			}
			else {
				std::cout << "UNBALANCED" << std::endl;

				return false;
			}
		}
		if (letter == '}') {
			char stacked_letter = stack.pop();

			if (stacked_letter == '{') {
				std::cout << "Fine";
			}
			else {
				std::cout << "UNBALANCED" << std::endl;

				return false;
			}
		}
	}

	if (!stack.is_empty()) {
		return false;
	}

	return true;
}

// Рекурсивный BinarySearch
int binarySearch(int arr[], int l, int r, int x) {
	if (r >= 1) { // l и r - левая и правая границы интервала; 
		int mid = l + (r - 1) / 2;

		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] > x) {
			return binarySearch(arr, l, mid - 1, x);
		}
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
// Итеративный Binary Search
int  itBinarySearch(int arr[], int l, int r, int x) {
	while (l <= r) {
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (arr[m] == x)
				return m;

			if (arr[m] < x)
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		return -1;
	}
	return -1;
}

// Наивный поиск подстроки
void search(const std::string& pat, const std::string& txt) {
	int M = pat.size();
	int N = txt.size();

	int i = 0;
	
	while (i <= N - M) {
		int j;

		for (j = 0; j < M; j++) {
			if (txt[i + j] != pat[j]) break;
		}

		if (j == M) {
			std::cout << "Pattern found at index " << i << std::endl;
			i = i + M;
		}
		else if (j == 0) {
			i = i + 1;
		}
		else i = i + j;
	}

}

// Алгоритм Кнута-Морриса-Пратта
void computeLPS(const std::string& pat, int* lps) {
	int j = 0;
	int i = 1;

	lps[0] = 0;

	while (i < pat.size()) {
		if (pat[i] == pat[j]) {
			j++;
			lps[i] = j;
			i++;
		}
		else {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPsearch(const std::string& pat, const std::string& txt) {
	int* lps = new int(pat.size());

	computeLPS(pat, lps);

	int i = 0;
	int j = 0;

	while (i < txt.size()) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == pat.size()) {
			std::cout << "Found pattern at index " << i - j << std::endl;
			j = lps[j - 1];
		}
		else if (i < txt.size() && pat[j] != txt[i]) {
			if (j != 0) {
				j = lps[j - 1];
			}
			else i = i + 1;
		}
	}
}

// Алгоритм Бойера-Мура
void badCharHeuristic(std::string str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}
void search(std::string txt, std::string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];

	badCharHeuristic(pat, m, badchar);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0)
		{
			std::cout << "pattern occurs at shift = " << s << std::endl;

			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

		}
		else
		{
			int bc = badchar[txt[s + j]];
			s += std::max(1, j - bc);
		}
	}
}




// HOMEWORK
bool isKPeriodic(const std::string& txt, int K) {
	if (K <= 0) { 
		std::cout << "K must be greater than 0!" << std::endl;

		return false;
	}			
	if (txt.size() % K != 0) {
		std::cout << "Length % K != 0, string cannot be periodic" << std::endl;
		return false;
	}

	std::string period{ txt.begin(), txt.begin() + K }; // подстрока длины K
	int enters = 0;										// кол-во вхождений
	
	int* lps = new int[period.size()];
	computeLPS(period, lps);				// считаем LPS проверяемого периода

	int i = 0, j = 0;

	while (i < txt.size()) {
		if (period[j] == txt[i]) {
			i++;
			j++;
		}
		else {
			std::cout << "Missmatch with the substring => String cannot be periodic with period " << K << std::endl;
			return false;
		}
		if (j == period.size()) {
			enters++;
			j = lps[j - 1];
		}
		else if (i < txt.size() && period[j] != txt[i]) {
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}

	if (K * enters == txt.size()) // если количество найденных совпадений, помноженное на К, равно длине строки, то строка кратна К
		std::cout << "string " << txt << " is periodic with period " << K << std::endl;
	else std::cout << "string " << txt << " is not periodic with period " << K << std::endl; // иначе не кратна

	delete[] lps;

	return K;
}

bool isKPeriodicTest(const std::string& txt, int K) {
	if (K <= 0) {
		std::cout << "K must be greater than 0!" << std::endl;

		return false;
	}
	if (txt.size() % K != 0) {
		std::cout << "Length % K != 0, string cannot be periodic" << std::endl;
		return false;
	}

	std::string period{ txt.begin(), txt.begin() + K }; // подстрока длины K
	int enters = 0;										// кол-во вхождений

	int* lps = new int[txt.size()];
	computeLPS(txt, lps);				// считаем LPS проверяемого периода

	if (lps[txt.size() - 1] == (txt.size() - K)) { 
		std::cout << "String is periodic with period " << K << std::endl;
		
		return true;
	}
	else {
		std::cout << "String is not periodic with period " << K << std::endl;

		return false;
	}

	return K;
}

int main()
{
	/*
	List list;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	std::cout << list << std::endl;

	list.push_front(-1);
	list.push_front(-2);
	list.push_front(-3);
	list.push_front(-4);

	std::cout << list << std::endl;

	list.delete_node_pos(6);
	std::cout << list << std::endl;
	list.delete_node_pos(3);
	std::cout << list << std::endl;

	//List l2;

	std::cout << list << std::endl;

	list.delete_node_pos(0);
	std::cout << list << std::endl;

	list.clear();*/

	/*
	int res = BracketsBalanced(std::string("{}()[]"));
	std::cout << res << std::endl;

	res = BracketsBalanced(std::string("{}()[)"));
	std::cout << res << std::endl;*/

	std::string test = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd";
	int K = 4;

	auto start = std::chrono::high_resolution_clock::now();
	isKPeriodic(test, K);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "RESULT = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
	isKPeriodicTest(test, K);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "RESULT = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;

	return 0;

}
