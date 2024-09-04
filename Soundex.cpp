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

// Adds a Soundex digit to the result, ensuring the length and validity
void addSoundexDigit(std::string& soundex, char digit, char& prevDigit) {
    if (digit != '0' && digit != prevDigit) {
        soundex += digit;
        prevDigit = digit;
    }
}

// Main function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return ""; // Return empty string for empty input

    std::string soundex(1, toupper(name[0])); // Start with the first letter
    char prevDigit = mapToSoundexDigit(name[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char currentDigit = mapToSoundexDigit(name[i]);
        addSoundexDigit(soundex, currentDigit, prevDigit);
        if (soundex.length() == 4) break; // Stop if length reaches 4
    }

    // Pad with zeros if needed
    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
