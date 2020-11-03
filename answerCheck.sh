#!/bin/bash
input="./answers.txt"
while IFS= read -r line
do
  sleep 2
  echo "$line"
done < "$input"
