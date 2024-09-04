#include "Soundex.h"
#include <cctype>
#include <unordered_map>

// Function to map a character to its corresponding Soundex digit
char mapToSoundexDigit(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    c = toupper(c);
    auto it = soundexMap.find(c);
    return it != soundexMap.end() ? it->second : '0';
}

// Function to check if a character's Soundex digit is ignorable
bool isIgnorable(char code) {
    return code == '0';
}

// Function to append a Soundex digit to the result if it's valid
void appendSoundexDigit(std::string& soundex, char digit) {
    if (soundex.length() < 4 && !isIgnorable(digit) && (soundex.empty() || soundex.back() != digit)) {
        soundex += digit;
    }
}

// Main function to generate Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = mapToSoundexDigit(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char currentCode = mapToSoundexDigit(name[i]);
        appendSoundexDigit(soundex, currentCode);
        prevCode = currentCode;
    }

    soundex.append(4 - soundex.length(), '0');
    return soundex;
}
