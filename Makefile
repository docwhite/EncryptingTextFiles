onRun: encode decode
	touch phrase.txt; \
	echo "A file called 'phrase.txt' has been created. Edit it and enter the word to encrypt."; \
	echo "To encrypt a file type './encode <text file to encrypt> <encrypted text file> KEYWORD'"; \
	echo "To decrypt a file type './decode <encrypted text file> <decrypted text file> KEYWORD'"; \
	echo "If the name of the text file you enter doesn't exist, an blank one will be created with this name"
encode:
	gcc encode.c -o encode
decode:
	gcc decode.c -o decode 
clean:
	rm *txt; \
	rm *~; \
	rm encode; \
	rm decode
