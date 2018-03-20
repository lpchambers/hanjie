#include <stdbool.h>
#include <stdint.h>

typedef struct Line {
	char len;
	bool solved;
	uint32_t select_mask;
	uint32_t cross_mask;
} Line;

int line_init(Line *line, char len) {
	line->len = len;
	line->solved = false;
	line->select_mask = 0;
	line-> cross_mask = 0;
	return 0;
}

void line_print(Line *line) {
	int i = 0;
	printf("*");
	for(; i<line->len; i++) {
		if (i%5 == 0) {
			printf("|");
		}
		if (line->select_mask & (1<<i)) {
			printf("O");
		}
		else if (line->cross_mask & (1<<i)) {
			printf("x");
		}
		else {
			printf(" ");
		}
	}
	if (i%5 == 0) printf("|");
	printf("*\r\n");
}
