#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define some_max 500 + 1

int day_one_solver(char* line) {
    char num[3] = {0};
    bool on_end = false;

    for (size_t ind = 0; line[ind] != 0; ind++) {
	if (isdigit(line[ind])) {
	    printf("%d, ", line[ind]);
	    if (on_end) {
		num[on_end] = line[ind];
	    }
	    else {
		num[on_end] = line[ind];
		on_end = true;
	    }
	}
    }

    if (num[1] == 0) { num[1] = num[0]; }
    return atoi(num);
}

int main (int args, char* argv[]) {
    char buffer[some_max] = {0};
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) { return EXIT_FAILURE; }
    
    int q1_total = 0;
    while (fgets(buffer, sizeof(buffer), input)) {
	int temp = day_one_solver(buffer);
	q1_total += temp;

	printf("%s :: %d\n", buffer, temp);
	memset(buffer, 0, sizeof(buffer));
    }

    printf("Advent 2023 - Day One:\n Challenge 1: %d\n", q1_total);
}
