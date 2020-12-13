AuzanCourse: main.cpp stats.o uptime.o meminfo.o
	g++ -o $@ main.cpp stats.o uptime.o meminfo.o

stats.o: stats.cpp
	g++ -o $@ -c stats.cpp
  
uptime.o: uptime.cpp
	g++ -o $@ -c uptime.cpp

meminfo.o: meminfo.cpp
	g++ -o $@ -c meminfo.cpp

clean:
	rm -rf AuzanCourse *.o