/*
 ============================================================================
 Name        : Stoplight.asm
 Folder      : specifiche
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Piccola implementazione di una Abstract State Machine
               che simula un semaforo.
               
               Il semaforo è rappresentato tra 3 colori:
              
               - VERDE: permette il passaggio delle auto 
                        (durata 20 secondi)
               - ARANCIONE: avvisa dell'arrivo del rosso (durata
                            5 secondi)
               - ROSSO: impedisce il passaggio (durata 10 secondi)
  
               All'avvio il semaforo si trova in uno qualsiasi dei 3 colori 
               (il colore all'avvio non è rilevante per il corretto 
               funzionamento del semaforo).
 
               L'aspetto critico è rappresentanto dalla sequenza temporale 
               con cui i colori si presentano: 
               
               ROSSO -> VERDE -> ARANCIONE -> ROSSO
 ============================================================================
 */
 
asm Stoplight
import StandardLibrary

/*
 * Dichiarazione universi e funzioni
 */
signature:

	/*
	 * Dichiarazione domini (enum)
	 */
	enum domain Colore = { VERDE | ARANCIONE | ROSSO } // dominio colore semaforo
	domain Seconds subsetof Integer // dominio tempo (secondi)
	
	/*
	 * Domini e funzioni controlled (leggibili e scrivibili)
	 */
	dynamic controlled stoplightColor: Colore // colore assunto dal semaforo
	dynamic controlled time: Seconds // tempo
	dynamic controlled action : String // azione implementata
	
	/*
	 * Funzioni derivate
	 */
	derived f_colorDuration: Colore -> Seconds // ritorna la durata massima di ciascun colore
	derived f_nextColor: Colore -> Colore // ritorna il successivo colore dato il colore attuale
	
	
/*
 * Definizione delle funzioni, delle regole, macro regole e dalla regola main.
 */
definitions:
	
	/*
	 * Funzione che ritorna la durata massima associata a ciascun colore del semaforo
	 */
	function f_colorDuration($colore in Colore) =
		if ($colore = VERDE) then 20
		else if ($colore = ARANCIONE) then 5
		else 10 endif endif
	
	/*
	 * Funzione che ritorna il successivo colore dato il colore attualmente mostrato
	 * dal semaforo
	 */
	function f_nextColor($coloreAttuale in Colore) = 
		if ($coloreAttuale = VERDE) then ARANCIONE
		else if ($coloreAttuale = ARANCIONE) then ROSSO
		else VERDE endif endif
	
	/*
	 * Regola per impostare il successivo stato, impostando il prossimo colore
	 * ottenuto tramite funzione f_nextColor() ed impostando il timer alla durata del 
	 * successivo colore tramite funzione f_colorDuration()
	 */
	rule r_cambioColore = 
		par
			time := f_colorDuration( f_nextColor(stoplightColor) )
			stoplightColor := f_nextColor(stoplightColor)
			action := "change_next_color"
		endpar
		
	/*
	 * Macro-regola che effettua il decremento del tempo ed invoca la regola
	 * di cambio colore nel caso in cui il timer associato all'attuale colore
	 * sia divenuto 0 (cambio colore necessario)
	 */
	macro rule r_decrementaUnSecondo =
		if (time > 0) then
			par
				time := time - 1
				action := "decremento_unsecondo"
			endpar
		else r_cambioColore[] 
		endif
		
	/*
	 * Macro-regola che effettua l'inizializzazione del semaforo con un colore
	 * random nel caso in cui il tempo sia impostato a -1, con il quale si indica
	 * che il semaforo è non funzionante
	 */	
	macro rule r_stoplightInitialize =
		par
			// Solo la prima volta sceglie a random uno dei tre colori dell'enum Colore
		if (time = -1) then
				choose $colore in Colore with true do
				time := f_colorDuration($colore)
			endif
			
			// Decrementa i secondi
			r_decrementaUnSecondo[] 
		endpar
		
	/*
	 * Definizione della regola main con la quale il semaforo viene attivato ed 
	 * inizializzato
	 */
	main rule r_Main = r_stoplightInitialize[]

	/*
	 * Definizione dei valori di inizializzazione
	 * 
	 * Tempo impostato a -1 implica semaforo non attivo
	 */
	default init initialize:
	
		function time = -1