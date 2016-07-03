#!/bin/bash
# 	File          : filler_01.sh
#	Date          : 05-31-2016
#	Program name  : space filler
#	Version       : 0.0.1
#	Author        : ----
#	Enviroment    : CLI
#	Description   : This little script will try to create several
#					folders and files inside them, the size of each file is
#					3.9 KiB (4010 bytes)
#	Notes         : Not optimized at all, just to test the speed of my system
#
#
# 
clear
today=$(date)
host=$(hostname)
linuxver=$(uname -r)
datatofile="1010101010101010101010101010101"
limit=8
echo "-----------------------------------------------------------------"
echo " Small write test to filesystem"
echo " This script is running on $host"
echo " System kernel is $linuxver"
#sleep 2
echo " Choose how long the test will last. "
echo " A higher number means more time to finish, and you can't use the PC meanwhile"
echo " 1- 32"
echo " 2- 64"
echo " 3- 128"
read user_opt
case $user_opt in
	1)
	limit=32
	;;
	2)
	limit=64
	;;
	3)
	limit=128
	;;
	*)
	limit=16
	;;
esac
clear
echo " This test started at : $today"
echo " First test , write multiple files using a fixed 32 character line"
for (( i=0; i <limit; i++))
do
	echo "---------------------------------------------------------"
	echo " Creating folder 'folder_$i'"
	mkdir "folder_"$i
	cd "folder_"$i
	for (( b= 0; b < limit; b++))
	do
		touch "file_"$b
		#echo " File 'file_$b' was created"
		for (( f=0; f < 128; f++))
		do
			echo $datatofile >> "file_"$b
		done
		#printf "File created at %s" $(date)
		#echo "File 'file$b' was created inside $(pwd)"
	done
	echo " Done with 'folder_$i' at $(date)"
	cd ..
done

today=$(date)
echo " Test ended at '$today'"
clear
echo "---------------------------------------------------------"
echo " Second test, copying of a created file of 4.0 KiB lenght"
echo " This test will use the same options from last test"
for (( r = 0; r < limit; r++))
do
	echo "---------------------------------------------------------"
	echo " Copying to folder_$r"
	for (( b=0; b < limit; b++))
	do
		cp copy_testfile "folder_"$r/"copy_test_"$b
	done
	echo " Done with 'folder_$r' at $(date)"
done
today=$(date)
echo " Test ended at '$today'"
#
clear
echo "---------------------------------------------------------"
echo " Third test, copying of a created file of 8.0 KiB lenght"
echo " This test will use the same options from last test"
for (( r = 0; r < limit; r++))
do
	echo "---------------------------------------------------------"
	echo " Copying to folder_$r"
	for (( b=0; b < limit; b++))
	do
		cp copy_testfile1 "folder_"$r/"copy_test1_"$b
	done
	echo " Done with 'folder_$r' at $(date)"
done
today=$(date)
echo " Test ended at '$today'"
#
clear
echo "---------------------------------------------------------"
echo " Third test, copying of a created file of 16.0 KiB lenght"
echo " This test will use the same options from last test"
for (( r = 0; r < limit; r++))
do
	echo "---------------------------------------------------------"
	echo " Copying to folder_$r"
	for (( b=0; b < limit; b++))
	do
		cp copy_testfile2 "folder_"$r/"copy_test2_"$b
	done
	echo " Done with 'folder_$r' at $(date)"
done
today=$(date)
echo " Test ended at '$today'"
#
clear
echo "---------------------------------------------------------"
echo " Third test, copying of a created file of 32.0 KiB lenght"
echo " This test will use the same options from last test"
for (( r = 0; r < limit; r++))
do
	echo "---------------------------------------------------------"
	echo " Copying to folder_$r"
	for (( b=0; b < limit; b++))
	do
		cp copy_testfile3 "folder_"$r/"copy_test3_"$b
	done
	echo " Done with 'folder_$r' at $(date)"
done
today=$(date)
echo " Test ended at '$today'"
clear
echo "---------------------------------------------------------"
echo " Third test, copying of a created file of 256.0 KiB lenght"
echo " This test will use the same options from last test"
for (( r = 0; r < limit; r++))
do
	echo "---------------------------------------------------------"
	echo " Copying to folder_$r"
	for (( b=0; b < limit; b++))
	do
		cp copy_testfile4 "folder_"$r/"copy_test4_"$b
	done
	echo " Done with 'folder_$r' at $(date)"
done
today=$(date)
echo " Test ended at '$today'"
exit
