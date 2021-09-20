# Calcolatrice in Python

# import della libreria per design GUI
from tkinter import *
from tkinter.font import BOLD
from tkinter.ttk import Combobox
from tkinter import messagebox

# variabile globale che rappresenta l'espressione numerica
expression = ""
equation = ""

# funzione per l'update dell'espressione sulla base della pressione
# dei pulsanti (sia numerici che operazionali)
def press(num):
    # riferimento alla variabile globale che rappresenta l'espressione
    global expression

    # concatenazione della stringa con il nuovo simbolo digitato
    expression = expression + str(num)

    # update dell'equazione sulla base della nuova configurazione delle'espressione numerica
    equation.set(expression)


# funzione per il calcolo del risultato chiamata alla pressione del pulsante "="
def equalpress():

    # utilizzo blocco try-catch per intercettare eccezioni nella valutazione dell'equazione
    try:
        # riferimento alle variabili globali
        global expression

        # calcolo continuo: nel caso venga specificato come primo carattere della sequenza un operatore,
        # si considera come primo membro dell'operazione il risultato precedentemente ottenuto
        if (
            expression[0] == "*"
            or expression[0] == "/"
            or expression[0] == "+"
            or expression[0] == "-"
        ) and operation_field.get() != "":
            expression = operation_field.get() + expression
            equation.set(expression)

        # valutazione dell'espressione (calcolo dell'operazione)
        total = str(eval(expression))
        operation.set(total)

        # svuoto l'espressione per consentire nuovo inserimento
        expression = ""

    # nel caso di errore, eccezione intercettata nel blocco catch
    except:
        equation.set(" error ")
        expression = ""


# funzione per la rimozione del contenuto del box espressione e risultato
def clear():
    global expression
    expression = ""
    equation.set("")
    operation.set("")


# funzione per la rimozione del contenuto dei campi associati al convertitore
def erase_input_conv():
    conv_input.set("")
    combo_to.current(1)
    combo_from.current(0)
    conv_output.set("")


# funzione di verifica generica dell'input (verifica assenza lettere)
def check_input():
    for c in input_conv.get():
        if c.isalpha():
            messagebox.showerror(title="Errore", message="Errore formato input")
            erase_input_conv()
            break


# funzione di veririca dell'input per input ottale
def check_input_octal():
    for c in input_conv.get():
        if int(c) < 0 or int(c) > 7:
            messagebox.showerror(title="Errore", message="Errore formato input ottale")
            erase_input_conv()
            break


# funzione di veririca dell'input per input binario
def check_input_binary():
    for c in input_conv.get():
        if int(c) < 0 or int(c) > 1:
            messagebox.showerror(title="Errore", message="Errore formato input binario")
            erase_input_conv()
            break


# funzione di veririca dell'input per input esadecimale
def check_input_hex():
    for c in input_conv.get():
        if (
            not (
                c.isalpha()
                and (ord(c) >= 97 and ord(c) <= 102)
                or (ord(c) >= 65 and ord(c) <= 70)
            )
            and c.isalpha()
        ):
            messagebox.showerror(
                title="Errore", message="Errore formato input esadecimale"
            )
            erase_input_conv()
            break


# funzione di conversione
def convert():
    # conversione da decimale
    if combo_from.get() == "Decimale":
        check_input()
        if combo_to.get() == "Binario":
            conv_output.set(bin(int(conv_input.get()))[2:])
        elif combo_to.get() == "Ottale":
            conv_output.set(oct(int(conv_input.get()))[2:])
        elif combo_to.get() == "Esadecimale":
            conv_output.set(hex(int(conv_input.get()))[2:])
        else:
            conv_output.set(conv_input.get())

    # conversione da binario
    if combo_from.get() == "Binario":
        check_input()
        check_input_binary()
        if combo_to.get() == "Decimale":
            conv_output.set(int(conv_input.get(), 2))
        elif combo_to.get() == "Ottale":
            conv_output.set(oct(int(conv_input.get(), 2))[2:])
        elif combo_to.get() == "Esadecimale":
            conv_output.set(hex(int(conv_input.get(), 2))[2:])
        else:
            conv_output.set(conv_input.get())

    # conversione da ottale
    if combo_from.get() == "Ottale":
        check_input()
        check_input_octal()
        if combo_to.get() == "Decimale":
            conv_output.set(int(conv_input.get(), 8))
        elif combo_to.get() == "Binario":
            conv_output.set(bin(int(conv_input.get(), 8))[2:])
        elif combo_to.get() == "Esadecimale":
            conv_output.set(hex(int(conv_input.get(), 8))[2:])
        else:
            conv_output.set(conv_input.get())

    # conversione da esadecimale
    if combo_from.get() == "Esadecimale":
        check_input_hex()
        if combo_to.get() == "Decimale":
            conv_output.set(int(conv_input.get(), 16))
        elif combo_to.get() == "Ottale":
            conv_output.set(oct(int(conv_input.get(), 16))[2:])
        elif combo_to.get() == "Binario":
            conv_output.set(bin(int(conv_input.get(), 16))[2:])
        else:
            conv_output.set(conv_input.get())


# main
if __name__ == "__main__":
    # creazione finestra
    gui = Tk()

    # setting del colore di sfondo
    gui.configure(background="gray33")

    # setting del titolo della finestra
    gui.title("Calcolatrice e convertitore di base")

    # configurazione delle dimensioni
    gui.geometry("1045x450")  # larghezza calcolatrice 445
    gui.resizable(False, False)  # dimensioni fissate

    # creazione di operazione ed equazione come istanze della
    # classe StringVar()
    equation = StringVar()
    operation = StringVar()
    conv_input = StringVar()
    conv_output = StringVar()

    # definizione del font
    myfont = ("Consolas", 18, BOLD)

    # definizione proprietà dei pulsanti
    bg_number = "gray77"  # sfondo pulsante numerico
    bg_operator = "lawn green"  # sfondo pulsante operatore
    text_clr = "black"  # colore testo
    button_height = 1  # altezza pulsante
    button_width = 5  # larghezza pulsante
    internal_pad = 2  # padding interno
    out_y_pad = 10  # padding esterno

    # creazione delle Entry testuali
    expression_field = Entry(gui, textvariable=equation, font=myfont, state="readonly")
    operation_field = Entry(
        gui, textvariable=operation, font=myfont, width=22, state="readonly"
    )

    # definizione delle proprietà delle Entry testuali
    expression_field.grid(columnspan=4, ipadx=80, ipady=5, row=1, padx=10, pady=10)
    operation_field.grid(columnspan=3, ipadx=15, ipady=5, row=3, padx=10, pady=10)

    # definizione dei pulsanti e delle loro proprietà
    # specifica della posizione del pulsante sulla griglia
    button_7 = Button(
        gui,
        text=" 7 ",
        fg=text_clr,
        bg=bg_number,
        command=lambda: press(7),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_7.grid(row=4, column=0, ipady=internal_pad, pady=out_y_pad)

    button_8 = Button(
        gui,
        text=" 8 ",
        fg=text_clr,
        bg=bg_number,
        command=lambda: press(8),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_8.grid(row=4, column=1, ipady=internal_pad, pady=out_y_pad)

    button_9 = Button(
        gui,
        text=" 9 ",
        fg=text_clr,
        bg=bg_number,
        command=lambda: press(9),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_9.grid(row=4, column=2, ipady=internal_pad, pady=out_y_pad)

    button_4 = Button(
        gui,
        text=" 4 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(4),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_4.grid(row=5, column=0, ipady=internal_pad, pady=out_y_pad)

    button_5 = Button(
        gui,
        text=" 5 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(5),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_5.grid(row=5, column=1, ipady=internal_pad, pady=out_y_pad)

    button_6 = Button(
        gui,
        text=" 6 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(6),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_6.grid(row=5, column=2, ipady=internal_pad, pady=out_y_pad)

    button_1 = Button(
        gui,
        text=" 1 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(1),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_1.grid(row=6, column=0, ipady=internal_pad, pady=out_y_pad)

    button_2 = Button(
        gui,
        text=" 2 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(2),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_2.grid(row=6, column=1, ipady=internal_pad, pady=out_y_pad)

    button3 = Button(
        gui,
        text=" 3 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(3),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button3.grid(row=6, column=2, ipady=internal_pad, pady=out_y_pad)

    button_0 = Button(
        gui,
        text=" 0 ",
        fg="black",
        bg=bg_number,
        command=lambda: press(0),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    button_0.grid(row=7, column=0, ipady=internal_pad, pady=out_y_pad)

    piu = Button(
        gui,
        text=" + ",
        fg=text_clr,
        bg=bg_operator,
        command=lambda: press("+"),
        height=button_height,
        width=button_width,
        font=myfont,
        relief="ridge",
        borderwidth=3,
    )
    piu.grid(row=7, column=3, ipady=internal_pad, pady=out_y_pad)

    meno = Button(
        gui,
        text=" - ",
        fg=text_clr,
        bg=bg_operator,
        command=lambda: press("-"),
        height=button_height,
        width=button_width,
        font=myfont,
        relief="ridge",
        borderwidth=3,
    )
    meno.grid(row=6, column=3, ipady=internal_pad, pady=out_y_pad)

    per = Button(
        gui,
        text=" * ",
        fg=text_clr,
        bg=bg_operator,
        command=lambda: press("*"),
        height=button_height,
        width=button_width,
        font=myfont,
        relief="ridge",
        borderwidth=3,
    )
    per.grid(row=5, column=3, ipady=internal_pad, pady=out_y_pad)

    diviso = Button(
        gui,
        text=" / ",
        fg=text_clr,
        bg=bg_operator,
        command=lambda: press("/"),
        height=button_height,
        width=button_width,
        font=myfont,
        relief="ridge",
        borderwidth=3,
    )
    diviso.grid(row=4, column=3, ipady=internal_pad, pady=out_y_pad)

    uguale = Button(
        gui,
        text=" = ",
        fg=text_clr,
        bg="light sky blue",
        command=equalpress,
        height=button_height,
        width=button_width,
        font=myfont,
        relief="solid",
        borderwidth=5,
    )
    uguale.grid(row=7, column=2, ipady=internal_pad, pady=out_y_pad)

    clear = Button(
        gui,
        text="AC",
        fg=text_clr,
        bg="tomato",
        command=clear,
        height=button_height,
        width=button_width,
        font=myfont,
        relief="solid",
        borderwidth=5,
    )
    clear.grid(row=3, column=3, ipady=internal_pad, pady=out_y_pad, columnspan=2)

    punto = Button(
        gui,
        text=".",
        fg=text_clr,
        bg="PaleGreen1",
        command=lambda: press("."),
        height=button_height,
        width=button_width,
        font=myfont,
    )
    punto.grid(row=7, column=1, ipady=internal_pad, pady=out_y_pad)

    # definizione del convertitore di base
    label_convertitore = Label(
        gui, text="Convertitore di base", font=myfont, width=30, bg="gray33"
    )
    label_convertitore.grid(row=1, column=6, columnspan=2)

    input_conv = Entry(gui, textvariable=conv_input, font=myfont)
    input_conv.grid(columnspan=3, ipadx=80, ipady=5, row=3, padx=10, pady=10, column=5)

    cancel = Button(
        gui,
        text=" AC ",
        fg=text_clr,
        bg="tomato",
        command=erase_input_conv,
        height=button_height,
        width=button_width,
        font=myfont,
        relief="solid",
        borderwidth=5,
    )
    cancel.grid(row=3, column=8, ipady=internal_pad, pady=out_y_pad)

    label_from = Label(
        gui, text="   From:", height=button_height, width=8, font=myfont, bg="gray33"
    )
    label_from.grid(row=4, column=5, ipady=internal_pad, pady=out_y_pad)

    label_to = Label(
        gui, text="     To:", height=button_height, width=8, font=myfont, bg="gray33"
    )
    label_to.grid(row=5, column=5, ipady=internal_pad, pady=out_y_pad)

    # combobox selezione base input
    combo_from = Combobox(
        gui,
        font=myfont,
        width=30,
        values=["Decimale", "Binario", "Ottale", "Esadecimale"],
        state="readonly",
    )
    combo_from.grid(row=4, column=6, columnspan=3)
    combo_from.current(0)

    # combobox selezione base output
    combo_to = Combobox(
        gui,
        font=myfont,
        width=30,
        values=["Decimale", "Binario", "Ottale", "Esadecimale"],
        state="readonly",
    )
    combo_to.grid(row=5, column=6, columnspan=3)
    combo_to.current(1)

    output_conv = Entry(gui, textvariable=conv_output, font=myfont, state="readonly")
    output_conv.grid(columnspan=3, ipadx=80, ipady=5, row=6, padx=10, pady=10, column=5)

    convert = Button(
        gui,
        text=" GO ",
        fg=text_clr,
        bg="light sky blue",
        command=convert,
        height=button_height,
        width=button_width,
        font=myfont,
        relief="solid",
        borderwidth=5,
    )
    convert.grid(row=6, column=8, ipady=internal_pad, pady=out_y_pad)

    # avvio interfaccia grafica
    gui.mainloop()
