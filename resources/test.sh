# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 16:09:15 by cgiron            #+#    #+#              #
#    Updated: 2019/06/11 08:04:56 by yforeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

player1=$1
player2=$2

n_turns=10
map=test

# dont touch after this line --------------------------------------------------

p1=0
p2=2
score_p1=0;
score_p2=0;
i=0

while [ $i -lt $n_turns ]
do
	./filler_vm -f ./test_maps/$map -p1 $player1 -p2 $player2 -q &> /dev/null
	echo "round" $((i+1))/$n_turns
	result=$(cat filler.trace | grep AGAINST | sed -e 's/AGAINST/ /g')
	score_p1=$(echo $result | cut -d\  -f1)
	score_p2=$(echo $result | cut -d\  -f2)
	echo "p1: $score_p1"
	echo "p2: $score_p2"
	if [ $score_p1 -gt $score_p2 ]; then
		((p1++))
	elif [ $score_p2 -gt $score_p1 ]; then
		((p2++))
	fi
	((i++))
done

echo "\nfinal score:"
echo "$player1 (p1): $p1"
echo "$player2 (p2): $p2"
