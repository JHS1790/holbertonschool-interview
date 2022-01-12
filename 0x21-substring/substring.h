#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
bool match(char const *s, char const **words, int nb_words, int word_len);
bool check_word(char const *str, char const *word);
bool check_array(int *arr, int len, int ans);

#endif /* SUBSTRING_H */
