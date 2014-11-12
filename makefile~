CXX=g++

client: Sensor.o City.o main.o
	$(CXX) -o client City.o Sensor.o main.o

main.o: main.cpp Sensor.h City.h
	$(CXX) -c -DMAP main.cpp

Sensor.o: Sensor.cpp Sensor.h
	$(CXX) -c -DMAP Sensor.cpp

 
City.o : City.cpp City.h Sensor.h
	$(CXX) -c -DMAP City.cpp

#in order to clean old .o
clean:
	rm -rf *.o
