# make prog_ura => выполнится только одно правило

all_targets: prog_simple prog_ku porg_ura prog_ura_ku

prog_simple: main.cpp
	g++ main.cpp -o prog
	
prog_ku: main.cpp
	g++ main.cpp -o progk -DKU
	
prog_ura: main.cpp
	g++ main.cpp -o progu -DURA
	
prog_ku_ura: main.cpp
	g++ main.cpp -o progku -DKU -DURA