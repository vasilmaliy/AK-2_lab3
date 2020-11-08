
build: 
	g++ ./Main.cpp -o main

main: build 
	./main -hcr --help

clean:
	rm -f main

.DEFAULT_GOAL:=main
