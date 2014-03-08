Text File Encrypter
===================

Encrypts text files using bitwise operations on ASCII characters. This code is an exercise, I do not own any rights. The exercise is designed by Eike Falk Anderson, lecturer at NCCA (Bournemouth University). I just wanted to share my results with my fellow students.
I will explain a little bit the workflow to get this thing working properly. Considering that our understanding so far about makefiles and C is quite a beginner one I will try to go step by step.
## Installation
* Clone this project to your git repos folder or if you are not familiarized with git just download the files as a ZIP.
* Uncompress the files to your home directory and navigate to the uncompressed folder.
```
Ramon$ cd ~/encryptingTextFiles-master/
```
## Usage
We will have 2 executables, 2 binaries. One called **encode** and another one called **decode**. Pretty self-explanatory. Both will accept some arguments when executing them, this additional arguments will be the name of the text files we want to work with (input.txt and output.txt, or source.txt and destination.txt) and a keyword to decode or encode, let me explain it later.
* Start by running the make command (I included a Makefile which does all the compilation work for
   us). If you dive inside the **Makefile** you will see that once you type the *make* command it will
create an empty text file called **phrase.txt** which will be the place where you will have to write
the word you want to encrypt to. You will get the two binaries as well ready to be executed,
**encode** and **decode**.
```
# The flag -s stands for silent. That way you don't see all the commands printed out.
Ramon$ make -s
```
* Try to list all the elements we have now.
```
Ramon$ ls
decode decode.c encode encode.c Makefile phrase.txt
```
* Now let's write the word or phrase we want to encrypt into the **phrase.txt** file:
```
# Write text inside the phrase.txt file (you can do it manually if you want...)
Ramon$ echo "HHH" > phrase.txt
# Printing the content inside phrase.txt to our terminal. Just to check.
Ramon$ cat phrase.txt
HHH
```
* We run the **encode** binary! We will write something like *./encode <source text file>
   <destination text file> <keyword>*. If the destination text file does not exist don't worry, it
will be created automatically. But make sure the source text file you refer to it does exist.
```
Ramon$ ./encode phrase.txt encrypted.txt PPP
# Let's make sure we got an encrypted text file
Ramon$ ls *txt
encrypted.txt phrase.txt
# We got it. Now let's see what the encrypted ASCII character is.
Ramon$ cat encrypted.txt
+++
# "+++" is what we get.
```
* If we want to decrypt is the same process but using the **decode** binary.
```
# Without the right keyword we won't be able to get what we had before encrypting
# so if we enter something different than "PPP" we won't get "HHH" back to our
# DECRYPTED.txt text file.
Ramon$ ./decode encrypted.txt DECRYPTED.txt PPP
Ramon$ ls *txt
encrypted.txt DECRYPTED.txt phrase.txt
# If we read the DECRYPTED.txt file...
Ramon$ cat DECRYPTED.txt
HHH
```
* If you want to clean all the temporary files, text files and binaries, type `make clean -s`

However I have some problems... For instance when I try to code my name `Ramon` using the keyword `Josefina` and try to decode it back, I get completely wrong characters. Non of the examples I wrote work. I am quite frustated. I will create probably another branch inside this git and start experimenting with other methods. If you have any idea please tell me.
I will attach now an image explaining my approach for decoding. Maybe it is easier to understand... or not, who knows...

<a href="http://imgur.com/UWIxjRv"><img src="http://i.imgur.com/UWIxjRv.jpg?1" title="Hosted by
imgur.com" /></a>`
