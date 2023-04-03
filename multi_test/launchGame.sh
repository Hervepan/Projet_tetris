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
echo "To launch the game go into projectC++ and type the command :"
if [[ $1 == "red" ]]; then
  echo '    make run ARGS="server"' 
elif [[ $1 == "blue" ]]; then
  echo 'make run ARGS="client 192.168.15.1"'
fi
sudo ip netns exec $1 bash -c "su $USER"

