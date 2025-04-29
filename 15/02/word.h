#ifndef WORD_H
#define WORD_H

/* Reads the next word from the input and stores it in word. */
/* Makes word empty if no word could be read because end-of-file. */
/* Truncates the wortd if its length exceeds len. */
void read_word(char *word, int len);

#endif
