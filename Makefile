CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = classtime.o instructor.o course.o courselist.o


main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gc* *.dSYM test/test core main

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/test $(OBJECTS) test/test.cpp

test: testBuild
	test/test --success

coverage: SHELL:=/bin/bash
coverage: test
	total_score=0; \
	total_lines=0; \
	cpp_files=`ls *.cpp | grep -v main.cpp`; \
	echo "$${cpp_files}"; \
	gcov $${cpp_files}; \
	for file in `gcov $${cpp_files} | sed  -n -e "/File '[a-z.]/{N;N;p;}" | grep -v "File" | grep -v "creating" | sed 's/[^0-9]*//' | sed 's/\.[0-9]*% of /,/'`; \
	do \
		IFS=', ' read -r -a array <<< "$${file}"; \
		total_lines=$$((total_lines+$${array[1]})); \
		total_score=$$((total_score+($${array[0]}*$${array[1]}))); \
		echo "$${array[0]}% of $${array[1]} lines"; \
	done; \
	echo "$${total_lines} total lines"; \
	echo "Overall coverage: $$((total_score/total_lines))%"

