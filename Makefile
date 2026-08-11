.PHONY: clean

# Link to C math library
LDLIBS = -lm

root_finder: root_finder.c root_finding_funcs.c
	$(CC) root_finder.c root_finding_funcs.c -o root_finder $(LDLIBS)

tests: test_root_finding_funcs.c root_finding_funcs.c
	$(CC) test_root_finding_funcs.c root_finding_funcs.c -o tests $(LDLIBS)

run_tests: tests
	./tests

clean:
	$(RM) root_finder tests