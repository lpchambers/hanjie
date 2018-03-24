#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Line {
	char len;
	bool solved;
	uint32_t select_mask;
	uint32_t cross_mask;
} Line;

int line_init(Line *line, char len);
void line_print(Line *line);
void line_set_select_mask(Line *line, uint32_t newmask);
void line_set_cross_mask(Line *line, uint32_t newmask);

