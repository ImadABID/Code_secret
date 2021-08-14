install : worktree main.o
	gcc -o bin/finder bin_tmp/main.o

main.o : main.c
	gcc -o bin_tmp/main.o -c main.c

worktree :
	mkdir bin_tmp bin

clean :
	rm -rf bin_tmp

uninstall : clean
	rm -rf bin