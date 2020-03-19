// SPDX-License-Identifier: GPL-2.0-only
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linenum;

int getword(FILE *fp, char *buf, int size)
{
	int c;
	int i;

	for (c = getc(fp); c != EOF && isspace(c); c = getc(fp))
		if (c == '\n')
			linenum++;

	for (i = 0; c != EOF && !isspace(c); c = getc(fp))
		if (i < size - 1)
			buf[i++] = tolower(c);
	if (i < size)
		buf[i] = '\0';

	if (c != EOF)
		ungetc(c, fp);

	return (buf[0] != '\0');
}

void doubleword(char *name, FILE *fp)
{
	char prev[128], word[128];

	linenum = 1;
	prev[0] = '\0';

	while (getword(fp, word, sizeof(word))) {
		if (isalpha(word[0]) && strcmp(prev, word) == 0) {
			if (name)
				printf("%s:", name);
			printf("%d: %s\n", linenum, word);
		}
		strcpy(prev, word);
	}
}

int main(int argc, char *argv[])
{
	int i;
	FILE *fp;

	for (i = 1; i < argc; i++) {
		fp = fopen(argv[i], "r");
		if (!fp) {
			fprintf(stderr, "%s: can't open '%s' (%s)\n", argv[0],
				argv[i], strerror(errno));
			return EXIT_FAILURE;
		}
		doubleword(argv[i], fp);
		fclose(fp);
	}

	if (argc == 1)
		doubleword(NULL, stdin);

	return EXIT_SUCCESS;
}
