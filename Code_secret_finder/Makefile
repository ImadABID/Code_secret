install : main.o
	gcc -o bin/finder bin_tmp/main.o

worktree :
	mkdir bin_tmp bin

clean :
	rm -f bin_tmp/*

uninstall : clean
	rm -f bin/*

main.o : src/main.c
	gcc -o bin_tmp/main.o -c main.c

list_teammate : list_teammate.o tests/list_teammate.c
	gcc -o bin_tmp/list_teammate_test tests/list_teammate.c bin_tmp/list_teammate.o
	bin_tmp/list_teammate_test

list_teammate.o : src/list_teammate.c headers/list_teammate.h
	gcc -o bin_tmp/list_teammate.o -c src/list_teammate.c


list_number : list_number.o number.o list_teammate.o tests/list_number.c
	gcc -o bin_tmp/list_number_test tests/list_number.c bin_tmp/list_number.o bin_tmp/list_teammate.o
	bin_tmp/list_number_test

list_number.o: src/list_number.c headers/list_number.h
	gcc -o bin_tmp/list_number.o -c src/list_number.c

number : number.o list_number.o list_teammate.o tests/number.c
	gcc -o bin_tmp/number_test tests/number.c bin_tmp/number.o bin_tmp/list_teammate.o
	bin_tmp/number_test

number.o: src/number.c headers/number.h
	gcc -o bin_tmp/number.o -c src/number.c
