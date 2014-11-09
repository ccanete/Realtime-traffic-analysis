#makefile a finir
CXX=g++

main.o: main.cpp
	$(CXX) -c main.cpp

Sensor.o: Sensor.cpp Sensor.h
	$(CXX) -c Sensor.cpp

 
City.o : City.cpp City.h Sensor.h
	$(CXX) -c City.cpp

#in order to clean old .o
clean:
	rm *.o


