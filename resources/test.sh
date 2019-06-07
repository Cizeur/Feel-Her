# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 16:09:15 by cgiron            #+#    #+#              #
#    Updated: 2019/06/07 16:47:05 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player1=$1
player2=$2

n_turns=10
map=test

# dont touch after this line --------------------------------------------------

p1=0;
p2=0;

while [ $n_turns != 0 ]
do
	./filler_vm -f ./test_maps/$map -p1 \
		$player1 -p2 \
		$player2 -q > Fuck_you
	result=$(cat filler.trace | grep won)
	echo "round" $n_turns
	cat filler.trace | grep AGAINST | tr '\n' ' '\
		| sed -e 's/[^0-9]/ /g' -e 's/^ *//g' -e 's/ *$//g'\
		| tr -s ' ' | tr ' ' '\n'
	if echo "$result" | grep -q "$player1"
	then
		((p1++))
	else
		((p2++))
	fi
	((n_turns--))
done

echo $player1
echo $p1
echo $player2
echo $p2
