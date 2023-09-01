: Clean up
rm output -rf
mkdir output

: Compile
g++ main.cpp -w -o output/main
