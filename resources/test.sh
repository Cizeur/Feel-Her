# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 16:09:15 by cgiron            #+#    #+#              #
#    Updated: 2019/06/18 08:11:13 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

########################## Variables initialization ############################

player1=""
player2=""
n_turns=10
map=test_maps/test
visualizer=../filler_visualiser
KEEP_OUTPUT=1
RAND_MAP=1
WATCH_PROMPT=1
RAND_MAP_SIZE="50 45"
p1=0
p2=0
score_p1=0;
score_p2=0;
i=0

################################ Functions #####################################

function usage
{
	printf "usage: test.sh p1 p2 [-n turns] [-m map] [-s width height] [-rkhb]\n\n"
	printf "	-h | --help:	Print this.\n"
	printf "	-n | --turns:	Number of turns.\n"
	printf "	-m | --map:	Give a map to 'test.sh'.\n"
	printf "	-s | --size:	Size of the map to generate if it applies.\n"
	printf "	-r | --random:	Generate a random map for each turn.\n"
	printf "			It also keeps them in the test_outputs\n"
	printf "			directory. This option supersedes the\n"
	printf "			given map, if any.\n"
	printf "	-k | --keep:	Keep output in test_outputs.\n"
	printf "	-b | --blind:	Do not prompt for visualisation.\n"
}

############################# Options parser ###################################


while [ "$1" != "" ]
do
	OPT=$1
	case $OPT in
		-h | --help )
			usage
			exit 0
			;;
		-n | --turns )
			shift
			n_turns=$1
			;;
		-m | --map )
			shift
			map=$1
			;;
		-s | --size )
			shift
			RAND_MAP=1
			RAND_MAP_SIZE="$1 $2"
			shift
			;;
		-r | --random )
			RAND_MAP=1
			;;
		-k | --keep )
			KEEP_OUTPUT=1
			;;
		-b | --blind )
			WATCH_PROMPT=0
			;;
		* )
			if [ "$player1" == "" ]; then
				player1=$1
			elif [ "$player2" == "" ]; then
				player2=$1
			fi
			;;
	esac
	shift
done

if [ "$player1" == "" -o "$player2" == "" ]; then
	echo "Error: not enough players"
	exit 1
fi

################################ Main loop #####################################

mkdir -p test_outputs

while [ $i -lt $n_turns ]
do
	if [ $((i+1)) -lt 10 ]; then
		istr="0$((i+1))"
	else
		istr="$((i+1))"
	fi
	seed=$(($RANDOM%10000))
	if [ $RAND_MAP -ne 0 ]; then
		test_maps/map_gen $RAND_MAP_SIZE > test_outputs/round_"$istr"_map
		map=test_outputs/round_"$istr"_map
	fi
	echo "round" $istr/$n_turns "- seed:" $seed
	total=0
	for j in 1 2
	do
		if [ $j -eq 1 ]; then
			echo "turn a:"
			pstr1=$player1
			pstr2=$player2
		else
			echo "turn b:"
			pstr1=$player2
			pstr2=$player1
		fi
		if [ $j -eq 1 ]; then
			./filler_vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2\
				 &> test_outputs/round_"$istr"_output_a
		else
			(echo '$$$ invert' && ./filler_vm -s $seed -f $map -p1 $pstr1\
				 -p2 $pstr2) &> test_outputs/round_"$istr"_output_b
		fi
		result=$(cat filler.trace | grep AGAINST | sed -e 's/AGAINST/ /g')
		if [ $j -eq 1 ]; then
			score_p1=$(echo $result | cut -d\  -f1)
			score_p2=$(echo $result | cut -d\  -f2)
		else
			score_p2=$(echo $result | cut -d\  -f1)
			score_p1=$(echo $result | cut -d\  -f2)
		fi
		echo "p1: $score_p1"
		echo "p2: $score_p2"
		if [ $score_p1 -gt $score_p2 ]; then
			((p1++))
			((total++))
		elif [ $score_p2 -gt $score_p1 ]; then
			((p2++))
			((total--))
		fi
	done
	if [ $total -eq 2 ]; then
		echo "\033[0;32m$player1 (p1) won the round !\033[0m"
	elif [ $total -eq -2 ]; then
		echo "\033[0;31m$player2 (p2) won the round !\033[0m"
	else
		echo "no clear winer..."
	fi
	if [ $WATCH_PROMPT -ne 0 ]; then
		read -p "watch round ? (y/n) " answer
		if [ "$answer" == "y" -o "$answer" == "Y" ]; then
			cat test_outputs/round_"$istr"_output_a | $visualizer &
			cat test_outputs/round_"$istr"_output_b | $visualizer 
		fi
	fi
	if [ $KEEP_OUTPUT -eq 0 ]; then
		rm test_outputs/round_"$istr"_output_a
		rm test_outputs/round_"$istr"_output_b
	fi
	echo
	((i++))
done

echo "final score:"
echo "$player1 (p1): $p1"
echo "$player2 (p2): $p2"
