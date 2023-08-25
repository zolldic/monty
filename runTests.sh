for i in alx_test_suite/monty_project/task_$1/*;
do
	echo "cat $i"
	echo "-------------------------------"
	$i
	echo ""
	echo ""
done
