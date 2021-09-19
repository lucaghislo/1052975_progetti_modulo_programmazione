# Calcolatrice in Python
 
# import della libreria per design GUI
from tkinter import *
from tkinter.font import BOLD
 
# variabile globale che rappresenta l'espressione numerica
expression = ""
 
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
 
 
# main
if __name__ == "__main__":
    # creazione finestra
    gui = Tk()
 
    # setting del colore di sfondo
    gui.configure(background="gray33")
 
    # setting del titolo della finestra
    gui.title("Calcolatrice")
 
    # configurazione delle dimensioni
    gui.geometry("445x450")
    gui.resizable(False, False) # dimensioni fissate
 
    # creazione di operazione ed equazione come istanze della 
    # classe StringVar()
    equation = StringVar()
    operation = StringVar()
 
    # definizione del font
    myfont = ('Consolas', 18, BOLD)

    # definizione proprietà dei pulsanti
    bg_number = "gray77" # sfondo pulsante numerico
    bg_operator = "lawn green" # sfondo pulsante operatore
    text_clr = "black" # colore testo
    button_height = 1 # altezza pulsante
    button_width = 5 # larghezza pulsante
    internal_pad = 2 # padding interno
    out_y_pad = 10 # padding esterno

    # creazione delle Entry testuali
    expression_field = Entry(gui, textvariable = equation, font = myfont)
    operation_field = Entry(gui, textvariable = operation, font = myfont, width=22)

    # definizione delle proprietà delle Entry testuali
    expression_field.grid(columnspan=4, ipadx=80, ipady=5, row = 1, padx=10, pady=10)
    operation_field.grid(columnspan=3, row = 3, padx=10, pady=10)
 
    # definizione dei pulsanti e delle loro proprietà
    # specifica della posizione del pulsante sulla griglia
    button_7 = Button(gui, text=' 7 ', fg=text_clr, bg=bg_number, command=lambda: press(7), height = button_height, width = button_width, font = myfont)
    button_7.grid(row=4, column=0, ipady = internal_pad, pady = out_y_pad)
 
    button_8 = Button(gui, text=' 8 ', fg=text_clr, bg=bg_number, command=lambda: press(8), height = button_height, width = button_width, font = myfont)
    button_8.grid(row=4, column=1, ipady = internal_pad, pady = out_y_pad)
 
    button_9 = Button(gui, text=' 9 ', fg=text_clr, bg=bg_number, command=lambda: press(9), height = button_height, width = button_width, font = myfont)
    button_9.grid(row=4, column=2, ipady = internal_pad, pady = out_y_pad)
 
    button_4 = Button(gui, text=' 4 ', fg='black', bg=bg_number, command=lambda: press(4), height = button_height, width = button_width, font = myfont)
    button_4.grid(row=5, column=0, ipady = internal_pad, pady = out_y_pad)
 
    button_5 = Button(gui, text=' 5 ', fg='black', bg=bg_number, command=lambda: press(5), height = button_height, width = button_width, font = myfont)
    button_5.grid(row=5, column=1, ipady = internal_pad, pady = out_y_pad)
 
    button_6 = Button(gui, text=' 6 ', fg='black', bg=bg_number, command=lambda: press(6), height = button_height, width = button_width, font = myfont)
    button_6.grid(row=5, column=2, ipady = internal_pad, pady = out_y_pad)
 
    button_1 = Button(gui, text=' 1 ', fg='black', bg=bg_number, command=lambda: press(1), height = button_height, width = button_width, font = myfont)
    button_1.grid(row=6, column=0, ipady = internal_pad, pady = out_y_pad)
 
    button_2 = Button(gui, text=' 2 ', fg='black', bg=bg_number,  command=lambda: press(2), height = button_height, width = button_width, font = myfont)
    button_2.grid(row=6, column=1, ipady = internal_pad, pady = out_y_pad)
 
    button3 = Button(gui, text=' 3 ', fg='black', bg=bg_number, command=lambda: press(3), height = button_height, width = button_width, font = myfont)
    button3.grid(row=6, column=2, ipady = internal_pad, pady = out_y_pad)
 
    button_0 = Button(gui, text=' 0 ', fg='black', bg=bg_number, command=lambda: press(0), height = button_height, width = button_width, font = myfont)
    button_0.grid(row=7, column=0, ipady = internal_pad, pady = out_y_pad)
 
    piu = Button(gui, text=' + ',  fg=text_clr, bg=bg_operator, command=lambda: press("+"), height = button_height, width = button_width, font = myfont, relief="ridge", borderwidth=3)
    piu.grid(row=7, column=3, ipady = internal_pad, pady = out_y_pad)
 
    meno = Button(gui, text=' - ', fg=text_clr, bg=bg_operator, command=lambda: press("-"), height = button_height, width = button_width, font = myfont, relief="ridge", borderwidth=3)
    meno.grid(row=6, column=3, ipady = internal_pad, pady = out_y_pad)
 
    per = Button(gui, text=' * ', fg=text_clr, bg=bg_operator, command=lambda: press("*"), height = button_height, width = button_width, font = myfont, relief="ridge", borderwidth=3)
    per.grid(row=5, column=3, ipady = internal_pad, pady = out_y_pad)
 
    diviso = Button(gui, text=' / ', fg=text_clr, bg=bg_operator, command=lambda: press("/"), height = button_height, width = button_width, font = myfont, relief="ridge", borderwidth=3)
    diviso.grid(row=4, column=3, ipady = internal_pad, pady = out_y_pad)
 
    uguale = Button(gui, text=' = ', fg=text_clr, bg="light sky blue",  command=equalpress, height = button_height, width = button_width, font = myfont, relief="solid", borderwidth=5)
    uguale.grid(row=7, column=2, ipady = internal_pad, pady = out_y_pad)
 
    clear = Button(gui, text='AC', fg=text_clr, bg="tomato", command=clear, height = button_height, width = button_width, font = myfont, relief="solid", borderwidth=5)
    clear.grid(row=3, column=3, ipady = internal_pad, pady = out_y_pad, columnspan = 2)
 
    punto = Button(gui, text='.', fg=text_clr, bg="PaleGreen1", command=lambda: press('.'), height = button_height, width = button_width, font = myfont)
    punto.grid(row=7, column=1, ipady = internal_pad, pady = out_y_pad)

    # avvio interfaccia grafica
    gui.mainloop()