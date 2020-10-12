all	:	p1 p2
p1	:	Tx.c
		@echo "Creating object file for message_queue Tx"
		gcc -o Tx Tx.c -lpthread -lrt -o Tx.out
		./Tx.out

p2	:	Rx.c
		@echo "Creating object file for message_queue Rx"
		gcc -o Rx Rx.c -lpthread -lrt -o Rx.out
		./Rx.out

