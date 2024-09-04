#include "Soundex.h"
#include <cctype>
#include <unordered_map>

// Maps characters to their corresponding Soundex digits
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
    return (it != soundexMap.end()) ? it->second : '0';
}

// Adds a Soundex digit to the result if it's valid and not a duplicate
void addSoundexDigit(std::string& soundex, char digit, char prevDigit) {
    if (digit != '0' && digit != prevDigit && soundex.length() < 4) {
        soundex += digit;
    }
}

// Pads the result string to ensure it has exactly 4 characters
void padSoundex(std::string& soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
}

// Main function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return ""; // Return empty string for empty input

    std::string soundex(1, toupper(name[0])); // Start with the first letter
    char prevDigit = mapToSoundexDigit(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char currentDigit = mapToSoundexDigit(name[i]);
        if (currentDigit != '0' && currentDigit != prevDigit) {
            addSoundexDigit(soundex, currentDigit, prevDigit);
            prevDigit = currentDigit;
        }
    }

    padSoundex(soundex);
    return soundex;
}
