.PHONY: clean

root_finder: root_finder.c root_finding_funcs.c
	$(CC) root_finder.c root_finding_funcs.c -o root_finder

tests: test_root_finding_funcs.c root_finding_funcs.c
	$(CC) test_root_finding_funcs.c root_finding_funcs.c -o tests

run_tests: tests
	./tests

clean:
	$(RM) root_finder tests