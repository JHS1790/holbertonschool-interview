#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool check_stable(int grid[3][3]);
void tumble(int grid[3][3]);
void print_gridC(int grid[3][3]);

#endif /* _SANDPILES_H_ */
