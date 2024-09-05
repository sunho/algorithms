mv *.cpp old
mv *.rs old
mv *.py old
cp compile_flags.txt /tmp
rm *.txt
cp /tmp/compile_flags.txt .
rm -rf *.dSYM
rm -rf *_stress
