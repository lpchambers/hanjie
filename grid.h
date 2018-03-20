#include "line.h"
#include <stdlib.h>

typedef struct Grid {
	char width;
	char height;
	Line *rows;
} Grid;

int grid_init(Grid *grid, char width, char height) {
	if (width <= 0) return -1;
	if (height <= 0) return -1;

	grid->rows = malloc((width + height) * sizeof(Line*));
	if (grid->rows == NULL) {
		return -1;
	}

	grid->width = width;
	grid->height = height;

	// Initialise rows
	for (int i=0; i<width; i++) {
		line_init(&grid->rows[i], width);
	}
	return 0;
}

int grid_free(Grid *grid) {
	free(grid->rows);
	return 0;
}

void grid_print_details(Grid *grid) {
	printf("Grid @ %p\r\n", grid);
	printf("Width:  %d\r\n", grid->width);
	printf("Height: %d\r\n", grid->height);
}

void print_char_n_times(char c, int n) {
	for (int i=0; i<n; i++) printf("%c", c);
}

void print_horiz_border(char c, int n) {
	printf("  ");  // For the vertical *|
	print_char_n_times(c, n);
	printf("\r\n");
}

void grid_print(Grid *grid) {
	int horiz_border_len = grid->width + (grid->width/5);

	print_horiz_border('*', horiz_border_len);

	for (int i=0; i<grid->height; i++) {
		if (i%5 == 0) print_horiz_border('-', horiz_border_len);
		line_print(&grid->rows[i]);
	}

	print_horiz_border('-', horiz_border_len);
	print_horiz_border('*', horiz_border_len);
}
