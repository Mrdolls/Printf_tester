1. Put the folder "t_printf" into your folder where your makefile is.
  
2. Import the .h in your main file with :
```c
#include "t_printf/t_printf.h"
```

3a. For ALL tests, set this:
```c
int main()
{
	TEST_PRINTFULL();
	return (1);
}
```

3b. For CUSTOM test, set this:
```c
int main()
{
	TEST_PRINTF("This is a custom test: %u", 45);
	return (1);
}
```

Preview:
```bash
printf   : This is a custom test: 45
ft_printf: This is a custom test: 45
Result: OK
Len   : OK

--------------------------------
```

4. For the compilation:
```bash
cc -Wall -Wextra -Werror *.c t_printf/t_prinf.a
```
5. Exemples:
```bash
printf   : This is a custom test: 45
ft_printf: This is a custom test: 45
Result: OK
Len   : KO
Error: 25 != 27

---------------------------------
```

```bash
printf   : This is a custom test: Bad ft_printf :(
ft_printf: This is a custom test: ad ft_printf :(
Result: KO
Len   : KO
Error: 39 != 40

---------------------------------
```
