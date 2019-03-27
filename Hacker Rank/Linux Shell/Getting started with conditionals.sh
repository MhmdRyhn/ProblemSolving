

read x

# Notice the quote ("") around $x and == operator
if [ "$x" == "y" ] || [ "$x" == "Y" ]; then
  echo "YES"
else
  echo "NO"
fi

