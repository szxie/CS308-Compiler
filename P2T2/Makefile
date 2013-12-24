SC: SCp.cpp SCl.cpp main.cpp
	g++ -o SC SCp.cpp SCl.cpp main.cpp
	
SCp.cpp: SCp.y
	bison -d -o SCp.cpp SCp.y

SCp.hpp: SCp.cpp

SCl.cpp: SCl.l SCp.hpp
	flex -o SCl.cpp SCl.l

clean:
	rm SC SCp.cpp SCp.hpp SCl.cpp
