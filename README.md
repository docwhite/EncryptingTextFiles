Text File Encrypter
===================

Encrypts text files using bitwise operations on ASCII characters. This code is an exercise, I do not own any rights. The exercise is designed by Eike Falk Anderson, lecturer at NCCA (Bournemouth University). I just wanted to share my results with my fellow students.
I will explain a little bit the workflow to get this thing working properly. Considering that our understanding so far about makefiles and C is quite a beginner one I will try to go step by step.
## Installation
1. Clone this project to your git repos folder or if you are not familiarized with git just download the files as a ZIP.
2. Uncompress the files to your home directory and navigate to the uncompressed folder.
```
cd ~/encryptingTextFiles-master/
```
## Usage
We will have 2 executables, 2 binaries. One called **encode** and another one called **decode**. Pretty self-explanatory. Both will accept some arguments when executing them, this additional arguments will be the name of the text files we want to work with (input.txt and output.txt, or source.txt and destination.txt) and a keyword to decode or encode, let me explain it later.

