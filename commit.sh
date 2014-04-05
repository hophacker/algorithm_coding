#!/bin/bash
read -p "Please provide the message of this commit:" message
git commit -a -m $message
~/generated/push.sh
