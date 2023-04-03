#!/bin/bash

# Remove veth interfaces and delete network namespaces
sudo ip netns delete red
sudo ip netns delete blue
