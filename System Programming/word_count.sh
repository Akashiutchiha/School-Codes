#!/bin/bash

echo "Enter the name of the file: "
read filename

if [ -f "$filename" ]; then
    echo "File already exists."
else
    echo "Enter some text: "
    read text
    echo "$text" > "$filename"
    echo "File $filename created and text written."
fi

word_count=$(wc -w "$filename" | awk '{print $1}')
echo "Word count of file $filename: $word_count"