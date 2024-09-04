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

// Checks if a digit is ignorable (i.e., '0')
bool isIgnorable(char digit) {
    return digit == '0';
}

// Determines if the current digit should be appended to the result
bool shouldAppendDigit(const std::string& soundex, char currentCode, char previousCode) {
    return soundex.length() < 4 && !isIgnorable(currentCode) && currentCode != previousCode;
}

// Processes characters to build the Soundex code
void processCharacters(const std::string& name, std::string& soundex) {
    if (name.empty()) return;
    
    char previousCode = mapToSoundexDigit(name[0]);
    soundex += toupper(name[0]); // Include the first letter's code

    for (size_t i = 1; i < name.length(); ++i) {
        char currentChar = name[i];
        char currentCode = mapToSoundexDigit(currentChar);

        if (currentCode != previousCode && !isIgnorable(currentCode)) {
            if (soundex.length() < 4) {
                soundex += currentCode;
            }
            previousCode = currentCode; // Update previousCode only when appending
        }
    }
}

// Main function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    std::string soundex;
    processCharacters(name, soundex);
    soundex.resize(4, '0'); // Pad with zeros to ensure the length is 4

    return soundex;
}
