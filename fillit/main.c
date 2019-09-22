#include "header.h"
#include <stdio.h>

void	print_mem(uint16_t *a)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 15; j >= 0; j--)
		{
			printf("%d", (a[i] >> j) & 1);
		}
		printf("\n");
	}
	// for (int i = 0; i < 4; i++)
	// {
	// 	for (int j = 0; j < 16; j++)
	// 	{
	// 		printf("%d", (a[i] >> j) & 1); 
	// 	}
	// 	printf("\n");
	// }
}

void	print_map(uint16_t *array)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 15; j >= 0; j--)
		{
			printf("%d", (array[i] >> j) & 1);
		}
		printf("\n");
	}
	
	// for (int j = 0; j < 4; j++)
	// {
	// 	for (int i = 63; i >= 0; i--)
	// 	{
	// 		printf("%d", (*array >> i) & 1);
	// 		if (i == 48 || i == 32 || i == 16)
	// 			printf("\n");
	// 	}
	// 	printf("\n");
	// 	printf("\n");
	// 	array++;
	// }
}

int		main(int argc, char **argv)
{
	t_tetrem	array_tetr[MAX_TETRAM + 1];
	t_map		map;
	uint16_t	*ptr = map.map_array;
	uint64_t	a = 0;

	reader_file(argv[1], array_tetr, &map);
	// print_map(map.map_array);
	// array_tetr[0].tetreminka = ~array_tetr[0].tetreminka ;
	// print_mem(&(array_tetr[0].tetreminka));
	// printf("\n");
	// print_mem(&(array_tetr[1].tetreminka));
	// printf("\n");
	// print_mem(&(array_tetr[2].tetreminka));
	// printf("\n");
	// *(uint64_t*)map.map_array ^= array_tetr->tetreminka;
	// map.map_array[5] = 1234;
	// ptr -= 3;
	// print_mem(array_tetr[1].tetreminka);
	// *(uint64_t*)ptr ^= array_tetr[1].tetreminka;
	// *(uint64_t*)map.map_array ^= array_tetr->tetreminka;
	// printf("%d\n", map.map_array[1]);
	algorithm(array_tetr, &map);
	// *(uint64_t*)(&map.map_array - 0) ^= 61440;
	// printf("pop = %d\n", map.map_array[3]);
	print_map(map.map_array);
	// printf("%llu", array_tetr[0].tetreminka);
}