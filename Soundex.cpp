#include "Soundex.h"
#include <cctype>
#include <unordered_map>

// Function to convert a character to its corresponding Soundex digit
char mapToSoundexDigit(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    char uppercaseChar = toupper(c);
    auto it = soundexMap.find(uppercaseChar);
    return (it != soundexMap.end()) ? it->second : '0';
}

// Function to check if a Soundex digit is ignorable
bool isIgnorable(char digit) {
    return digit == '0';
}

// Function to check if there is room to append another digit
bool canAppendMoreDigits(const std::string& soundex) {
    return soundex.length() < 4;
}

// Function to check if the digit is different from the last appended digit
bool isDifferentFromPrevious(const std::string& soundex, char digit) {
    return soundex.empty() || soundex.back() != digit;
}

// Function to determine if a Soundex digit can be appended
bool canAppendSoundexDigit(const std::string& soundex, char digit) {
    return canAppendMoreDigits(soundex) && !isIgnorable(digit) && isDifferentFromPrevious(soundex, digit);
}

// Function to append a Soundex digit to the result if it's valid
void appendSoundexDigit(std::string& soundex, char digit) {
    if (canAppendSoundexDigit(soundex, digit)) {
        soundex += digit;
    }
}

// Function to process each character in the name
void processCharacters(const std::string& name, std::string& soundex) {
    char previousCode = mapToSoundexDigit(name[0]);
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char currentCode = mapToSoundexDigit(name[i]);
        appendSoundexDigit(soundex, currentCode);
        previousCode = currentCode;
    }
}

// Main function to generate Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    processCharacters(name, soundex);

    // Pad with zeros if needed
    soundex.append(4 - soundex.length(), '0');
    return soundex;
}
