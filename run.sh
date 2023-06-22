#!/bin/bash
make
./server &      # Run the server in the background
sleep 1         # Wait for the server to start
SERVER_PID=$!   # Get the PID of the server process
osascript -e "tell application \"Terminal\" to do script \"cd /Users/mkaruvan/Desktop/minitalk/ && ./client $SERVER_PID 'Your message here'; sleep 10; exit\""
sleep 10        # Wait for the client to finish
osascript -e 'tell application "Terminal" to quit first window without saving'
kill $SERVER_PID # Kill the server