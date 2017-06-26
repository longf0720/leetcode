tr ' ' '\n' < words.txt | sort | uniq  -c | sort -r | awk '$2!="" {print $2,$1}'
