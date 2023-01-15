.PHONY: all clean build run rebuild unittest integrtest test 

all: clean build test

clean:
	rm -rf build

build:
	./build.sh -DCMAKE_BUILD_TYPE=Debug

run:
	./build.sh -DCMAKE_BUILD_TYPE=Release
	./build/app/demo_app

rebuild: clean build

unittest: build
	./build/tests/unit/unique_names_unit_test

integrtest: build
	./tests/integr/test_app.py

test: unittest integrtest