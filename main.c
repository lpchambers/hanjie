#include <stdio.h>
#include "line.h"

int main(void) {
	Line l;
	line_init(&l, 15);
	printf("%d\n", l.len);
	line_print(&l);
	return 0;
}
