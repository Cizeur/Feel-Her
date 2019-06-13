# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 16:09:15 by cgiron            #+#    #+#              #
#    Updated: 2019/06/13 11:34:59 by yforeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

player1=$1
player2=$2

n_turns=10
map=test_maps/test
visualizer=../filler_visualiser
KEEP_OUTPUT=1
RAND_MAP=1
WATCH_PROMPT=1
RAND_MAP_SIZE="100 100"

# dont touch after this line --------------------------------------------------

p1=0
p2=0
score_p1=0;
score_p2=0;
i=0

if [ $KEEP_OUTPUT -ne 0 -o $RAND_MAP -ne 0 ]; then
	mkdir -p test_outputs
fi

while [ $i -lt $n_turns ]
do
	seed=$RANDOM
	if [ $RAND_MAP -ne 0 ]; then
		test_maps/a.out $RAND_MAP_SIZE > test_outputs/round_"$i"_map
		map=test_outputs/round_"$i"_map
	fi
	echo "round" $((i+1))/$n_turns
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
		if [ $KEEP_OUTPUT -ne 0 ]; then
			./filler_vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2 \
				&> test_outputs/round_"$i"_output_"$j"
		else
			./filler_vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2 -q &> /dev/null
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
			cat test_outputs/round_"$i"_output_1 | $visualizer &
			cat test_outputs/round_"$i"_output_2 | $visualizer &
		fi
	fi
	echo
	((i++))
done

echo "final score:"
echo "$player1 (p1): $p1"
echo "$player2 (p2): $p2"
