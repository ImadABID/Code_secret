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