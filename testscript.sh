#!/bin/bash

project="C12"

userpath="$HOME/piscine_42_london_june_2023/"
test_path="$HOME/1337-Piscine-42/$project"
#test_path="$HOME/Piscine_42_2022_JY/c02submit"
main_path="$HOME/semi_evaluate/$project"

project_path="$userpath$project"
for i in  00 01 02  03  04  05 06  07 08 09 10 11 12 13 14 15 16 17 
do
	echo -e "\n TEST ex$i" 
    dir=$HOME/temp/test/ex$i/
    if [ ! -d "$dir" ]; then
    mkdir -p "$dir"
    fi

    
    dir=$HOME/temp/ex$i/
    if [ ! -d "$dir" ]; then
    mkdir -p "$dir"
    fi

    dir=$HOME/temp/user/ex$i/
    if [ ! -d "$dir" ]; then
    mkdir -p "$dir"
    fi

    cp -R $main_path/ex$i/* $HOME/temp/test/ex$i/
    cp -R $main_path/ex$i/* $HOME/temp/user/ex$i/

    for file in $(find $test_path/ex$i/* | grep -v 'main'); do
        cp -R $file $HOME/temp/test/ex$i/
    done
    cp -R $test_path/ex00/ft_create_elem.c $HOME/temp/test/ex$i/

    cp -R $project_path/ex$i/* $HOME/temp/user/ex$i/
    cp -R $project_path/ex00/ft_create_elem.c $HOME/temp/user/ex$i/
    
	norminette -R CheckForbiddenSourceHeader $project_path/ex$i/*.c $project_path/ex$i/*.h
    #norminette -R CheckDefine $project_path/ex$i/*.c $project_path/ex$i/*.h
    

	gcc -Wall -Wextra -Werror  -o  $HOME/temp/ex$i/user $HOME/temp/user/ex$i/*.c -lbsd
	gcc -Wall -Wextra -Werror  -o  $HOME/temp/ex$i/test $HOME/temp/test/ex$i/*.c -lbsd
	#cat ${project_path}/ex$i/*
	#read a
	if [ -f "./ex$i/run.sh" ]; then
		./ex$i/run.sh
	else
		
        diff <($HOME/temp/ex$i/user lkjdfla lkadj dajfeaf f aslfjf fdasof) <($HOME/temp/ex$i/test lkjdfla lkadj dajfeaf f aslfjf fdasof)
        #if [ -z "$diff_output" ]; then
        #    echo "\n There is no difference between the files."
            
        #else
        #    echo "$diff_output"
        #fi
        
	fi
	#read a
done