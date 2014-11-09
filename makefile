#makefile a finir
CXX=g++

client: main.o City.o Sensor.o
	$(CXX) City.o Sensor.o main.o -o client

main.o: main.cpp
	$(CXX) -c main.cpp

Sensor.o: Sensor.cpp Sensor.h
	$(CXX) -c Sensor.cpp

 
City.o : City.cpp City.h Sensor.h
	$(CXX) -c City.cpp

#in order to clean old .o
clean:
	rm *.o


