#ifndef LIBCSTR_H
#define LIBCSTR_H

#include <stdbool.h>
#include <stddef.h>

//+++++++++++++++++++++++++++++|FUNCTION
//DECLARATIONS|+++++++++++++++++++++++++++++//

// Length and Copy Operations
size_t strLength(const char *str);
char *strCopy(char *dest, const char *src);

// Character-level checks
bool isAlphanumChar(char c);
char charToLowercase(char c);
char charToUppercase(char c);

// isFUNCTIONS
bool isAlpha(const char *str);
bool isDigit(const char *str);
bool isAlphanum(const char *str);
bool isLowercase(const char *str);
bool isUppercase(const char *str);
bool isWhitespace(const char *str);
bool isHexadec(const char *str);
bool isBinary(const char *str);
bool isOctal(const char *str);
bool isPalindrome(const char *str);
bool isPalindromeIgnoreCase(const char *str);

// Concatenation and Comparison
char *strConcat(char *dest, const char *src);
int strCompareInt(const char *str1, const char *str2);
bool strCompareBool(const char *str1, const char *str2);
int strCompareIntIgnoreCase(const char *str1, const char *str2);
bool strCompareBoolIgnoreCase(const char *str1, const char *str2);
void strSort(char *str);

// Finding Functions
char *strFindChar(const char *str, int ch);
char *strFindString(const char *haystack, const char *needle);
bool strStartsWith(const char *str, const char *prefix);
bool strEndsWith(const char *str, const char *suffix);

// Modification Functions
char *strReverse(char *str);
char *strToUppercase(char *str);
char *strToLowercase(char *str);
char *strToTilecase(char *str);
char *strSwapcase(char *str);
char *strTrimSpace(char *str);
char *strRemoveWhitespace(char *str);
char *strRemoveDuplicates(char *str);
char *strReplace(char *str, const char *old_substr, const char *new_substr);

// Substring and Joining Operations
char *strSubstring(const char *str, int start, int length);
char **strSplit(const char *str, char delimiter, int *count);
char *strJoin(char **strings, int count, const char *delimiter);

// Repetition and Conversion
char *strRepeat(const char *str, int n);
int strToInteger(const char *str);
char *intToString(int num, char *str);
int strBinaryToDecimal(const char *binary_str);
int strOctalToDecimal(const char *octal_str);
int strHexadecimalToDecimal(const char *hex_str);

// Utility Functions
int strCountWords(const char *str);

// Extra Functions
bool isSpace(char c);

#endif
