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
	gcc -o bin_tmp/list_number_test tests/list_number.c bin_tmp/list_number.o bin_tmp/number.o bin_tmp/list_teammate.o
	bin_tmp/list_number_test

list_number.o: src/list_number.c headers/list_number.h
	gcc -o bin_tmp/list_number.o -c src/list_number.c

number : number.o list_number.o list_teammate.o tests/number.c
	gcc -o bin_tmp/number_test tests/number.c bin_tmp/number.o bin_tmp/list_number.o bin_tmp/list_teammate.o
	bin_tmp/number_test

number.o: src/number.c headers/number.h
	gcc -o bin_tmp/number.o -c src/number.c

teammate_graph : teammate_graph.o headers/teammate_graph.h tests/teammate_graph.c
	gcc -o bin_tmp/teammate_graph tests/teammate_graph.c bin_tmp/teammate_graph.o
	bin_tmp/teammate_graph

teammate_graph.o : src/teammate_graph.c headers/teammate_graph.h
	gcc -o bin_tmp/teammate_graph.o -c src/teammate_graph.c

teammate_path_list : teammate_path_list.o tests/teammate_path_list.c headers/teammate_path_list.h
	gcc -o bin_tmp/teammate_path_list tests/teammate_path_list.c bin_tmp/teammate_path_list.o
	bin_tmp/teammate_path_list

teammate_path_list.o : src/teammate_path_list.c headers/teammate_path_list.h
	gcc -o bin_tmp/teammate_path_list.o -c src/teammate_path_list.c

all_sets : list_number.o
	gcc -o bin_tmp/generate_all_sets tests/all_sets.c bin_tmp/list_number.o bin_tmp/number.o bin_tmp/list_teammate.o

generate_all_sets : all_sets
	bin_tmp/generate_all_sets > headers/all_sets.h
	cat headers/all_sets.h