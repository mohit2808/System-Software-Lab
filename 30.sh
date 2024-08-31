cd ~; 
echo "modifications done here" > running.txt
if [ $# -eq 1 ]
then
    echo "After some time this was created" > once.txt
fi