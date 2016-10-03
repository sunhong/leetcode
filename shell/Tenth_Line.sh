num=$(cat file.txt | wc -l)
if [ $num -lt 10 ]
then
  echo ""
else
  line=$(sed -n 10p file.txt)
  echo $line
fi