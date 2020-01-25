build:
		gcc $(mysql_config --cflags) ./src/main.c $(mysql_config --libs) ./src/utils/memory.c ./src/calculation.c ./src/evalutor.c ./src/operations/add.c ./src/operations/sub.c ./src/operations/mul.c ./src/operations/div.c ./src/operations/per.c -L/usr/lib/mysql -lmysqlclient 
Test:
		gcc -o ./Test ./test/main_test.c ./src/utils/memory.c ./src/calculation.c ./src/evalutor.c ./src/operations/add.c ./src/operations/sub.c ./src/operations/mul.c ./src/operations/div.c ./src/operations/per.c
clean:
		rm a.out Test