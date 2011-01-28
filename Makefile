
CXX=g++
DEBUG=-g
INCLUDE=-I. -I./EDSDK/Header
CFLAGS=$(DEBUG) $(INCLUDE) -D__APPLE__ -arch i386

FRAMEWORKS=-F./EDSDK/Framework -framework EDSDK -framework carbon

EOSCTRL=eosctrl.app/Contents/MacOS/eosctrl

%.o: %.cpp 
	$(CXX) $(CFLAGS) -c -o $@ $< 

eosctrl: main.o err.o util.o
	$(CXX) $(DEBUG) -arch i386  $(FRAMEWORKS) -o $(EOSCTRL) main.o util.o err.o

clean:
	rm -f *~ *.o $(EOSCTRL)

run: eosctrl
	exec eosctrl.app/Contents/MacOS/eosctrl

srun: eosctrl
	exec sudo /usr/libexec/StartupItemContext eosctrl.app/Contents/MacOS/eosctrl
