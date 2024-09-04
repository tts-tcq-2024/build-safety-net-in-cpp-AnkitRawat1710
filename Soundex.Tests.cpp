#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, IgnoresVowelsAndCertainConsonants) {
    EXPECT_EQ(generateSoundex("Aeiouhw"), "A000");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, CombinesDuplicateEncodings) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("Jackson"), "J250");
}

TEST(SoundexTest, HandlesNamesWithDifferentCases) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(SoundexTest, HandlesNamesWithSameConsonantsSeparatedByVowels) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T520");
    EXPECT_EQ(generateSoundex("Honeyman"), "H500");
}

TEST(SoundexTest, PadsWithZeroesIfNeeded) {
    EXPECT_EQ(generateSoundex("O"), "O000");
    EXPECT_EQ(generateSoundex("Oa"), "O000");
    EXPECT_EQ(generateSoundex("Ob"), "O100");
}

TEST(SoundexTest, LimitsToFourCharacters) {
    EXPECT_EQ(generateSoundex("Robertson"), "R163");
    EXPECT_EQ(generateSoundex("Rupertson"), "R163");
}

TEST(SoundexTest, HandlesNameWithOnlyIgnoredCharacters) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
    EXPECT_EQ(generateSoundex("Hwhw"), "H000");
}

TEST(SoundexTest, HandlesNameWithAdjacentConsonantsWithSameCode) {
    EXPECT_EQ(generateSoundex("Bbff"), "B100");
    EXPECT_EQ(generateSoundex("Ccgg"), "C200");
    EXPECT_EQ(generateSoundex("Ddtt"), "D300");
}

