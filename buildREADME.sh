!#/bin/bash

set -x

to_lower()
{
    local result=$(echo "$1" | tr '[:upper:]' '[:lower:]')
    echo "$result"
}

swap_char()
{
    local input=$(cat)
    local result=$(echo "$input" | tr "$1" "$2")
    echo "$result"
}

build_reference()
{
    local reference=$(to_lower "$1" | swap_char ' ' '-')
    local numberOfOccurences=$(grep -E "\(\#$reference\)|\(\#$reference-[0-9]+\)" "$outputFile" | wc -l)
    if [ $numberOfOccurences -ne 0 ]; then
        echo "$reference-$numberOfOccurences"
    else
        echo "$reference"
    fi
}

# 1 is number, 2 is file
build_indice_line()
{
    local result=""
    local i=$1
    while [ $i -gt 0 ]; do
        result+="\t"
        i=$(($i - 1))
    done
    result+="- ["$2"](#$(build_reference "$2"))"
    echo "$result"
}

indice_recursive()
{
    local insertPath="../"
    for entry in *
    do
        if [ -d "$entry" ]; then
            echo -e $(build_indice_line $depth "$entry") >> "$outputFile"
            cd "$entry"
            depth=$(($depth + 1))
            outputFile="$insertPath$outputFile"
            indice_recursive
            depth=$(($depth - 1))
            cd ".."
            outputFile=$(echo "$outputFile" | cut --complement -d "/" -f 1)
        fi
    done
}

build_list_title()
{
    local result="##"
    local i=$1
    while [ $i -gt 0 ]; do
        result+="#"
        i=$(($i - 1))
    done
    result+=" $2"
    echo "$result"
}

build_list_item()
{
    local filename=$(echo "$1" | cut -d "." -f 3 --complement)
    local newFilePath=$(echo "$filepath$1" | sed 's/ /%20/g')
    result="- ["$filename"]($newFilePath)"
    echo "$result"
}

list_recursive()
{
    local insertPath="../"
    for entry in *
    do
        if [ -d "$entry" ]; then
            echo -e $(build_list_title $depth "$entry") >> "$outputFile"
            cd "$entry"
            depth=$(($depth + 1))
            outputFile="$insertPath$outputFile"
            filepath="$filepath$entry/"
            list_recursive
            cd ".."
            depth=$(($depth - 1))
            outputFile=$(echo "$outputFile" | cut --complement -d "/" -f 1)
            local len=$(( $(echo "$filepath" | tr '/' '\n' | wc -l) - 1 ))
            filepath=$(echo "$filepath" | cut --complement -d "/" -f $len)
        elif [ -f "$entry" ]; then
            local fileType=$(echo "$entry" | cut -d "." -f 3)
            if [[ "cpp" == $fileType ]]; then
                echo $(build_list_item "$entry") >> "$outputFile"
            fi
        fi
    done
    echo "" >> "$outputFile"
}

# VARIABLES

if [ ! $# -eq 0 ]
    then
        outputFile="$1"
else
    outputFile="README.md"
fi

name="Leetcode Exercises"
depth=0
filepath="/"

if [ ! -f "$outputFile" ]; then
    touch "$outputFile"
fi

echo "# $name

## Indice
" > "$outputFile"

indice_recursive

echo "" >> "$outputFile"

depth=0

list_recursive