all: src/Estrada.cpp src/connection.cpp src/edgetype.h src/graphviewer.cpp src/FichaJUNG.cpp src/map.cpp src/menu.cpp src/node.cpp src/VETV.cpp src/VETV.h
	g++ -g -o proj src/Estrada.cpp src/connection.cpp src/edgetype.h src/graphviewer.cpp src/FichaJUNG.cpp src/map.cpp src/menu.cpp src/node.cpp src/VETV.cpp src/VETV.h
clean: 
	rm -f proj
force:
	make clean
	make all
