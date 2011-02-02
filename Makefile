
CXX=g++
DEBUG=-g
INCLUDE=-I. -I./EDSDK/Header
CFLAGS=$(DEBUG) $(INCLUDE) -D__APPLE__ -arch i386

FRAMEWORKS=-F./EDSDK/Framework -framework EDSDK -framework carbon

EOSCTRL=eosctrl.app/Contents/MacOS/eosctrl

%.o: %.cpp 
	$(CXX) $(CFLAGS) -c -o $@ $< 

eosctrl: main.o err.o util.o shoot.o
	$(CXX) $(DEBUG) -arch i386  $(FRAMEWORKS) -o $(EOSCTRL) main.o shoot.o util.o err.o

foo: foo.o
	$(CXX) $(DEBUG) -arch i386  $(FRAMEWORKS) -o foo foo.o

clean:
	rm -f *~ *.o $(EOSCTRL) foo

run: eosctrl
	exec eosctrl.app/Contents/MacOS/eosctrl

srun: eosctrl
	exec sudo /usr/libexec/StartupItemContext eosctrl.app/Contents/MacOS/eosctrl

all: clean eosctrl

