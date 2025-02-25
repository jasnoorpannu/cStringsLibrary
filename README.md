# **cStringsLibrary: A Comprehensive String Manipulation Library in C**

The `cStringsLibrary` is a versatile C library designed to provide a wide range of efficient and essential string manipulation functions. From basic operations such as string length, copying, and concatenation, to advanced features like string sorting, palindrome checks, and case conversions, this library aims to simplify string handling in C. 

It also includes specialized functions for working with various numeric formats (binary, octal, hexadecimal), word counting, and string joining and splitting, making it a comprehensive solution for handling strings in C projects and Competitive Programming.

This library is designed for efficiency, readability, and ease of use, providing a rich set of tools for developers working with C strings. Whether you're building applications, writing algorithms, or dealing with complex string data, `cStringsLibrary` offers the functionality you need :)

<p align="center">
  <img src="https://github.com/jasnoorpannu/cStringsLibrary/blob/main/cStringsLogo.png"/>
</p>

# **How to Use the `libcstr` Library**

Using the `libcstr` library is simple and straightforward. Follow these steps to get started:

## **1. Download the Library**
To begin using the library, download the `libcstr.c` and `libcstr.h` files from the repository or your preferred source.

## **2. Include the Header File**
In your C program, include the `libcstr.h` header file to access all the functions provided by the library.

```c
#include "libcstr.h"
```

## **3. Compile the Code**
If you're working with the `libcstr.c` file directly, ensure that it is included during compilation. For example, if you're using GCC, compile your program like this:

```bash
gcc -o myProgram myProgram.c libcstr.c
```

This command will compile both your source file (`myProgram.c`) and the `libcstr.c` file together, linking them to produce the final executable.

## **4. Use the Functions**
Now, you can begin using the library functions in your program. Here's an example:

```c
#include "libcstr.h"
#include <stdio.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[50];

    // Copy string
    strCopy(str2, str1);
    printf("Copied String: %s\n", str2);

    // Reverse string
    strReverse(str1);
    printf("Reversed String: %s\n", str1);

    // Check if string is a palindrome
    if (isPalindrome(str1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
```

## **5. Build and Run**
Once you've added the necessary functions and logic to your program, build and run it as usual:

```bash
gcc -o myProgram myProgram.c libcstr.c
./myProgram
```

## **6. Explore Other Functions**
The `libcstr` library includes a variety of functions for string manipulation, such as sorting, splitting, finding substrings, checking properties, and more. To explore additional functionality, refer to the header file `libcstr.h` for the full list of available functions.

# **Functions in cStrings Library:**

## **Length and Copy Operations**
- **`strLength(const char* str)`**: Returns the length of the string, excluding the null terminator.
- **`strCopy(char* dest, const char* src)`**: Copies the content of the `src` string into the `dest` string.

## **isFUNCTIONS (Check Functions)**
- **`isAlpha(const char* str)`**: Returns `true` if the string contains only alphabetic characters.
- **`isDigit(const char* str)`**: Returns `true` if the string contains only digits.
- **`isAlphanum(const char* str)`**: Returns `true` if the string contains only alphanumeric characters (letters and digits).
- **`isLowercase(const char* str)`**: Returns `true` if the string contains only lowercase letters.
- **`isUppercase(const char* str)`**: Returns `true` if the string contains only uppercase letters.
- **`isWhitespace(const char* str)`**: Returns `true` if the string contains only whitespace characters (spaces, tabs, newlines).
- **`isHexadec(const char* str)`**: Returns `true` if the string represents a valid hexadecimal number.
- **`isBinary(const char* str)`**: Returns `true` if the string represents a valid binary number.
- **`isOctal(const char* str)`**: Returns `true` if the string represents a valid octal number.
- **`isPalindrome(const char* str)`**: Returns `true` if the string is a palindrome (reads the same forwards and backwards).
- **`isPalindromeIgnoreCase(const char* str)`**: Returns `true` if the string is a palindrome, ignoring case.

## **Concatenation and Comparison**
- **`strConcat(char* dest, const char* src)`**: Concatenates `src` to the end of `dest`.
- **`strCompareInt(const char* str1, const char* str2)`**: Compares two strings lexicographically and returns an integer indicating the result.
- **`strCompareBool(const char* str1, const char* str2)`**: Compares two strings and returns `true` if they are identical, `false` otherwise.
- **`strCompareIntIgnoreCase(const char* str1, const char* str2)`**: Compares two strings lexicographically ignoring case.
- **`strCompareBoolIgnoreCase(const char* str1, const char* str2)`**: Compares two strings ignoring case, returns `true` if they are identical.
- **`strSort(char* str)`**: Sorts the characters in the string in lexicographical order.

## **Finding Functions**
- **`strFindChar(const char* str, int ch)`**: Finds the first occurrence of the character `ch` in the string.
- **`strFindString(const char* haystack, const char* needle)`**: Finds the first occurrence of `needle` within `haystack`.
- **`strStartsWith(const char* str, const char* prefix)`**: Returns `true` if `str` starts with the `prefix`.
- **`strEndsWith(const char* str, const char* suffix)`**: Returns `true` if `str` ends with the `suffix`.

## **Modification Functions**
- **`strReverse(char* str)`**: Reverses the string in-place.
- **`strToUppercase(char* str)`**: Converts all characters in the string to uppercase.
- **`strToLowercase(char* str)`**: Converts all characters in the string to lowercase.
- **`strToTilecase(char* str)`**: Converts the first character of each word in the string to uppercase, and the rest to lowercase.
- **`strSwapcase(char* str)`**: Swaps the case of all characters in the string.
- **`strTrimSpace(char* str)`**: Removes leading and trailing whitespace characters from the string.
- **`strRemoveWhitespace(char* str)`**: Removes all whitespace characters from the string.
- **`strRemoveDuplicates(char* str)`**: Removes duplicate consecutive characters from the string.
- **`strReplace(char* str, const char* old_substr, const char* new_substr)`**: Replaces all occurrences of `old_substr` with `new_substr` in `str`.

## **Substring and Joining Operations**
- **`strSubstring(const char* str, int start, int length)`**: Returns a substring from `str` starting at `start` with the given `length`.
- **`strSplit(const char* str, char delimiter, int* count)`**: Splits `str` into an array of strings based on `delimiter`, storing the number of splits in `count`.
- **`strJoin(char** strings, int count, const char* delimiter)`**: Joins an array of strings into a single string, separating them with `delimiter`.

## **Repetition and Conversion**
- **`strRepeat(const char* str, int n)`**: Repeats the string `n` times and returns the new string.
- **`strToInteger(const char* str)`**: Converts a string to its integer representation.
- **`intToString(int num, char* str)`**: Converts an integer `num` to a string and stores it in `str`.
- **`strBinaryToDecimal(const char* binary_str)`**: Converts a binary string to its decimal equivalent.
- **`strOctalToDecimal(const char* octal_str)`**: Converts an octal string to its decimal equivalent.
- **`strHexadecimalToDecimal(const char* hex_str)`**: Converts a hexadecimal string to its decimal equivalent.

## **Utility Functions**
- **`strCountWords(const char* str)`**: Counts the number of words in the string (words are separated by spaces).

## **Extra Functions**
- **`isSpace(char c)`**: Returns `true` if the character `c` is a space.

# **Connect with me!**

If you found this library useful or have any questions, feel free to connect with me on the following social media platforms:

Twitter: https://x.com/j4snoor_pannu

GitHub: https://github.com/jasnoorpannu

LinkedIn: https://www.linkedin.com/in/jasnoorpannu/


Looking forward to connecting with you!
