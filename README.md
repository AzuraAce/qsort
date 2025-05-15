# QSort

## Install
```
git clone https://github.com/AzuraAce/qsort
cd qsort
make
cp -r ./{lib,include} <your-project-dir>
```

## Usage
When compiling, set these flags
```
-Iinclude -Llib -lqsort
```

For Example
```
gcc -Iinclude -Llib main.c -lqsort -o main
```
