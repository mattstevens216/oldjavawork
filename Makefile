RPS.exe: tool.o rock.o paper.o scissors.o RPSgame.o play.o
	g++ tool.o rock.o paper.o scissors.o RPSgame.o play.o -o RPS.exe
tool.o: tool.cpp
	g++ -c tool.cpp
rock.o: rock.cpp
	g++ -c rock.cpp
paper.o: paper.cpp
	g++ -c paper.cpp
scissors.o: scissors.cpp
	g++ -c scissors.cpp
RPSgame.o: RPSgame.cpp
	g++ -c RPSgame.cpp
play.o: play.cpp
	g++ -c play.cpp
clean:
	rm -f *.o *.out *.exe
