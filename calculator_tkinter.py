from tkinter import *

# settings window
win = Tk()
win.geometry('412x294')
win.resizable(0,0)
win.title('Calculator by Nagachi')

def btn_click(item):
    """Update input from clicked button
    
    args:
        item : button
    
    return :
        add expression to input_text
    """
    global expression
    expression = expression + item
    input_text.set(expression)

def btn_clear():
    """
    Clear calculator inpur
    return:
        empty string to input_text
    """
    global expression
    expression = ""
    input_text.set("")

def btn_equal():
    """
    Eval string and doing calculations
    return:
        evaluate calculations
    """
    global expression
    result = str(eval(expression))
    input_text.set(result)
    expression = ""

expression = ""

input_text = StringVar() #input field
input_frame = Frame(win, #creating frame for the input field
            width=312, height=50, bd=0, 
            highlightbackground='black',
            highlightcolor='black',
            highlightthickness=2)
input_frame.pack(side=TOP)

input_field = Entry(input_frame, #create input field
            font=('arial', 18, 'bold'),
            textvariable=input_text,
            width=50, bg='#eee',
            bd=0, justify=RIGHT)
input_field.grid(row=0, column=0)
input_field.pack(ipady=10) #ipady is internal padding to increase height

#creating frame for button
btns_frame = Frame(win, width=312, height=272.5, bg='grey')
btns_frame.pack()

#button clear
clear = Button(btns_frame, text='Clear', 
            fg='#eee', width=38,
            height=3, bd=0, bg='#bd0d39',
            cursor='hand2',
            command=lambda: btn_clear()
            ).grid(row=0, column=0, columnspan=3, padx=1, pady=1)

#button division
divide = Button(btns_frame, text='/', 
            fg='black', width=10,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda: btn_click('/')
            ).grid(row=0, column=3, padx=1, pady=1)

#button multiply
multiply = Button(btns_frame, text='*', 
            fg='black', width=10,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda: btn_click('*')
            ).grid(row=1, column=3, padx=1, pady=1)

#button minus
minus = Button(btns_frame, text='-', 
            fg='black', width=10,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda: btn_click('-')
            ).grid(row=2, column=3, padx=1, pady=1)

#button plus
plus = Button(btns_frame, text='+', 
            fg='black', width=10,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda: btn_click('+')
            ).grid(row=3, column=3, padx=1, pady=1)

#button equal
equal = Button(btns_frame, text='=', 
            fg='black', width=10,
            height=3, bd=0, bg='#80d177',
            cursor='hand2',
            command=lambda: btn_equal()
            ).grid(row=4, column=3, padx=1, pady=1)

#button comma
comma = Button(btns_frame, text='.', 
            fg='black', width=10,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda: btn_click('.')
            ).grid(row=4, column=2, padx=1, pady=1)

#button zero
zero = Button(btns_frame, text='0', 
            fg='black', width=24,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda: btn_click('0')
            ).grid(row=4, column=0, columnspan=2, padx=1, pady=1)

#Number button (1-9)
num = iter(range(9,0,-1))
for i in range(1,4):
    for j in range(2,-1,-1):
        num_pad = str(next(num))
        Button(btns_frame, text=num_pad, 
            fg='black', width=10,
            height=3, bd=0, bg='#eee',
            cursor='hand2',
            command=lambda num_pad=num_pad: btn_click(num_pad)
            ).grid(row=i, column=j, padx=1, pady=1)

win.mainloop()