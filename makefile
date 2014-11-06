#makefile a finir
CXX=g++



Sensor.o: Sensor.cpp Sensor.h
	$(CXX) -c Sensor.cpp

 
City.o : City.cpp City.h Sensor.h
        $(CXX) -c City.cpp


clean:
	rm *.o


