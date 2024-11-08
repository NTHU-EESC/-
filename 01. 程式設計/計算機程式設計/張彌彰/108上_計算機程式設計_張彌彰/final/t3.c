
// Q3 108061112 林靖
// Given three strings, paragraph, phrase and new, it is known that the length
// of paragraph is longer than that of both phrase and new. Please write a
// function to generate a new string that is the paragraph with all
// occurrences of phrase replaced by new.
//
// For example,
// char paragraph[] = "Humpty Dumpty sat on a wall,
//             Humpty Dumpty had a great fall.
//             All the king's horses and all the king's men
//             Couldn't put Humpty Dumpty together again.";
// char phrase[] = "Humpty Dumpty"; and
// char new[] = "Hickory Dickory Dock";
//
// Calling replace function we get
// replace(paragraph, phrase, new) = "Hickory Dickory Dock sat on a wall,
//              Hickory Dickory Dock had a great fall.
//              All the king's horses and all the king's men
//              Couldn't put Hickory Dickory Dock together again."

#include <stdlib.h>
#include <string.h>

char *replace(char *paragraph, char *phrase, char *new)
{
	char *replaced = malloc(sizeof(char));
	char *tore;
	char *pa;
	char *ph = phrase;
	char *re = replaced;
	
	for (pa = paragraph; &pa != '\0'; pa++) {
		if (&pa == &ph) {
			ph++;
			tore
		} else {
			realloc(replaced, strlen(replaced) + 2)
			re++;
			&re = &pa;
		}
	}

}
