echo "Running unit tests:"

for i in tests/*_tests
do
  if test -f $i
  then
    if $VALGRIND ./$i 2>> tests/tests.log
    # VALGRIND is tool for memory leak detection
    then
      echo $i PASS
    else
      echo "ERROR in $i see tests/tests.log"
      echo "-----"
      tail tests/tests.log
      exit 1
    fi
  fi
done

echo ""

