all: cmakeGenerateMakeFile cmakeBuild

config: installDependences

build: cmakeGenerateMakeFile cmakeBuild

installDependences:
	sudo apt-get -y install qmake6 qt6-base-dev libqt6charts6-dev libqt6charts6

cmakeGenerateMakeFile:
	qmake6 -o build/Makefile 20222-team-1.pro -Wnone

cmakeBuild:
	cd build && make

run: 
	cd build && ./20222-team-1
