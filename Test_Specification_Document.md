# **Test Specification Document**
This document outlines the test cases designed to validate the implementation of the Soundex algorithm. The Soundex algorithm encodes words into a letter followed by three digits based on predefined rules, enhancing search capabilities by matching similarly sounding words. The document covers both functional and edge case scenarios to ensure the algorithm works as expected.

### **Features to be Tested**
1. Soundex Code Generation
   - Encoding a word to Soundex format as per defined rules.
2. Handling Different Input Types
   - Single character strings
   - Strings with only vowels
   - Strings with adjacent characters having the same encoding value
3. Code Correctness
   - Proper encoding of consonants based on Soundex digit mapping.
   - Combining duplicate encodings for adjacent consonants.
   - Ignoring vowels and specific consonants (a, e, i, o, u, y, h, w).
   - Zero-padding the output if it’s less than four characters.
4. Boundary Cases
   - Strings with all ignored characters.
   - Strings exceeding the length requirement (only first 4 characters to be used).
   - Different cases of the same name (uppercase, lowercase, mixed-case).

### **Test Cases**

#### **Test Case 1: Handles Single Character String**

| **Test Case ID**  | TC1 |
|-------------------|--------------------------|
| **Objective**     | Verify that the function handles a single character input correctly. |
| **Input**         | `"A"` |
| **Expected Output**| `"A000"` |
| **Rationale**     | If a single character is provided, the output must retain the first letter and pad with zeros to ensure the length is 4 characters. |

---

#### **Test Case 2: Ignores Vowels and Certain Consonants**

| **Test Case ID**  | TC2 |
|-------------------|--------------------------|
| **Objective**     | Ensure that the function ignores vowels (a, e, i, o, u) and certain consonants (h, w). |
| **Input**         | `"Aeiouhw"` |
| **Expected Output**| `"A000"` |
| **Rationale**     | Vowels and the consonants h and w are ignored per Soundex rules. Since no valid consonants are left, the result will be the first letter, padded with zeros. |

---

#### **Test Case 3: Encodes Consonants Correctly**

| **Test Case ID**  | TC3 |
|-------------------|--------------------------|
| **Objective**     | Ensure that consonants are encoded to the correct digits based on Soundex rules. |
| **Input**         | `"Robert"` |
| **Expected Output**| `"R163"` |
| **Rationale**     | The Soundex rules dictate that the consonants R (6), B (1), and T (3) should be encoded. Vowels are ignored. |

---

#### **Test Case 4: Combines Duplicate Consonants**

| **Test Case ID**  | TC4 |
|-------------------|--------------------------|
| **Objective**     | Ensure that consecutive consonants with the same Soundex digit are encoded as a single digit. |
| **Input**         | `"Jackson"` |
| **Expected Output**| `"J250"` |
| **Rationale**     | The letters `C` and `K` map to the same digit (2). These are adjacent in "Jackson" and should be encoded as a single 2. |

---

#### **Test Case 5: Handles Names with Different Cases**

| **Test Case ID**  | TC5 |
|-------------------|--------------------------|
| **Objective**     | Ensure the function handles different letter cases (upper and lower). |
| **Input**         | `"Rubin"` |
| **Expected Output**| `"R150"` |
| **Rationale**     | The algorithm should be case-insensitive, so "Rubin" should result in the same Soundex code regardless of letter case. |

---

#### **Test Case 6: Handles Names with Vowels Between Consonants**

| **Test Case ID**  | TC6 |
|-------------------|--------------------------|
| **Objective**     | Ensure that vowels between consonants do not interfere with the encoding of consonants. |
| **Input**         | `"Tymczak"` |
| **Expected Output**| `"T520"` |
| **Rationale**     | Vowels (y) between consonants should be ignored, and only consonants are considered for encoding. The output should only include valid consonants in their proper order. |

---

#### **Test Case 7: Pads with Zeros if Needed**

| **Test Case ID**  | TC7 |
|-------------------|--------------------------|
| **Objective**     | Ensure that the function pads the output with zeros if fewer than 4 characters are produced. |
| **Input**         | `"O"` |
| **Expected Output**| `"O000"` |
| **Rationale**     | The algorithm requires the output to be 4 characters long, so it must pad with zeros if necessary. |

---

#### **Test Case 8: Limits Output to Four Characters**

| **Test Case ID**  | TC8 |
|-------------------|--------------------------|
| **Objective**     | Ensure that the Soundex code is limited to 4 characters. |
| **Input**         | `"Robertson"` |
| **Expected Output**| `"R163"` |
| **Rationale**     | Only the first 4 characters of the Soundex code are retained, so additional consonants beyond that should be ignored. |

---

#### **Test Case 9: Handles Names with Only Ignored Characters**

| **Test Case ID**  | TC9 |
|-------------------|--------------------------|
| **Objective**     | Ensure the function handles names with only vowels and ignored consonants. |
| **Input**         | `"Aeio"` |
| **Expected Output**| `"A000"` |
| **Rationale**     | All characters are ignored except the first one, so the output should be the first character followed by zeros. |

---

#### **Test Case 10: Adjacent Consonants with Same Code**

| **Test Case ID**  | TC10 |
|-------------------|--------------------------|
| **Objective**     | Ensure that adjacent consonants that map to the same Soundex digit are only encoded once. |
| **Input**         | `"Bbff"` |
| **Expected Output**| `"B100"` |
| **Rationale**     | The letters `B` and `F` both map to the same digit (1). The algorithm should encode them as a single '1'. |

---

### **Conclusion**
The test cases outlined in this document will ensure that the Soundex algorithm adheres to its specification and handles a wide range of input types, including common and edge cases.
