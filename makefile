#MakeFile
OBJS = remove_command.o

FLAGS=-O3
main:.cpuset .main
debug:.debugset .main

.cpuset:
	$(eval CXX=g++  $(FLAGS) -DAMP_CPU_EMULATE -std=c++14 -fopenmp)
	$(eval CLINK=g++ -fopenmp -o rmlatexcmd)
.debugset:
	$(eval CXX=g++ -g -DAMP_CPU_EMULATE -D_DEBUG -std=c++14 )
	$(eval CLINK=g++  -pthread -o drmlatexcmd)
	
.main :  $(OBJS) 
	$(CLINK) $(OBJS) -lstdc++fs 



remove_command.o :  remove_command.cpp
	$(CXX) -c remove_command.cpp

clean : 
	rm $(OBJS) -f
