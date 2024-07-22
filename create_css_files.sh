#!/bin/bash

while IFS=" " read -ra args; do
    path="${args[0]}"
    mkdir -p "$path"
    cd "$path"
    for ((i = 1; i < ${#args[@]}; i++)); do
        # mkdir -p "${args[@]:1:i}"
        touch "${args[$i]}.css"
        cd ../
    done
    # cd "$path"
done
