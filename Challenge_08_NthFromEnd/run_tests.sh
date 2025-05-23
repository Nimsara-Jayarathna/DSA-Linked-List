#!/bin/bash
gcc Challenge_08_NthFromEnd.c -o program
echo "Running Challenge_08_NthFromEnd Tests..."

for i in 1; do
    ./program < input$i.txt > out.txt
    echo "Test $i:"
    diff out.txt expected$i.txt && echo "✅ Passed" || echo "❌ Failed"
    echo ""
done

for i in hidden1 hidden2 hidden3; do
    ./program < $i.txt > out.txt
    echo "Hidden Test $i:"
    diff out.txt expected_$i.txt && echo "✅ Passed" || echo "❌ Failed"
    echo ""
done
