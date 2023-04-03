if (($# != 1))
then
  exit
fi

if [[ $1 == "red" ]]
then 
  COLOR=31
elif [[ $1 == "blue" ]]; then
  COLOR=34
fi
clear
NEWPS1='${PS1/32/'$COLOR'}'
echo "Please type the following command in the terminal to help see in which network space you are in"
echo "PS1=$NEWPS1"
sudo ip netns exec $1 bash -c "su $USER"

