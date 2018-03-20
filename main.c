//#include "line.h"
#include "grid.h"

int main(void) {
	Grid g;
	grid_init(&g, 15, 15);
	grid_print_details(&g);
	grid_print(&g);
	grid_free(&g);
	return 0;
}
