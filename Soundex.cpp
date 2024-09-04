#include "Soundex.h"
#include <cctype>
#include <unordered_map>

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

bool isIgnorable(char digit) {
    return digit == '0';
}

bool canAppendSoundexDigit(const std::string& soundex, char currentCode, char previousCode) {
    return soundex.length() < 4 && !isIgnorable(currentCode) && (currentCode != previousCode);
}

void processCharacter(const std::string& name, std::string& soundex, char& previousCode, size_t index) {
    char currentCode = mapToSoundexDigit(name[index]);
    
    if (canAppendSoundexDigit(soundex, currentCode, previousCode)) {
        soundex += currentCode;
    }

    if (!isIgnorable(currentCode)) {
        previousCode = currentCode;
    }
}

void processCharacters(const std::string& name, std::string& soundex) {
    char previousCode = mapToSoundexDigit(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        processCharacter(name, soundex, previousCode, i);
    }
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    processCharacters(name, soundex);

    soundex.append(4 - soundex.length(), '0');
    return soundex;
}
