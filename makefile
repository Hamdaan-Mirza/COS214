run:
	g++ *.cpp -o TestingMain
	./TestingMain

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.json *.html *.css output.txt coverage.txt valgrind.txt -f TestingMain

# coverage:
# 	make clean
# 	g++ -g --coverage -dumpbase '' *.cpp -o TestingMain
# 	./TestingMain > output.txt
# 	gcov -f -m -r -j TestingMain > coverage.txt 
# 	gcovr --html-details output.html

valgrind:
	make clean
	make
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --keep-stacktraces=alloc-and-free --error-exitcode=1 -s --log-file=valgrind.txt ./TestingMain > output.txt

gdb:
	make clean
	make
	gdb ./TestingMain
