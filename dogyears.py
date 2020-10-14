from tkinter import *

def dog_years():
	"""
	Return an age in dog years.
	"""
	global answer #bad form, but needs to be done

	age = int(number1.get())

	# clear any previous answers
	answer.delete(0, END)

	if age <= 1:
		answer.insert(0, str(15))
	elif age == 2:
		answer.insert(0, str(24))
	else:
		answer.insert(0, str(24 + ((age - 2) * 5)))

# create the basic window
base = Tk()

# set the window title
base.title("How old is Mari really?")

# set window size Width X Height
base.geometry("300x200")

# create first text label
Label(base, text="Dog years").pack()

# create a text entry field
number1 = Entry(base)
number1.pack()

# create second text label
Label(base, text="Human years").pack()

# create answer field
answer = Entry(base)
answer.pack()

# add button
Button(base, text="Convert!", command=dog_years).pack()
base.mainloop()