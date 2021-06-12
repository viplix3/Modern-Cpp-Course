echo "Number of lines"
wc -l data.dat

echo "Number of line containing dolor or dalor"
grep -ci "dolor\|dalor" data.dat

echo "Number of words"
wc -w data.dat

echo "Number of words starting with mol"
grep -c -e "mol." data.dat