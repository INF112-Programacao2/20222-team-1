all: cmakeGenerateMakeFile cmakeBuild
	
cmakeGenerateMakeFile:
	qmake -o build/Makefile 20222-team-1.pro

cmakeBuild:
	cd build && make

run: 
	cd build && ./20222-team-1