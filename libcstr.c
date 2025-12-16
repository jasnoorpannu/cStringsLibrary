#include "libcstr.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//+++++++++++++++++++++++++++++|FUNCTIONS|+++++++++++++++++++++++++++++//

// Length and Copy Operations

// Returns the length of a given string.
size_t strLength(const char *str) {
  size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

// Copies the source string to the destination string and returns the
// destination.
char *strCopy(char *dest, const char *src) {
  char *original_dest = dest;
  while ((*dest++ = *src++) != '\0')
    ;
  return original_dest;
}

// Character-level helper functions
bool isAlphanumChar(char c) { return isalnum(c); }

char charToLowercase(char c) { return tolower(c); }

char charToUppercase(char c) { return toupper(c); }

// isFUNCTIONS

// Returns true if the string contains only alphabetic characters.
bool isAlpha(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only digit characters.
bool isDigit(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only alphanumeric characters.
bool isAlphanum(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalnum(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only lowercase alphabetic characters.
bool isLowercase(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!islower(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only uppercase alphabetic characters.
bool isUppercase(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isupper(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only whitespace characters.
bool isWhitespace(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isSpace(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only hexadecimal characters.
bool isHexadec(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isxdigit(str[i])) {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only binary characters ('0' or '1').
bool isBinary(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] != '0' && str[i] != '1') {
      return false;
    }
  }
  return true;
}

// Returns true if the string contains only octal digits (0-7).
bool isOctal(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '7') {
      return false;
    }
  }
  return true;
}

// Returns true if the string is a palindrome, ignoring non-alphanumeric
// characters.
bool isPalindrome(const char *str) {
  int len = strLength(str);
  int i, j;

  for (i = 0, j = len - 1; i < j; i++, j--) {
    while (i < j && !isAlphanumChar(str[i])) // CHANGED
      i++;
    while (i < j && !isAlphanumChar(str[j])) // CHANGED
      j--;

    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

// Returns true if the string is a palindrome, ignoring case and
// non-alphanumeric characters.
bool isPalindromeIgnoreCase(const char *str) {
  int len = strLength(str);
  int i, j;

  for (i = 0, j = len - 1; i < j; i++, j--) {
    while (i < j && !isAlphanumChar(str[i])) // CHANGED
      i++;
    while (i < j && !isAlphanumChar(str[j])) // CHANGED
      j--;

    if (charToLowercase(str[i]) != charToLowercase(str[j])) { // CHANGED
      return false;
    }
  }
  return true;
}

// Concatenation and Comparison

// Concatenates two strings and returns the destination string.
char *strConcat(char *dest, const char *src) {
  char *ptr = dest + strLength(dest);
  while ((*ptr++ = *src++) != '\0')
    ;
  return dest;
}

// Compares two strings lexicographically and returns an integer result.
int strCompareInt(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Compares two strings lexicographically and returns true if they are equal.
bool strCompareBool(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *str1 == *str2;
}

// Compares two strings lexicographically, ignoring case, and returns an integer
// result.
int strCompareIntIgnoreCase(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return charToLowercase((unsigned char)*str1) -
         charToLowercase((unsigned char)*str2);
}

// Compares two strings lexicographically, ignoring case, and returns true if
// they are equal.
bool strCompareBoolIgnoreCase(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return charToLowercase((unsigned char)*str1) ==
         charToLowercase((unsigned char)*str2);
}

// Sort the String - Helper functions
static void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

static int partition(char *str, int low, int high) {
  char pivot = str[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (str[j] < pivot) {
      i++;
      swap(&str[i], &str[j]);
    }
  }
  swap(&str[i + 1], &str[high]);
  return i + 1;
}

static void quickSort(char *str, int low, int high) {
  if (low < high) {
    int pi = partition(str, low, high);
    quickSort(str, low, pi - 1);
    quickSort(str, pi + 1, high);
  }
}

// Sort the String
void strSort(char *str) {
  int len = strLength(str);
  quickSort(str, 0, len - 1);
}

// Finding Functions

// Finds the first occurrence of a character in a string and returns a pointer
// to it.
char *strFindChar(const char *str, int ch) {
  while (*str != '\0' && *str != ch) {
    str++;
  }
  return (*str == ch) ? (char *)str : NULL;
}

// Finds the first occurrence of a substring within a string and returns a
// pointer to it.
char *strFindString(const char *haystack, const char *needle) {
  if (!*needle) {
    return (char *)haystack;
  }

  while (*haystack) {
    const char *h = haystack;
    const char *n = needle;

    while (*h && *n && *h == *n) {
      h++;
      n++;
    }

    if (!*n) {
      return (char *)haystack;
    }

    haystack++;
  }

  return NULL;
}

// Checks if a string starts with a given prefix and returns true if it does.
bool strStartsWith(const char *str, const char *prefix) {
  while (*prefix) {
    if (*prefix++ != *str++) {
      return false;
    }
  }
  return true;
}

// Checks if a string ends with a given suffix and returns true if it does.
bool strEndsWith(const char *str, const char *suffix) {
  int str_len = strLength(str);
  int suffix_len = strLength(suffix);

  if (suffix_len > str_len) {
    return false;
  }

  return strCompareBool(str + str_len - suffix_len, suffix);
}

// Modification Functions

// Reverses the given string in place and returns the modified string.
char *strReverse(char *str) {
  int len = strLength(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
  return str;
}

// Converts all characters of the string to uppercase.
char *strToUppercase(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}

// Converts all characters of the string to lowercase.
char *strToLowercase(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

// Converts the string to titlecase (first letter uppercase, rest lowercase).
char *strToTilecase(char *str) {
  bool newWord = true;
  for (int i = 0; str[i] != '\0'; i++) {
    if (isspace(str[i])) {
      newWord = true;
    } else if (newWord) {
      str[i] = toupper(str[i]);
      newWord = false;
    } else {
      str[i] = tolower(str[i]);
    }
  }
  return str;
}

// Switches the case of each character in the string (uppercase to lowercase and
// vice versa).
char *strSwapcase(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (isupper(str[i])) {
      str[i] = tolower(str[i]);
    } else if (islower(str[i])) {
      str[i] = toupper(str[i]);
    }
  }
  return str;
}

// Removes leading and trailing whitespace from the string.
char *strTrimSpace(char *str) {
  int start = 0;
  int end = strLength(str) - 1;

  while (isspace(str[start])) {
    start++;
  }

  while (end >= start && isspace(str[end])) {
    end--;
  }

  int newLength = end - start + 1;
  for (int i = 0; i < newLength; i++) {
    str[i] = str[start + i];
  }
  str[newLength] = '\0';

  return str;
}

// Removes all whitespace characters from the string.
char *strRemoveWhitespace(char *str) {
  int i = 0, j = 0;
  while (str[i]) {
    if (!isspace(str[i])) {
      str[j++] = str[i];
    }
    i++;
  }
  str[j] = '\0';
  return str;
}

// Removes duplicate characters from the string.
char *strRemoveDuplicates(char *str) {
  int len = strLength(str);
  if (len <= 1)
    return str;

  int newLength = 0;
  for (int i = 0; i < len; i++) {
    bool foundDuplicate = false;
    for (int j = 0; j < newLength; j++) {
      if (str[i] == str[j]) {
        foundDuplicate = true;
        break;
      }
    }
    if (!foundDuplicate) {
      str[newLength++] = str[i];
    }
  }
  str[newLength] = '\0';
  return str;
}

// Replaces all occurrences of old_substr with new_substr in the string.
char *strReplace(char *str, const char *old_substr, const char *new_substr) {
  char buffer[1024];
  char *position = strstr(str, old_substr);

  if (position == NULL)
    return str;

  int len_before = position - str;

  strncpy(buffer, str, len_before);
  buffer[len_before] = '\0';

  strcat(buffer, new_substr);
  strcat(buffer, position + strLength(old_substr));

  strcpy(str, buffer);
  return str;
}

// Substring and Joining Operations

// Extracts a substring from the given string starting at the specified position
// and with the specified length.
char *strSubstring(const char *str, int start, int length) {
  char *substr = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    substr[i] = str[start + i];
  }
  substr[length] = '\0';
  return substr;
}

// Splits the given string by the delimiter and returns an array of substrings.
char **strSplit(const char *str, char delimiter, int *count) {
  int len = strLength(str);
  char **result = malloc(sizeof(char *) * len);
  int resultIndex = 0;
  int start = 0;

  for (int i = 0; i <= len; i++) {
    if (str[i] == delimiter || str[i] == '\0') {
      result[resultIndex] = strSubstring(str, start, i - start);
      resultIndex++;
      start = i + 1;
    }
  }

  *count = resultIndex;
  return result;
}

// Joins an array of strings into a single string with a delimiter in between.
char *strJoin(char **strings, int count, const char *delimiter) {
  int totalLength = 0;
  for (int i = 0; i < count; i++) {
    totalLength += strLength(strings[i]);
  }
  totalLength += (count - 1) * strLength(delimiter) + 1;

  char *result = malloc(totalLength);
  result[0] = '\0';

  for (int i = 0; i < count; i++) {
    strcat(result, strings[i]);
    if (i < count - 1) {
      strcat(result, delimiter);
    }
  }
  return result;
}

// Repetition and Conversion

// Returns a string that repeats the input string n times.
char *strRepeat(const char *str, int n) {
  int len = strLength(str);
  char *result = malloc(len * n + 1);

  for (int i = 0; i < n; i++) {
    strcat(result, str);
  }
  return result;
}

// Converts a string to an integer.
int strToInteger(const char *str) {
  int result = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    result = result * 10 + (str[i] - '0');
  }
  return result;
}

// Converts an integer to a string.
char *intToString(int num, char *str) {
  snprintf(str, 12, "%d", num);
  return str;
}

// Converts a binary string to decimal.
int strBinaryToDecimal(const char *binary_str) {
  int result = 0;
  for (int i = 0; binary_str[i] != '\0'; i++) {
    result = result * 2 + (binary_str[i] - '0');
  }
  return result;
}

// Converts an octal string to decimal.
int strOctalToDecimal(const char *octal_str) {
  int result = 0;
  for (int i = 0; octal_str[i] != '\0'; i++) {
    result = result * 8 + (octal_str[i] - '0');
  }
  return result;
}

// Converts a hexadecimal string to decimal.
int strHexadecimalToDecimal(const char *hex_str) {
  int result = 0;
  for (int i = 0; hex_str[i] != '\0'; i++) {
    result =
        result * 16 + (isdigit(hex_str[i]) ? hex_str[i] - '0'
                                           : toupper(hex_str[i]) - 'A' + 10);
  }
  return result;
}

// Utility Functions

// Counts the number of words in a string.
int strCountWords(const char *str) {
  int count = 0;
  bool inWord = false;

  for (int i = 0; str[i] != '\0'; i++) {
    if (isspace(str[i])) {
      inWord = false;
    } else if (!inWord) {
      count++;
      inWord = true;
    }
  }
  return count;
}

// Checks if the character is a space.
bool isSpace(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }

// LIBCSTR_H
