#FT_NBR1='\'\''?"\"'\''\'
#FT_NBR2=rcrdmddd
#FT_NBR1='\"\"!\"\"!\"\"!\"\"!\"\"!\"\"'
#FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
base1=''\''\\"?!'
base2='mrdoc'
n1=$(echo ${FT_NBR1} | tr "${base1}" '01234')
n2=$(echo ${FT_NBR2} | tr "${base2}" '01234')
sum=$(echo "obase=13;ibase=5;$n1+$n2" |bc)
echo ${sum} | tr '0123456789ABC' 'gtaio luSnemf'