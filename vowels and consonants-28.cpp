/*In a class, an English teacher was teaching the vowels and consonants to the students.  
She says “Vowel sounds allow the air to flow freely, causing the chin to drop 
noticeably, whilst consonant sounds are produced by restricting the air flow”. As a  
class activity the students are asked to identify the vowels and consonants in the given 
word/sentence and count the number of elements in each.  Write an algorithm to help 
the student to count the number of vowels and consonants in the given sentence.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void countVowelsAndConsonants(const char *sentence, int *vowel_count, int *consonant_count) {
    char vowels[] = "aeiouAEIOU";
    *vowel_count = 0;
    *consonant_count = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) { 
            if (strchr(vowels, sentence[i])) {
                (*vowel_count)++;
            } else {
                (*consonant_count)++;
            }
        }
    }
}
int main() {
    char sentence[256];
    int vowel_count, consonant_count;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    countVowelsAndConsonants(sentence, &vowel_count, &consonant_count);

    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);

    return 0;
}
