#!/bin/bash
echo "Welcome To Shell Programming"
echo "1.Edit"
echo "2.Complie"
echo "3.Execute"
echo "Enter an option you would like to operate:"
read n
case n in
	"1") echo "1.Printing your name and enrollment number."
	     echo "2.Finding the average of four numbers."
	     echo "3.Swapping the two numbers."
	     echo "4.Concatinating two strings."
	     echo "5.Basic operations on numbers."
	     echo "6.Print date after a sleep of 5"
	     echo "7.To find sum ofall digits."
	     echo "8.Reverse a number."
	     echo "9.Factorial of a number"
	     echo "10.Area and perimeter of a rectangle and area and circumfrence of a circle."
	     echo "11.Multiplication table"
	     echo "Enter a number to edit the repective code"
	     read a
	     case a in 
	     	     "1") echo "Enter your name"
				read name
				echo "Enter your roll number"
				read rno
				echo "Your name is: $name"
				echo "Your Roll Number is: $rno"
		esac
esac
	
	     	
