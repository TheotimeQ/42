

#include "libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	printf("\nRETOUR %d |",ft_printf(" %%"));
	// printf("\n");
	printf("\nRETOUR %d |",printf(" %%"));
}

//Si malloc brake return -1
//Header changer 
//normer !
//Leak sur substr ?

// Error in test 44: ft_printf("%+.5d, %+.5d, %+.5d, %+.5d, %+.5d, %+.5d, %+.5d, %+.5d", 0, 5, 
// -1, -10, 100, -1862, INT_MIN, INT_MAX): returned: 69, but expected: 72
// Error in test 44: ft_printf("%+.5d, %+.5d, %+.5d, %+.5d, %+.5d, %+.5d, %+.5d, %+.5d", 0, 5, 
// -1, -10, 100, -1862, INT_MIN, INT_MAX): different memory

// Error in test 45: ft_printf("%+.10d, %+.10d, %+.10d, %+.10d, %+.10d, %+.10d, %+.10d, 
// %+.10d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX): returned: 99, but expected: 102
// Error in test 45: ft_printf("%+.10d, %+.10d, %+.10d, %+.10d, %+.10d, %+.10d, %+.10d, 
// %+.10d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX): different memory

// - [OUTPUT] ft_printf("%-05%")

// 48:     TEST(24, print(" %+d ", LONG_MIN));
// 52:     TEST(28, print(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
// ULONG_MAX, 0, -42));
// 79:     TEST(53, print(" %+i ", UINT_MAX));