1. Put the folder "t_printf" into your folder where your makefile is.
  
2. Import the lib in your main with :
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
