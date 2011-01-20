
CXX=g++
DEBUG=-g
INCLUDE=-I. -I./EDSDK/Header
CFLAGS=$(DEBUG) $(INCLUDE)

FRAMEWORKS=-F./EDSDK/Framework -framework EDSDK -framework carbon

%.o: %.cpp 
	$(CXX) -c -o $@ $< $(CFLAGS)

eosctrl: main.o err.o
	$(CXX) $(DEBUG) -arch i386  $(FRAMEWORKS) -o eosctrl main.o err.o

clean:
	rm -f *~ *.o;
