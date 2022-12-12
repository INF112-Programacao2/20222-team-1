all: installDependences cmakeGenerateMakeFile cmakeBuild

installDependences:
	sudo apt-get -y install qt5-qmake qtbase5-dev libqt5charts5-dev

cmakeGenerateMakeFile:
	qmake -o build/Makefile 20222-team-1.pro

cmakeBuild:
	cd build && make

run: 
	cd build && ./20222-team-1
