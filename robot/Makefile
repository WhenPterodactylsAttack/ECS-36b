# Dylan Yue 920058006
CXXFLAG = -Wall
CXX=g++

robot:robot.o Angle.o
	$(CXX) -o $@ $^

robot.o:robot.cpp
	$(CXX) -o $@ -c $^

Angle.o:Angle.cpp Angle.h
	$(CXX) -o $@ -c $<

clean:
	rm -f robot robot.o Angle.o
