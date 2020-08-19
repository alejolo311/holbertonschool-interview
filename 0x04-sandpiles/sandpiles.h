#ifndef SANDPILES_H
#define SANDPILES_H

void add(int grid1[3][3], int grid2[3][3]);
int check_if_is_unstable(int grid[3][3]);
void print(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void stabilize(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
