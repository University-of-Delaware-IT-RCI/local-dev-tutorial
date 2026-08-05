.PHONY: clean

multiply_add: multiply_add.c math_funcs.c
	$(CC) multiply_add.c math_funcs.c -o multiply_add

tests: test_math_funcs.c math_funcs.c
	$(CC) test_math_funcs.c math_funcs.c -o tests

clean:
	$(RM) multiply_add tests