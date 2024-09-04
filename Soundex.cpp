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

// Determines if the current digit should be appended to the result
bool shouldAppendDigit(const std::string& soundex, char digit, char prevDigit) {
    return soundex.length() < 4 && digit != '0' && digit != prevDigit;
}

// Processes characters to build the Soundex code
void processCharacters(const std::string& name, std::string& soundex) {
    if (name.empty()) return; // CCN = 1

    char prevDigit = mapToSoundexDigit(name[0]);
    soundex += toupper(name[0]); // Include the first letter's code

    for (size_t i = 1; i < name.length(); ++i) { // CCN = 2
        char currentDigit = mapToSoundexDigit(name[i]);
        if (shouldAppendDigit(soundex, currentDigit, prevDigit)) {
            soundex += currentDigit;
        }
        prevDigit = currentDigit;
    }
}

// Main function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    std::string soundex;
    processCharacters(name, soundex); // CCN = 1

    // Ensure the result is exactly four characters long
    if (soundex.length() < 4) {
        soundex.resize(4, '0'); // Pad with zeros if needed
    }

    return soundex;
}
