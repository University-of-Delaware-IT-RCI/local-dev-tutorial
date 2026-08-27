.PHONY: all run_tests clean

# C compiler flags (e.g. warnings or optimization level)
CFLAGS = -Wall

# Link to C math library
LDLIBS = -lm

all: root_finder tests run_tests

root_finder: root_finder.c root_finding_funcs.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

tests: test_root_finding_funcs.c root_finding_funcs.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

run_tests: tests
	./tests

clean:
	$(RM) root_finder tests