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

function copy_test_1(){
	echo "---------------------------------------------------------"
	echo " This test started at : $today"
	echo " First test , write multiple files using a fixed 32 character line"
	for (( i=0; i <limit; i++))
	do
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
}


function copy_test_2(){
	echo "---------------------------------------------------------"
	echo " Second test, copying of a created file of 4.0 KiB lenght"
	echo " This test will use the same options from last test"
	for (( r = 0; r < limit; r++))
	do
		echo " Copying to folder_$r"
		for (( b=0; b < limit; b++))
		do
			cp copy_testfile "folder_"$r/"copy_test_"$b
		done
		echo " Done with 'folder_$r' at $(date)"
	done
	today=$(date)
	echo " Test ended at '$today'"
	}


	function copy_test_3(){
	echo "---------------------------------------------------------"
	echo " Third test, copying of a created file of 8.0 KiB lenght"
	echo " This test will use the same options from last test"
	for (( r = 0; r < limit; r++))
	do
		echo " Copying to folder_$r"
		for (( b=0; b < limit; b++))
		do
			cp copy_testfile1 "folder_"$r/"copy_test1_"$b
		done
		echo " Done with 'folder_$r' at $(date)"
	done
	today=$(date)
	echo " Test ended at '$today'"
}

function copy_test_4(){
	echo "---------------------------------------------------------"
	echo " Third test, copying of a created file of 16.0 KiB lenght"
	echo " This test will use the same options from last test"
	for (( r = 0; r < limit; r++))
	do
		echo " Copying to folder_$r"
		for (( b=0; b < limit; b++))
		do
			cp copy_testfile2 "folder_"$r/"copy_test2_"$b
		done
		echo " Done with 'folder_$r' at $(date)"
	done
	today=$(date)
	echo " Test ended at '$today'"
}

function copy_test_5(){
	echo "---------------------------------------------------------"
	echo " Third test, copying of a created file of 32.0 KiB lenght"
	echo " This test will use the same options from last test"
	for (( r = 0; r < limit; r++))
	do
		echo " Copying to folder_$r"
		for (( b=0; b < limit; b++))
		do
			cp copy_testfile3 "folder_"$r/"copy_test3_"$b
		done
		echo " Done with 'folder_$r' at $(date)"
	done
	today=$(date)
	echo " Test ended at '$today'"
}

function copy_test_6(){
	echo "---------------------------------------------------------"
	echo " Third test, copying of a created file of 256.0 KiB lenght"
	echo " This test will use the same options from last test"
	for (( r = 0; r < limit; r++))
	do
		echo " Copying to folder_$r"
		for (( b=0; b < limit; b++))
		do
			cp copy_testfile4 "folder_"$r/"copy_test4_"$b
		done
		echo " Done with 'folder_$r' at $(date)"
	done
	today=$(date)
	echo " Test ended at '$today'"
}
clear
# Some vars to start
today=$(date)
host=$(hostname)
linuxver=$(uname -r)
# the data to copy
datatofile="1010101010101010101010101010101"
limit=8
# Case vars to catch from dialog
DIALOG_CANCEL=1
DIALOG_ESC=255
HEIGHT=0
WIDTH=0
# Width and height of the gauge window
RHEIGHT=22
RWIDTH=77
# The ouput temp file to use
OUTPUT=/home/versus/bin/output.tmp$$
TMPFILE=/home/versus/bin/testfile.tmp$$

# trap and delete temp files
trap "rm $OUTPUT; rm $TMPFILE; exit" SIGHUP SIGINT SIGTERM



while true; do
	exec 3>&1
	selection=$(dialog \
		--backtitle "Simple test for the filesystem" \
		--title "Menu" \
		--clear \
		--cancel-label "Exit" \
		--menu "Choose how long the test will last :" $HEIGHT $WIDTH 4 \
		"1" "32 iterations" \
		"2" "64 iterations" \
		"3" "128 iterations" \
		2>&1 1>&3)
	exit_status=$?
	exec 3>&-
	case $exit_status in
		$DIALOG_CANCEL)
		clear
		[ -f $OUTPUT ] && rm $OUTPUT
		[ -f $TMPFILE ] && rm $TMPFILE
		echo "Program terminated."
		exit
		;;
		$DIALOG_ESC)
		clear
		[ -f $OUTPUT ] && rm $OUTPUT
		[ -f $TMPFILE ] && rm $TMPFILE
		echo "Program aborted." >&2
		exit 1
		;;
	esac
	case $selection in
		0 )
		clear
		echo "Program terminated."
		;;
		1 )
		
		limit=32
		PCT=17
		(
		copy_test_1 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_2 >> $OUTPUT
		PCT=`expr $PCT + 10`
		copy_test_3 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_4 >> $OUTPUT
		PCT=`expr $PCT + 10`
		copy_test_5 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_6 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT		
		) | dialog --title "Test progress" --gauge "Please wait while test ends..." 20 70 0
		
		cat $OUTPUT | expand >> $TMPFILE
		dialog --backtitle "Sequential Byte Copy test" --title "Results" --textbox "$TMPFILE" $RHEIGHT $RWIDTH
		;;
		2 )
		limit=64
		PCT=17
		(
		copy_test_1 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_2 >> $OUTPUT
		PCT=`expr $PCT + 10`
		copy_test_3 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_4 >> $OUTPUT
		PCT=`expr $PCT + 10`
		copy_test_5 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_6 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT		
		) | dialog --title "Test progress" --gauge "Please wait while test ends..." 20 70 0
		cat $OUTPUT | expand >> $TMPFILE
		dialog --backtitle "Sequential Byte Copy test" --title "Results" --textbox "$TMPFILE" $RHEIGHT $RWIDTH		
		;;
		3 )
		limit=128
		PCT=17
		(
		copy_test_1 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_2 >> $OUTPUT
		PCT=`expr $PCT + 10`
		copy_test_3 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_4 >> $OUTPUT
		PCT=`expr $PCT + 10`
		copy_test_5 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT
		copy_test_6 >> $OUTPUT
		PCT=`expr $PCT + 10`
		echo $PCT		
		) | dialog --title "Test progress" --gauge "Please wait while test ends..." 20 70 0
		cat $OUTPUT | expand >> $TMPFILE
		dialog --backtitle "Sequential Byte Copy test" --title "Results" --textbox "$TMPFILE" $RHEIGHT $RWIDTH
		;;
	esac
done


#set -x
# if temp files found, delete em
[ -f $OUTPUT ] && rm $OUTPUT
[ -f $TMPFILE ] && rm $TMPFILE
#set +x
exit

