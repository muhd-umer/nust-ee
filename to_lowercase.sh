#!/bin/bash
# Rename all directories. This will need to be done first.
# Process each directorys contents before the directory itself
find * -depth -type d | while read x
do
        # Translate Caps to Small letters
        y=$(echo "$x" | tr '[A-Z ]' '[a-z_]');

        # create directory if it does not exit
        if [ ! -d "$y" ]; then
                mkdir -p "$y";
        fi

        # check if the source and destination is the same
        if [ "$x" != "$y" ]; then

                # move directory files before deleting
                ls -A "$x" | while read i
                do
                  mv "$x"/"$i" "$y";
                done
                rmdir "$x";

        fi

done

# Rename all files
find * -type f | while read x ;
do
        # Translate Caps to Small letters
        y=$(echo "$x" | tr '[A-Z ]' '[a-z_]');
        if [ "$x" != "$y" ]; then
                mv "$x" "$y";
        fi
done

exit 0