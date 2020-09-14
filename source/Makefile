export CC=clang-10
export CXX=clang++-10

all: build

build: /workspace/CMakeCache.txt
	cmake --build /workspace

/workspace/CMakeCache.txt:
	cd /workspace && cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug /source
