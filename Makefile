all: *.cpp
	@g++ -std=c++17 *.cpp -o parser
	@echo Parser Compiled
clean:
	@$(RM) parser